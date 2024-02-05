/** @file
  The header file of bootloader support SMM.

  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef BL_SUPPORT_SMM_H_
#define BL_SUPPORT_SMM_H_

#include "edk2-master/MdePkg/Include/PiDxe.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/IoLib.h"
#include "edk2-master/MdePkg/Include/Library/HobLib.h"
#include "edk2-master/UefiCpuPkg/Include/Library/MtrrLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/SmmServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/PciLib.h"
#include "edk2-master/MdePkg/Include/Protocol/SmmSwDispatch2.h"
#include "edk2-master/MdePkg/Include/Protocol/SmmAccess2.h"
#include "edk2-master/MdePkg/Include/Protocol/MpService.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include <Register/Intel/ArchitecturalMsr.h>
#include "edk2-master/UefiPayloadPkg/Include/Guid/SmmRegisterInfoGuid.h"
#include "edk2-master/UefiPayloadPkg/Include/Guid/SmmS3CommunicationInfoGuid.h"
#include "edk2-master/MdePkg/Include/Guid/SmramMemoryReserve.h"

#define  EFI_MSR_SMRR_MASK            0xFFFFF000
#define  MSR_SMM_FEATURE_CONTROL      0x4E0
#define  SMRAM_SAVE_STATE_MAP_OFFSET  0xFC00    /// Save state offset from SMBASE

typedef struct {
  UINT32    Base;
  UINT32    Mask;
} SMRR_BASE_MASK;

#endif
