/** @file

  Driver for the XenIo protocol

  This driver simply allocate space for the grant tables.

  Copyright (c) 2019, Citrix Systems, Inc.

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/Library/XenIoMmioLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/Library/XenPlatformLib.h"

EFI_STATUS
EFIAPI
InitializeXenIoPvhDxe (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  VOID        *Allocation;
  EFI_STATUS  Status;
  EFI_HANDLE  XenIoHandle;

  Allocation  = NULL;
  XenIoHandle = NULL;

  if (!XenPvhDetected ()) {
    return EFI_UNSUPPORTED;
  }

  Allocation = AllocateReservedPages (FixedPcdGet32 (PcdXenGrantFrames));
  if (Allocation == NULL) {
    Status = EFI_OUT_OF_RESOURCES;
    goto Error;
  }

  Status = XenIoMmioInstall (&XenIoHandle, (UINTN)Allocation);
  if (EFI_ERROR (Status)) {
    goto Error;
  }

  return EFI_SUCCESS;

Error:
  if (Allocation != NULL) {
    FreePages (Allocation, FixedPcdGet32 (PcdXenGrantFrames));
  }

  return Status;
}
