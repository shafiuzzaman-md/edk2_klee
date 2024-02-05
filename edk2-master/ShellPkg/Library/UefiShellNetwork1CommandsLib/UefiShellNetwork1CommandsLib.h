/** @file
  header file for NULL named library for network1 shell command functions.

  Copyright (c) 2010 - 2016, Intel Corporation. All rights reserved. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _UEFI_SHELL_NETWORK1_COMMANDS_LIB_H_
#define _UEFI_SHELL_NETWORK1_COMMANDS_LIB_H_

#include "edk2-master/MdePkg/Include/Uefi.h"

#include "edk2-master/ShellPkg/Include/Guid/ShellLibHiiGuid.h"

#include "edk2-master/MdePkg/Include/Protocol/Cpu.h"
#include "edk2-master/MdePkg/Include/Protocol/ServiceBinding.h"
#include "edk2-master/MdePkg/Include/Protocol/Ip6.h"
#include "edk2-master/MdePkg/Include/Protocol/Ip6Config.h"
#include "edk2-master/MdePkg/Include/Protocol/Ip4.h"
#include "edk2-master/MdePkg/Include/Protocol/Ip4Config2.h"
#include "edk2-master/MdePkg/Include/Protocol/Arp.h"

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/ShellPkg/Include/Library/ShellCommandLib.h"
#include "edk2-master/ShellPkg/Include/Library/ShellLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/SortLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/HiiLib.h"
#include "edk2-master/NetworkPkg/Include/Library/NetLib.h"
#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "edk2-master/MdePkg/Include/Library/PrintLib.h"

extern EFI_HII_HANDLE  gShellNetwork1HiiHandle;

/**
  Function for 'ping' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunPing (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Function for 'ifconfig' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunIfconfig (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

#endif
