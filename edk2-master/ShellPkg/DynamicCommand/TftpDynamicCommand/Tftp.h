/** @file
  Header file for 'tftp' command functions.

  Copyright (c) 2010 - 2017, Intel Corporation. All rights reserved. <BR>
  Copyright (c) 2015, ARM Ltd. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _TFTP_H_
#define _TFTP_H_

#include "edk2-master/MdePkg/Include/Uefi.h"

#include "edk2-master/MdePkg/Include/Protocol/HiiPackageList.h"
#include "edk2-master/MdePkg/Include/Protocol/ServiceBinding.h"
#include "edk2-master/MdePkg/Include/Protocol/Mtftp4.h"

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/ShellPkg/Include/Library/ShellLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/HiiLib.h"
#include "edk2-master/NetworkPkg/Include/Library/NetLib.h"
#include "edk2-master/MdePkg/Include/Library/PrintLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/UefiHiiServicesLib.h"

extern EFI_HII_HANDLE  mTftpHiiHandle;

typedef struct {
  UINTN    FileSize;
  UINTN    DownloadedNbOfBytes;
  UINTN    LastReportedNbOfBytes;
} DOWNLOAD_CONTEXT;

/**
  Function for 'tftp' command.

  @param[in]  ImageHandle     The image handle.
  @param[in]  SystemTable     The system table.

  @retval SHELL_SUCCESS            Command completed successfully.
  @retval SHELL_INVALID_PARAMETER  Command usage error.
  @retval SHELL_ABORTED            The user aborts the operation.
  @retval value                    Unknown error.
**/
SHELL_STATUS
RunTftp (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Retrieve HII package list from ImageHandle and publish to HII database.

  @param ImageHandle            The image handle of the process.

  @return HII handle.
**/
EFI_HII_HANDLE
InitializeHiiPackage (
  EFI_HANDLE  ImageHandle
  );

#endif // _TFTP_H_
