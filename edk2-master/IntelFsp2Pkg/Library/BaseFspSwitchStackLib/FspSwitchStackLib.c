/** @file

  Copyright (c) 2014 - 2022, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Base.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/IntelFsp2Pkg/Include/Library/FspCommonLib.h"

/**

  Switch the current stack to the previous saved stack.

  @param[in]  NewStack         The new stack to be switched.

  @return OldStack         After switching to the saved stack,
                           this value will be saved in eax before returning.


**/
UINTN
EFIAPI
SwapStack (
  IN  UINTN  NewStack
  )
{
  FSP_GLOBAL_DATA  *FspData;
  UINTN            OldStack;

  FspData            = GetFspGlobalDataPointer ();
  OldStack           = FspData->CoreStack;
  FspData->CoreStack = (UINTN)NewStack;
  return OldStack;
}
