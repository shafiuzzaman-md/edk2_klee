/**@file
  Functions related to the Firmware Volume Block service whose
  implementation is specific to the SMM driver build.

  Copyright (C) 2015, Red Hat, Inc.
  Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/SmmServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/BaseTools/Source/C/Include/Protocol/DevicePath.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Protocol/SmmFirmwareVolumeBlock.h"

#include "FwBlockService.h"

VOID
InstallProtocolInterfaces (
  IN EFI_FW_VOL_BLOCK_DEVICE  *FvbDevice
  )
{
  EFI_HANDLE  FvbHandle;
  EFI_STATUS  Status;

  ASSERT (FeaturePcdGet (PcdSmmSmramRequire));

  //
  // There is no SMM service that can install multiple protocols in the SMM
  // protocol database in one go.
  //
  // The SMM Firmware Volume Block protocol structure is the same as the
  // Firmware Volume Block protocol structure.
  //
  FvbHandle = NULL;
  DEBUG ((DEBUG_INFO, "Installing QEMU flash SMM FVB\n"));
  Status = gSmst->SmmInstallProtocolInterface (
                    &FvbHandle,
                    &gEfiSmmFirmwareVolumeBlockProtocolGuid,
                    EFI_NATIVE_INTERFACE,
                    &FvbDevice->FwVolBlockInstance
                    );
  ASSERT_EFI_ERROR (Status);

  Status = gSmst->SmmInstallProtocolInterface (
                    &FvbHandle,
                    &gEfiDevicePathProtocolGuid,
                    EFI_NATIVE_INTERFACE,
                    FvbDevice->DevicePath
                    );
  ASSERT_EFI_ERROR (Status);
}

VOID
InstallVirtualAddressChangeHandler (
  VOID
  )
{
  //
  // Nothing.
  //
}

EFI_STATUS
MarkIoMemoryRangeForRuntimeAccess (
  IN EFI_PHYSICAL_ADDRESS  BaseAddress,
  IN UINTN                 Length
  )
{
  //
  // Nothing
  //

  return EFI_SUCCESS;
}

VOID
SetPcdFlashNvStorageBaseAddresses (
  VOID
  )
{
  //
  // Do nothing.
  //
}
