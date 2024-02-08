/** @file

  CcProbeLib is used to probe the Confidential computing guest type.

  Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/CcProbeLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/WorkArea.h"

/**
  Probe the ConfidentialComputing Guest type. See defition of
  CC_GUEST_TYPE in <ConfidentialComputingGuestAttr.h>.

  @return The guest type

**/
UINT8
EFIAPI
CcProbe (
  VOID
  )
{
  OVMF_WORK_AREA  *WorkArea;

  WorkArea = (OVMF_WORK_AREA *)FixedPcdGet32 (PcdOvmfWorkAreaBase);

  return WorkArea != NULL ? WorkArea->Header.GuestType : CcGuestTypeNonEncrypted;
}
