/** @file
  Confidential Computing Secret configuration table constructor

  Copyright (C) 2020 James Bottomley, IBM Corporation.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiDxe.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/Guid/ConfidentialComputingSecret.h"

EFI_STATUS
EFIAPI
InitializeSecretDxe (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS                              Status;
  CONFIDENTIAL_COMPUTING_SECRET_LOCATION  *SecretDxeTable;

  Status = gBS->AllocatePool (
                  EfiACPIReclaimMemory,
                  sizeof (CONFIDENTIAL_COMPUTING_SECRET_LOCATION),
                  (VOID **)&SecretDxeTable
                  );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  SecretDxeTable->Base = FixedPcdGet32 (PcdSevLaunchSecretBase);
  SecretDxeTable->Size = FixedPcdGet32 (PcdSevLaunchSecretSize);

  return gBS->InstallConfigurationTable (
                &gConfidentialComputingSecretGuid,
                SecretDxeTable
                );
}
