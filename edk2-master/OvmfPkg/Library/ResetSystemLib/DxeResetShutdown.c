/** @file
  DXE Reset System Library Shutdown API implementation for OVMF.

  Copyright (C) 2020, Red Hat, Inc.
  Copyright (c) 2006 - 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Base.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/IoLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Library/ResetSystemLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/OvmfPlatforms.h"

STATIC UINT16  mAcpiPmBaseAddress;
STATIC UINT16  mAcpiHwReducedSleepCtl;

EFI_STATUS
EFIAPI
DxeResetInit (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  UINT16  HostBridgeDevId;

  HostBridgeDevId = PcdGet16 (PcdOvmfHostBridgePciDevId);
  switch (HostBridgeDevId) {
    case INTEL_82441_DEVICE_ID:
      mAcpiPmBaseAddress = PIIX4_PMBA_VALUE;
      break;
    case INTEL_Q35_MCH_DEVICE_ID:
      mAcpiPmBaseAddress = ICH9_PMBASE_VALUE;
      break;
    case CLOUDHV_DEVICE_ID:
      mAcpiHwReducedSleepCtl = CLOUDHV_ACPI_SHUTDOWN_IO_ADDRESS;
      break;
    default:
      ASSERT (FALSE);
      CpuDeadLoop ();
      return EFI_UNSUPPORTED;
  }

  return EFI_SUCCESS;
}

/**
  Calling this function causes the system to enter a power state equivalent
  to the ACPI G2/S5 or G3 states.

  System shutdown should not return, if it returns, it means the system does
  not support shut down reset.
**/
VOID
EFIAPI
ResetShutdown (
  VOID
  )
{
  if (mAcpiHwReducedSleepCtl) {
    IoWrite8 (mAcpiHwReducedSleepCtl, 5 << 2 | 1 << 5);
  } else {
    IoBitFieldWrite16 (mAcpiPmBaseAddress + 4, 10, 13, 0);
    IoOr16 (mAcpiPmBaseAddress + 4, BIT13);
  }

  CpuDeadLoop ();
}
