/** @file
  Reset System Library functions for OVMF

  Copyright (c) 2006 - 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Base.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/IoLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Library/ResetSystemLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/TimerLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiRuntimeLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/OvmfPlatforms.h"

static UINTN
MicrovmGedBase (
  VOID
  )
{
  VOID  *Address = (VOID *)(UINTN)MICROVM_GED_MMIO_BASE_REGS;

  if (EfiGoneVirtual ()) {
    EfiConvertPointer (0, &Address);
    DEBUG ((DEBUG_INFO, "%a: virtual -> 0x%x\n", __func__, Address));
  } else {
    DEBUG ((DEBUG_INFO, "%a: physical -> 0x%x\n", __func__, Address));
  }

  return (UINTN)Address;
}

static VOID
MicrovmReset (
  VOID
  )
{
  UINTN  Address = MicrovmGedBase ();

  DEBUG ((DEBUG_INFO, "%a: microvm reset via ged\n", __func__));
  MmioWrite8 (
    Address + MICROVM_ACPI_GED_REG_RESET,
    MICROVM_ACPI_GED_RESET_VALUE
    );
  CpuDeadLoop ();
}

static VOID
MicrovmShutdown (
  VOID
  )
{
  UINTN  Address = MicrovmGedBase ();

  DEBUG ((DEBUG_INFO, "%a: microvm poweroff via ged\n", __func__));
  MmioWrite8 (
    Address + MICROVM_ACPI_GED_REG_SLEEP_CTL,
    (1 << 5) /* enable bit */ |
    (5 << 2)           /* typ == S5  */
    );
  CpuDeadLoop ();
}

VOID EFIAPI
ResetCold (
  VOID
  )
{
  MicrovmReset ();
}

VOID EFIAPI
ResetWarm (
  VOID
  )
{
  MicrovmReset ();
}

VOID
EFIAPI
ResetPlatformSpecific (
  IN UINTN  DataSize,
  IN VOID   *ResetData
  )
{
  MicrovmReset ();
}

VOID
EFIAPI
ResetSystem (
  IN EFI_RESET_TYPE  ResetType,
  IN EFI_STATUS      ResetStatus,
  IN UINTN           DataSize,
  IN VOID            *ResetData OPTIONAL
  )
{
  MicrovmReset ();
}

VOID EFIAPI
ResetShutdown (
  VOID
  )
{
  MicrovmShutdown ();
}
