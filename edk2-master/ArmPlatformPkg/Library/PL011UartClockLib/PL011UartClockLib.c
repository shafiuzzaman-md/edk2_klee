/** @file

  Copyright 2018 NXP

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Base.h"

/**
  Return clock in for PL011 Uart IP

  @return Pcd PL011UartClkInHz
**/
UINT32
EFIAPI
PL011UartClockGetFreq (
  VOID
  )
{
  return FixedPcdGet32 (PL011UartClkInHz);
}
