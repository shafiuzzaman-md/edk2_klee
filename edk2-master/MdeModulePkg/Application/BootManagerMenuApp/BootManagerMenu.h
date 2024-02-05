/** @file
  FrontPage routines to handle the callbacks and browser calls

Copyright (c) 2004 - 2018, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _BOOT_MANAGER_MENU_H_
#define _BOOT_MANAGER_MENU_H_

#include "edk2-master/MdePkg/Include/Uefi.h"
#include "edk2-master/MdeModulePkg/Include/Guid/MdeModuleHii.h"
#include "edk2-master/MdeModulePkg/Include/Library/UefiBootManagerLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/HiiLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "edk2-master/MdePkg/Include/Protocol/LoadedImage.h"
#include "edk2-master/MdeModulePkg/Include/Protocol/BootLogo.h"

#define TITLE_TOKEN_COUNT  1
#define HELP_TOKEN_COUNT   3

typedef struct _BOOT_MENU_SCREEN {
  UINTN    StartCol;
  UINTN    StartRow;
  UINTN    Width;
  UINTN    Height;
} BOOT_MENU_SCREEN;

typedef struct _BOOT_MENU_SCROLL_BAR_CONTROL {
  BOOLEAN    HasScrollBar;
  UINTN      ItemCountPerScreen;
  UINTN      FirstItem;
  UINTN      LastItem;
} BOOT_MENU_SCROLL_BAR_CONTROL;

typedef struct _BOOT_MENU_POPUP_DATA {
  EFI_STRING_ID                   TitleToken[TITLE_TOKEN_COUNT]; // Title string ID
  UINTN                           ItemCount;                     // Selectable item count
  EFI_STRING_ID                   *PtrTokens;                    // All of selectable items string ID
  EFI_STRING_ID                   HelpToken[HELP_TOKEN_COUNT];   // All of help string ID
  UINTN                           SelectItem;                    // Current select  item
  BOOT_MENU_SCREEN                MenuScreen;                    // Boot menu screen information
  BOOT_MENU_SCROLL_BAR_CONTROL    ScrollBarControl;              // Boot menu scroll bar information
} BOOT_MENU_POPUP_DATA;

#endif
