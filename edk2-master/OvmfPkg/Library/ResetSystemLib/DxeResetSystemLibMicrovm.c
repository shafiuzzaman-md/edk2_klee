/** @file
  Reset System Library functions for OVMF

  Copyright (c) 2006 - 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "edk2-master/MdePkg/Include/Base.h"
#include "edk2-master/MdePkg/Include/PiDxe.h"

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/DxeServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/IoLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/ResetSystemLib.h"
#include "edk2-master/MdePkg/Include/Library/TimerLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiRuntimeLib.h"
#include "edk2-master/OvmfPkg/Include/OvmfPlatforms.h"

EFI_STATUS
EFIAPI
DxeResetSystemLibMicrovmConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  UINTN                            Address = MICROVM_GED_MMIO_BASE;
  EFI_STATUS                       Status;
  EFI_GCD_MEMORY_SPACE_DESCRIPTOR  Descriptor;

  DEBUG ((DEBUG_INFO, "%a: start\n", __func__));

  Status = gDS->GetMemorySpaceDescriptor (Address, &Descriptor);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_INFO, "%a: GetMemorySpaceDescriptor failed\n", __func__));
    return RETURN_UNSUPPORTED;
  }

  Status = gDS->SetMemorySpaceAttributes (
                  Address,
                  SIZE_4KB,
                  Descriptor.Attributes | EFI_MEMORY_RUNTIME
                  );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_INFO, "%a: SetMemorySpaceAttributes failed\n", __func__));
    return RETURN_UNSUPPORTED;
  }

  DEBUG ((DEBUG_INFO, "%a: done\n", __func__));
  return EFI_SUCCESS;
}
