/** @file
*
*  Copyright (c) 2011-2023, Arm Limited. All rights reserved.
*
*  SPDX-License-Identifier: BSD-2-Clause-Patent
*
**/

#include "edk2-master/MdePkg/Include/Uefi.h"
#include "edk2-master/MdePkg/Include/Library/IoLib.h"
#include "edk2-master/ArmPkg/Include/Library/ArmGicLib.h"

VOID
EFIAPI
ArmGicV2EnableInterruptInterface (
  IN  UINTN  GicInterruptInterfaceBase
  )
{
  /*
  * Enable the CPU interface in Non-Secure world
  * Note: The ICCICR register is banked when Security extensions are implemented
  */
  MmioWrite32 (GicInterruptInterfaceBase + ARM_GIC_ICCICR, 0x1);
}

VOID
EFIAPI
ArmGicV2DisableInterruptInterface (
  IN  UINTN  GicInterruptInterfaceBase
  )
{
  // Disable Gic Interface
  MmioWrite32 (GicInterruptInterfaceBase + ARM_GIC_ICCICR, 0x0);
  MmioWrite32 (GicInterruptInterfaceBase + ARM_GIC_ICCPMR, 0x0);
}
