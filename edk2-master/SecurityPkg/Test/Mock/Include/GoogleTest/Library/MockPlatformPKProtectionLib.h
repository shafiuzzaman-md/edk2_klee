/** @file
  Google Test mocks for PlatformPKProtectionLib

  Copyright (c) 2022, Intel Corporation. All rights reserved.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef MOCK_PLATFORM_PK_PROTECTION_LIB_H_
#define MOCK_PLATFORM_PK_PROTECTION_LIB_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/UnitTestFrameworkPkg/Include/Library/GoogleTestLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/UnitTestFrameworkPkg/Include/Library/FunctionMockLib.h"
extern "C" {
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/SecurityPkg/Include/Library/PlatformPKProtectionLib.h"
}

struct MockPlatformPKProtectionLib {
  MOCK_INTERFACE_DECLARATION (MockPlatformPKProtectionLib);

  MOCK_FUNCTION_DECLARATION (
    EFI_STATUS,
    DisablePKProtection,
    ()
    );
};

#endif
