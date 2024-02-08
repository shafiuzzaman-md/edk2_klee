/** @file
  This library retrieve the EFI_BOOT_SERVICES pointer from EFI system table in
  library's constructor.

  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"

/**
  The dummy constructor for DxeHobListLib.

  @retval  EFI_SUCCESS

**/
EFI_STATUS
EFIAPI
DxeHobListLibNullConstructor (
  VOID
  )
{
  return EFI_SUCCESS;
}
