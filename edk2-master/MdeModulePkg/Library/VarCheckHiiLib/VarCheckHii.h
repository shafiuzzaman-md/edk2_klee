/** @file
  Include file for Var Check Hii handler and bin.

Copyright (c) 2015 - 2017, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _VAR_CHECK_HII_H_
#define _VAR_CHECK_HII_H_

#include "edk2-master/MdeModulePkg/Include/Library/VarCheckLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"

#include "edk2-master/MdeModulePkg/Include/Guid/MdeModuleHii.h"

#include "edk2-master/MdePkg/Include/Protocol/HiiDatabase.h"
#include "edk2-master/MdePkg/Include/Protocol/FirmwareVolume2.h"
#include "edk2-master/MdePkg/Include/Protocol/FirmwareVolumeBlock.h"

#include "InternalVarCheckStructure.h"
#include "VarCheckHiiGen.h"

// #define DUMP_VAR_CHECK_HII
// #define DUMP_HII_DATA

typedef struct {
  UINT8    HiiOpCode;
  CHAR8    *HiiOpCodeStr;
} VAR_CHECK_HII_OPCODE_STRING;

typedef struct {
  UINT8    PackageType;
  CHAR8    *PackageTypeStr;
} VAR_CHECK_HII_PACKAGE_TYPE_STRING;

/**
  Dump Var Check HII.

  @param[in] VarCheckHiiBin     Pointer to VarCheckHiiBin.
  @param[in] VarCheckHiiBinSize VarCheckHiiBin size.

**/
VOID
DumpVarCheckHii (
  IN VOID   *VarCheckHiiBin,
  IN UINTN  VarCheckHiiBinSize
  );

extern VAR_CHECK_HII_VARIABLE_HEADER  *mVarCheckHiiBin;
extern UINTN                          mVarCheckHiiBinSize;

#endif
