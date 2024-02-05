/** @file
  Provides interface to shell internal functions for shell commands.

  Copyright (c) 2006 - 2018, Intel Corporation. All rights reserved. <BR>
  (C) Copyright 2016 Hewlett Packard Enterprise Development LP<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _UEFI_COMMAND_LIB_INTERNAL_HEADER_
#define _UEFI_COMMAND_LIB_INTERNAL_HEADER_

#include "edk2-master/MdePkg/Include/Uefi.h"

#include "edk2-master/MdePkg/Include/Guid/FileInfo.h"
#include "edk2-master/MdePkg/Include/Guid/GlobalVariable.h"

#include "edk2-master/MdePkg/Include/Protocol/SimpleFileSystem.h"
#include "edk2-master/MdePkg/Include/Protocol/LoadedImage.h"
#include "edk2-master/ShellPkg/Include/Protocol/EfiShellInterface.h"
#include "edk2-master/ShellPkg/Include/Protocol/EfiShellEnvironment2.h"
#include "edk2-master/MdePkg/Include/Protocol/Shell.h"
#include "edk2-master/MdePkg/Include/Protocol/ShellParameters.h"
#include "edk2-master/MdePkg/Include/Protocol/UnicodeCollation.h"
#include "edk2-master/MdePkg/Include/Protocol/BlockIo.h"
#include "edk2-master/MdePkg/Include/Protocol/ShellDynamicCommand.h"

#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/SortLib.h"
#include "edk2-master/ShellPkg/Include/Library/HandleParsingLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/ShellPkg/Include/Library/ShellCommandLib.h"
#include "edk2-master/MdePkg/Include/Library/PrintLib.h"
#include "edk2-master/ShellPkg/Include/Library/ShellLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/HiiLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/OrderedCollectionLib.h"

typedef struct {
  LIST_ENTRY                Link;
  CHAR16                    *CommandString;
  SHELL_GET_MAN_FILENAME    GetManFileName;
  SHELL_RUN_COMMAND         CommandHandler;
  BOOLEAN                   LastError;
  EFI_HII_HANDLE            HiiHandle;
  EFI_STRING_ID             ManFormatHelp;
} SHELL_COMMAND_INTERNAL_LIST_ENTRY;

typedef struct {
  LIST_ENTRY     Link;
  SCRIPT_FILE    *Data;
} SCRIPT_FILE_LIST;

typedef struct {
  EFI_FILE_PROTOCOL    *FileHandle;
  CHAR16               *Path;
} SHELL_COMMAND_FILE_HANDLE;

//
// Collects multiple EFI_SHELL_FILE_INFO objects that share the same name.
//
typedef struct {
  //
  // A string that compares equal to either the FileName or the FullName fields
  // of all EFI_SHELL_FILE_INFO objects on SameNameList, according to
  // gUnicodeCollation->StriColl(). The string is not dynamically allocated;
  // instead, it *aliases* the FileName or FullName field of the
  // EFI_SHELL_FILE_INFO object that was first encountered with this name.
  //
  CONST CHAR16    *Alias;
  //
  // A list of EFI_SHELL_FILE_INFO objects whose FileName or FullName fields
  // compare equal to Alias, according to gUnicodeCollation->StriColl().
  //
  LIST_ENTRY      SameNameList;
} SHELL_SORT_UNIQUE_NAME;

#endif //_UEFI_COMMAND_LIB_INTERNAL_HEADER_
