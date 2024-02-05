/** @file
  HddPassword PEI module which is used to unlock HDD password for S3.

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _HDD_PASSWORD_PEI_H_
#define _HDD_PASSWORD_PEI_H_

#include "edk2-master/MdePkg/Include/PiPei.h"
#include "edk2-master/MdePkg/Include/IndustryStandard/Atapi.h"

#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/PeimEntryPoint.h"
#include "edk2-master/MdePkg/Include/Library/PeiServicesLib.h"
#include "edk2-master/MdePkg/Include/Library/PciLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/LockBoxLib.h"

#include "edk2-master/MdeModulePkg/Include/Ppi/AtaPassThru.h"

#include "HddPasswordCommon.h"

//
// Time out value for ATA PassThru PPI
//
#define ATA_TIMEOUT  30000000

#endif
