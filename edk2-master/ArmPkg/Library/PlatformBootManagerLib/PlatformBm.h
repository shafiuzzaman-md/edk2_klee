/** @file
  Head file for BDS Platform specific code

  Copyright (C) 2015-2016, Red Hat, Inc.
  Copyright (c) 2004 - 2008, Intel Corporation. All rights reserved.<BR>
  Copyright (c) 2016, Linaro Ltd. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef PLATFORM_BM_H_
#define PLATFORM_BM_H_

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"

/**
  Use SystemTable Conout to stop video based Simple Text Out consoles from
  going to the video device. Put up LogoFile on every video device that is a
  console.

  @param[in]  LogoFile   File name of logo to display on the center of the
                         screen.

  @retval EFI_SUCCESS     ConsoleControl has been flipped to graphics and logo
                          displayed.
  @retval EFI_UNSUPPORTED Logo not found
**/
EFI_STATUS
EnableQuietBoot (
  IN  EFI_GUID  *LogoFile
  );

/**
  Use SystemTable Conout to turn on video based Simple Text Out consoles. The
  Simple Text Out screens will now be synced up with all non video output
  devices

  @retval EFI_SUCCESS     UGA devices are back in text mode and synced up.
**/
EFI_STATUS
DisableQuietBoot (
  VOID
  );

#endif // PLATFORM_BM_H_
