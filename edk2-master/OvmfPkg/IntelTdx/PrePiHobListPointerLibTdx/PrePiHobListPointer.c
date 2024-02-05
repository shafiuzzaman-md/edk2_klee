/** @file
*
*  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
*  SPDX-License-Identifier: BSD-2-Clause-Patent
*
**/

#include "edk2-master/MdePkg/Include/PiPei.h"
#include "edk2-master/EmbeddedPkg/Include/Library/PrePiHobListPointerLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/HobLib.h"
#include "edk2-master/OvmfPkg/Include/WorkArea.h"

/**
  Returns the pointer to the HOB list.

  This function returns the pointer to first HOB in the list.

  @return The pointer to the HOB list.

**/
VOID *
EFIAPI
PrePeiGetHobList (
  VOID
  )
{
  TDX_WORK_AREA  *TdxWorkArea;

  TdxWorkArea = (TDX_WORK_AREA *)(UINTN)FixedPcdGet32 (PcdOvmfWorkAreaBase);
  ASSERT (TdxWorkArea != NULL);
  ASSERT (TdxWorkArea->SecTdxWorkArea.HobList != 0);

  return (VOID *)(UINTN)TdxWorkArea->SecTdxWorkArea.HobList;
}

/**
  Updates the pointer to the HOB list.

  @param  HobList       Hob list pointer to store

**/
EFI_STATUS
EFIAPI
PrePeiSetHobList (
  IN  VOID  *HobList
  )
{
  TDX_WORK_AREA  *TdxWorkArea;

  TdxWorkArea = (TDX_WORK_AREA *)(UINTN)FixedPcdGet32 (PcdOvmfWorkAreaBase);
  ASSERT (TdxWorkArea != NULL);

  TdxWorkArea->SecTdxWorkArea.HobList = (UINTN)HobList;

  return EFI_SUCCESS;
}
