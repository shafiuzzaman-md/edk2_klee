/** @file
  Define the structure for the Boot Manager Menu File.

Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef UNIVERSAL_PAYLOAD_BOOT_MANAGER_MENU_H_
#define UNIVERSAL_PAYLOAD_BOOT_MANAGER_MENU_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/UniversalPayload/UniversalPayload.h"

#pragma pack (1)

typedef struct {
  UNIVERSAL_PAYLOAD_GENERIC_HEADER    Header;
  GUID                                FileName;
} UNIVERSAL_PAYLOAD_BOOT_MANAGER_MENU;

#pragma pack()

#define UNIVERSAL_PAYLOAD_BOOT_MANAGER_MENU_REVISION  1

extern GUID  gEdkiiBootManagerMenuFileGuid;
#endif
