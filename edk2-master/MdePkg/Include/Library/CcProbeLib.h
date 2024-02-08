/** @file

Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef CC_PROBE_LIB_H_
#define CC_PROBE_LIB_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/ConfidentialComputingGuestAttr.h"

/**
  Probe the ConfidentialComputing Guest type. See defition of
  CC_GUEST_TYPE in <ConfidentialComputingGuestAttr.h>.

  @return The guest type

**/
UINT8
EFIAPI
CcProbe (
  VOID
  );

#endif
