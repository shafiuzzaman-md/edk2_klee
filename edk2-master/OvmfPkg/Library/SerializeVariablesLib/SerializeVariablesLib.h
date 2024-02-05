/** @file
  Serialize Variables Library implementation

  Copyright (c) 2009 - 2011, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __SERIALIZE_VARIABLES_LIB_INSTANCE__
#define __SERIALIZE_VARIABLES_LIB_INSTANCE__

#include "edk2-master/MdePkg/Include/Uefi.h"

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/OvmfPkg/Include/Library/SerializeVariablesLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"

#define SV_FROM_HANDLE(a)  CR (a, SV_INSTANCE, Signature, SV_SIGNATURE)
#define SV_SIGNATURE  SIGNATURE_32 ('S', 'V', 'A', 'R')

typedef struct {
  UINT32    Signature;
  VOID      *BufferPtr;
  UINTN     BufferSize;
  UINTN     DataSize;
} SV_INSTANCE;

#endif
