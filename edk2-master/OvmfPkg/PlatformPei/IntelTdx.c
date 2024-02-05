/** @file
  Initialize Intel TDX support.

  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "edk2-master/MdePkg/Include/PiPei.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/HobLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/IndustryStandard/Tdx.h"
#include "edk2-master/OvmfPkg/Include/IndustryStandard/QemuFwCfg.h"
#include "edk2-master/OvmfPkg/Include/Library/QemuFwCfgLib.h"
#include "edk2-master/MdePkg/Include/Library/PeiServicesLib.h"
#include "edk2-master/MdePkg/Include/Library/TdxLib.h"
#include "edk2-master/OvmfPkg/Include/Library/TdxHelperLib.h"
#include "edk2-master/OvmfPkg/Include/Library/PlatformInitLib.h"
#include "edk2-master/OvmfPkg/Include/WorkArea.h"
#include "edk2-master/MdePkg/Include/ConfidentialComputingGuestAttr.h"
#include "Platform.h"

/**
  This Function checks if TDX is available, if present then it sets
  the dynamic PCDs for Tdx guest.
  **/
VOID
IntelTdxInitialize (
  VOID
  )
{
 #ifdef MDE_CPU_X64
  RETURN_STATUS  PcdStatus;

  if (!TdIsEnabled ()) {
    return;
  }

  TdxHelperBuildGuidHobForTdxMeasurement ();

  PcdStatus = PcdSet64S (PcdConfidentialComputingGuestAttr, CCAttrIntelTdx);
  ASSERT_RETURN_ERROR (PcdStatus);

  PcdStatus = PcdSet64S (PcdTdxSharedBitMask, TdSharedPageMask ());
  ASSERT_RETURN_ERROR (PcdStatus);

  PcdStatus = PcdSetBoolS (PcdSetNxForStack, TRUE);
  ASSERT_RETURN_ERROR (PcdStatus);
 #endif
}
