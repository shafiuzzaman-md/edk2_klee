/** @file
  Recovery module header file.

  Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _RECOVERY_MODULE_LOAD_PEI_H_
#define _RECOVERY_MODULE_LOAD_PEI_H_

#include "edk2-master/MdePkg/Include/PiPei.h"

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/MdePkg/Include/Library/HobLib.h"
#include "edk2-master/SignedCapsulePkg/Include/Library/EdkiiSystemCapsuleLib.h"

//
// Update data
//

typedef struct {
  UINTN    NumOfRecovery;
} CONFIG_HEADER;

typedef struct {
  UINTN       Index;
  EFI_GUID    FileGuid;
  UINTN       Length;
  UINTN       ImageOffset;
} RECOVERY_CONFIG_DATA;

#endif
