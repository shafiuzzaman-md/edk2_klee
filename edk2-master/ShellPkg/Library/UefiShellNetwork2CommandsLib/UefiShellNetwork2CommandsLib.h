/** @file
  Main file for NULL named library for network2 shell command functions.

  Copyright (c) 2016, Intel Corporation. All rights reserved. <BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _UEFI_SHELL_NETWORK2_COMMANDS_LIB_H_
#define _UEFI_SHELL_NETWORK2_COMMANDS_LIB_H_

#include "edk2-master/MdePkg/Include/Protocol/Cpu.h"
#include "edk2-master/MdePkg/Include/Protocol/ServiceBinding.h"
#include "edk2-master/MdePkg/Include/Protocol/Ip6.h"
#include "edk2-master/MdePkg/Include/Protocol/Ip6Config.h"

#include "edk2-master/ShellPkg/Include/Guid/ShellLibHiiGuid.h"

#include "edk2-master/ShellPkg/Include/Library/ShellLib.h"
#include "edk2-master/ShellPkg/Include/Library/ShellCommandLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/HiiLib.h"
#include "edk2-master/NetworkPkg/Include/Library/NetLib.h"

extern EFI_HII_HANDLE  gShellNetwork2HiiHandle;

/**
  Function for 'ping6' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).

  @retval SHELL_SUCCESS  The ping6 processed successfullly.
  @retval others         The ping6 processed unsuccessfully.

**/
SHELL_STATUS
EFIAPI
ShellCommandRunPing6 (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Function for 'ifconfig6' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).

  @retval SHELL_SUCCESS   The ifconfig6 command processed successfully.
  @retval others          The ifconfig6 command process failed.

**/
SHELL_STATUS
EFIAPI
ShellCommandRunIfconfig6 (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

#endif
