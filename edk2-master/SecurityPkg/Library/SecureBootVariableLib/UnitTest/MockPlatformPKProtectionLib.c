/** @file
  Provides a mocked interface for configuring PK related variable protection.

  Copyright (c) Microsoft Corporation.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/RedfishPkg/PrivateInclude/Crt/stdio.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/RedfishPkg/PrivateInclude/Crt/string.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/RedfishPkg/PrivateInclude/Crt/stdarg.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/RedfishPkg/PrivateInclude/Crt/stddef.h"
#include <setjmp.h>
#include <cmocka.h>

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"

/**
  Disable any applicable protection against variable 'PK'. The implementation
  of this interface is platform specific, depending on the protection techniques
  used per platform.

  Note: It is the platform's responsibility to conduct cautious operation after
        disabling this protection.

  @retval     EFI_SUCCESS             State has been successfully updated.
  @retval     Others                  Error returned from implementation specific
                                      underying APIs.

**/
EFI_STATUS
EFIAPI
DisablePKProtection (
  VOID
  )
{
  return (EFI_STATUS)mock ();
}
