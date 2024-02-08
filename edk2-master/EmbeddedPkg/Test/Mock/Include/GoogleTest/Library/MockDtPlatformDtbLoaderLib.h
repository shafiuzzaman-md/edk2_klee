/** @file
  Google Test mocks for DtPlatformDtbLoaderLib

  Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
  Copyright (c) 2023, Intel Corporation. All rights reserved.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef MOCK_DT_PLATFORM_DTB_LOADER_LIB_H_
#define MOCK_DT_PLATFORM_DTB_LOADER_LIB_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/UnitTestFrameworkPkg/Include/Library/GoogleTestLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/UnitTestFrameworkPkg/Include/Library/FunctionMockLib.h"
extern "C" {
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Pi/PiMultiPhase.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmbeddedPkg/Include/Library/DtPlatformDtbLoaderLib.h"
}

struct MockDtPlatformDtbLoaderLib {
  MOCK_INTERFACE_DECLARATION (MockDtPlatformDtbLoaderLib);

  MOCK_FUNCTION_DECLARATION (
    EFI_STATUS,
    DtPlatformLoadDtb,
    (OUT   VOID   **Dtb,
     OUT   UINTN  *DtbSize)
    );
};

#endif
