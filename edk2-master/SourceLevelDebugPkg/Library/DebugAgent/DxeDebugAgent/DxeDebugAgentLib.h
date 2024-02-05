/** @file
  Header file for Dxe Core Debug Agent Library instance.

  Copyright (c) 2010 - 2018, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _DXE_CORE_DEBUG_AGENT_LIB_H_
#define _DXE_CORE_DEBUG_AGENT_LIB_H_

#include "edk2-master/MdePkg/Include/PiDxe.h"

#include "edk2-master/MdePkg/Include/Protocol/SerialIo.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/DevicePath.h"
#include "edk2-master/MdePkg/Include/Protocol/PiPcd.h"

#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"

#include "DebugAgent.h"

/**
  Install EFI Serial IO protocol based on Debug Communication Library.

**/
VOID
InstallSerialIo (
  VOID
  );

#endif
