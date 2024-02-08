/** @file
  Traditional MM CPU specific programming.

  Copyright (c) Microsoft Corporation.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Base.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "CpuFeaturesLib.h"

/**
  Gets the maximum number of logical processors from the PCD PcdCpuMaxLogicalProcessorNumber.

  This access is abstracted from the PCD services to enforce that the PCD be
  FixedAtBuild in the Standalone MM build of this driver.

  @return  The value of PcdCpuMaxLogicalProcessorNumber.

**/
UINT32
GetCpuMaxLogicalProcessorNumber (
  VOID
  )
{
  return PcdGet32 (PcdCpuMaxLogicalProcessorNumber);
}
