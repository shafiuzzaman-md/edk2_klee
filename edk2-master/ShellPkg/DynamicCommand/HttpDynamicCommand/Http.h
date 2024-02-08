/** @file
  Header file for 'http' command functions.

  Copyright (c) 2010 - 2017, Intel Corporation. All rights reserved. <BR>
  Copyright (c) 2015, ARM Ltd. All rights reserved.<BR>
  Copyright (c) 2020, Broadcom. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _HTTP_H_
#define _HTTP_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Library/HiiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/NetworkPkg/Include/Library/HttpLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/NetworkPkg/Include/Library/NetLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PrintLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/ShellPkg/Include/Library/ShellLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Library/UefiHiiServicesLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/HiiPackageList.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/HttpUtilities.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/ServiceBinding.h"

#define HTTP_APP_NAME  L"http"

#define REQ_OK           0
#define REQ_NEED_REPEAT  1

//
// Download Flags.
//
#define DL_FLAG_TIME      BIT0 // Show elapsed time.
#define DL_FLAG_KEEP_BAD  BIT1 // Keep files even if download failed.

extern EFI_HII_HANDLE  mHttpHiiHandle;

typedef struct {
  UINTN                   ContentDownloaded;
  UINTN                   ContentLength;
  UINTN                   LastReportedNbOfBytes;
  UINTN                   BufferSize;
  UINTN                   Status;
  UINTN                   Flags;
  UINT8                   *Buffer;
  CHAR16                  *ServerAddrAndProto;
  CHAR16                  *Uri;
  EFI_HTTP_TOKEN          ResponseToken;
  EFI_HTTP_TOKEN          RequestToken;
  EFI_HTTP_PROTOCOL       *Http;
  EFI_HTTP_CONFIG_DATA    HttpConfigData;
} HTTP_DOWNLOAD_CONTEXT;

/**
  Function for 'http' command.

  @param[in]  ImageHandle     The image handle.
  @param[in]  SystemTable     The system table.

  @retval SHELL_SUCCESS            Command completed successfully.
  @retval SHELL_INVALID_PARAMETER  Command usage error.
  @retval SHELL_ABORTED            The user aborts the operation.
  @retval value                    Unknown error.
**/
SHELL_STATUS
RunHttp (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Retrieve HII package list from ImageHandle and publish to HII database.

  @param[in] ImageHandle            The image handle of the process.

  @retval HII handle.
**/
EFI_HII_HANDLE
InitializeHiiPackage (
  IN EFI_HANDLE  ImageHandle
  );

#endif // _HTTP_H_
