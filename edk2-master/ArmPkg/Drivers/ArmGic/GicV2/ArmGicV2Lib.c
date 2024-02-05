/** @file
*
*  Copyright (c) 2013-2023, ARM Limited. All rights reserved.
*
*  SPDX-License-Identifier: BSD-2-Clause-Patent
*
**/

#include "edk2-master/ArmPkg/Include/Library/ArmGicLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/IoLib.h"

UINTN
EFIAPI
ArmGicV2AcknowledgeInterrupt (
  IN  UINTN  GicInterruptInterfaceBase
  )
{
  // Read the Interrupt Acknowledge Register
  return MmioRead32 (GicInterruptInterfaceBase + ARM_GIC_ICCIAR);
}

VOID
EFIAPI
ArmGicV2EndOfInterrupt (
  IN  UINTN  GicInterruptInterfaceBase,
  IN UINTN   Source
  )
{
  ASSERT (Source <= MAX_UINT32);
  MmioWrite32 (GicInterruptInterfaceBase + ARM_GIC_ICCEIOR, (UINT32)Source);
}
