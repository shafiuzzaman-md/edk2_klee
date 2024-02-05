/** @file
  UEFI OS based application for unit testing the DevicePathLib.

  Copyright (c) 2023, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef __TEST_DEVICE_PATH_LIB_H__
#define __TEST_DEVICE_PATH_LIB_H__

#include "edk2-master/MdePkg/Include/PiPei.h"
#include "edk2-master/MdePkg/Include/Uefi.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/UnitTestLib.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/DevicePath.h"
#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "edk2-master/CryptoPkg/Library/Include/stdint.h"

EFI_STATUS
CreateDevicePathStringConversionsTestSuite (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework
  );

#endif
