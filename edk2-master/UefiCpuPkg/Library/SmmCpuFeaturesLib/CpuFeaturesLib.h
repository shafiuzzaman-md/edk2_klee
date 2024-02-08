/** @file
  Internal library function definitions.

  Copyright (c) Microsoft Corporation.
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef CPU_FEATURES_LIB_H_
#define CPU_FEATURES_LIB_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/UefiCpuPkg/Include/Guid/SmmBaseHob.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/UefiCpuPkg/Include/Library/SmmCpuFeaturesLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/HobLib.h"

/**
  Performs library initialization.

  This initialization function contains common functionality shared betwen all
  library instance constructors.

**/
VOID
CpuFeaturesLibInitialization (
  VOID
  );

/**
  Internal worker function that is called to complete CPU initialization at the
  end of SmmCpuFeaturesInitializeProcessor().

**/
VOID
FinishSmmCpuFeaturesInitializeProcessor (
  VOID
  );

/**
  Gets the maximum number of logical processors from the PCD PcdCpuMaxLogicalProcessorNumber.

  This access is abstracted from the PCD services to enforce that the PCD be
  FixedAtBuild in the Standalone MM build of this driver.

  @return  The value of PcdCpuMaxLogicalProcessorNumber.

**/
UINT32
GetCpuMaxLogicalProcessorNumber (
  VOID
  );

#endif
