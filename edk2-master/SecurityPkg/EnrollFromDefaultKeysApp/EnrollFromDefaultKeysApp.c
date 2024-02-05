/** @file
  Enroll default PK, KEK, db, dbx.

Copyright (c) 2021, ARM Ltd. All rights reserved.<BR>
Copyright (c) 2021, Semihalf All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "edk2-master/SecurityPkg/Include/Guid/AuthenticatedVariableFormat.h"
#include "edk2-master/MdePkg/Include/Guid/GlobalVariable.h"
#include "edk2-master/MdePkg/Include/Guid/ImageAuthentication.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/PrintLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Uefi/UefiMultiPhase.h"
#include "edk2-master/SecurityPkg/Include/UefiSecureBoot.h"
#include "edk2-master/SecurityPkg/Include/Library/SecureBootVariableLib.h"
#include "edk2-master/SecurityPkg/Include/Library/SecureBootVariableProvisionLib.h"

/**
  Entry point function of this shell application.
  @param[in] ImageHandle    The firmware allocated handle for the EFI image.
  @param[in] SystemTable    A pointer to the EFI System Table.

  @retval 0       The entry point is executed successfully.
  @retval other   Some error occurs when executing this entry point.
**/
EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS  Status;
  UINT8       SetupMode;

  Status = GetSetupMode (&SetupMode);
  if (EFI_ERROR (Status)) {
    AsciiPrint ("EnrollFromDefaultKeysApp: Cannot get SetupMode variable: %r\n", Status);
    return 1;
  }

  if (SetupMode == USER_MODE) {
    AsciiPrint ("EnrollFromDefaultKeysApp: Skipped - USER_MODE\n");
    return 1;
  }

  Status = SetSecureBootMode (CUSTOM_SECURE_BOOT_MODE);
  if (EFI_ERROR (Status)) {
    AsciiPrint ("EnrollFromDefaultKeysApp: Cannot set CUSTOM_SECURE_BOOT_MODE: %r\n", Status);
    return 1;
  }

  Status = EnrollDbFromDefault ();
  if (EFI_ERROR (Status)) {
    AsciiPrint ("EnrollFromDefaultKeysApp: Cannot enroll db: %r\n", Status);
    goto error;
  }

  Status = EnrollDbxFromDefault ();
  if (EFI_ERROR (Status)) {
    AsciiPrint ("EnrollFromDefaultKeysApp: Cannot enroll dbt: %r\n", Status);
  }

  Status = EnrollDbtFromDefault ();
  if (EFI_ERROR (Status)) {
    AsciiPrint ("EnrollFromDefaultKeysApp: Cannot enroll dbx: %r\n", Status);
  }

  Status = EnrollKEKFromDefault ();
  if (EFI_ERROR (Status)) {
    AsciiPrint ("EnrollFromDefaultKeysApp: Cannot enroll KEK: %r\n", Status);
    goto cleardbs;
  }

  Status = EnrollPKFromDefault ();
  if (EFI_ERROR (Status)) {
    AsciiPrint ("EnrollFromDefaultKeysApp: Cannot enroll PK: %r\n", Status);
    goto clearKEK;
  }

  Status = SetSecureBootMode (STANDARD_SECURE_BOOT_MODE);
  if (EFI_ERROR (Status)) {
    AsciiPrint (
      "EnrollFromDefaultKeysApp: Cannot set CustomMode to STANDARD_SECURE_BOOT_MODE\n"
      "Please do it manually, otherwise system can be easily compromised\n"
      );
  }

  return 0;

clearKEK:
  DeleteKEK ();

cleardbs:
  DeleteDbt ();
  DeleteDbx ();
  DeleteDb ();

error:
  Status = SetSecureBootMode (STANDARD_SECURE_BOOT_MODE);
  if (EFI_ERROR (Status)) {
    AsciiPrint (
      "EnrollFromDefaultKeysApp: Cannot set CustomMode to STANDARD_SECURE_BOOT_MODE\n"
      "Please do it manually, otherwise system can be easily compromised\n"
      );
  }

  return 1;
}
