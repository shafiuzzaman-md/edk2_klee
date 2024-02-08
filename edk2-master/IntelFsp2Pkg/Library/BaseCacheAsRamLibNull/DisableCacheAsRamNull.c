/** @file

  Copyright (c) 2014, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/IntelFsp2Pkg/Include/Library/CacheAsRamLib.h"

/**
  This function disable CAR.

  @param[in] DisableCar       TRUE means use INVD, FALSE means use WBINVD

**/
VOID
EFIAPI
DisableCacheAsRam (
  IN BOOLEAN  DisableCar
  )
{
  //
  // Disable CAR
  //

  if (DisableCar) {
    AsmInvd ();
  } else {
    AsmWbinvd ();
  }

  return;
}
