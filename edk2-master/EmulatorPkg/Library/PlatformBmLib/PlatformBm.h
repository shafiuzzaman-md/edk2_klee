/*++ @file

Copyright (c) 2006 - 2018, Intel Corporation. All rights reserved.<BR>
Portions copyright (c) 2011, Apple Inc. All rights reserved.
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _PLATFORM_BM_H
#define _PLATFORM_BM_H

#include "edk2-master/MdePkg/Include/PiDxe.h"

#include "edk2-master/EmulatorPkg/Include/Guid/EmuSystemConfig.h"
#include "edk2-master/MdePkg/Include/Guid/EventGroup.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuThunk.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuIoThunk.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuGraphicsWindow.h"
#include "edk2-master/MdeModulePkg/Include/Protocol/GenericMemoryTest.h"
#include "edk2-master/MdePkg/Include/Protocol/LoadedImage.h"
#include "edk2-master/MdePkg/Include/Protocol/FirmwareVolume2.h"

#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/UefiBootManagerLib.h"
#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/BootLogoLib.h"
#include "edk2-master/MdePkg/Include/Library/HobLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/HiiLib.h"

#define CONSOLE_OUT  0x00000001
#define STD_ERROR    0x00000002
#define CONSOLE_IN   0x00000004
#define CONSOLE_ALL  (CONSOLE_OUT | CONSOLE_IN | STD_ERROR)

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL    *DevicePath;
  UINTN                       ConnectType;
} BDS_CONSOLE_CONNECT_ENTRY;

extern BDS_CONSOLE_CONNECT_ENTRY  gPlatformConsole[];

#define gEndEntire \
  { \
    END_DEVICE_PATH_TYPE,\
    END_ENTIRE_DEVICE_PATH_SUBTYPE,\
    { \
      END_DEVICE_PATH_LENGTH,\
      0\
    }\
  }

typedef struct {
  EMU_VENDOR_DEVICE_PATH_NODE    EmuBus;
  EMU_VENDOR_DEVICE_PATH_NODE    EmuGraphicsWindow;
  EFI_DEVICE_PATH_PROTOCOL       End;
} EMU_PLATFORM_UGA_DEVICE_PATH;

//
// Platform BDS Functions
//

/**
  Perform the memory test base on the memory test intensive level,
  and update the memory resource.

  @param  Level         The memory test intensive level.

  @retval EFI_STATUS    Success test all the system memory and update
                        the memory resource

**/
EFI_STATUS
PlatformBootManagerMemoryTest (
  IN EXTENDMEM_COVERAGE_LEVEL  Level
  );

VOID
PlatformBdsConnectSequence (
  VOID
  );

#endif // _PLATFORM_BM_H
