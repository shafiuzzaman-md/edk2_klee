/*++

Copyright (c) 2013-2017, ARM Ltd. All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent

--*/

#ifndef ARM_GIC_DXE_H_
#define ARM_GIC_DXE_H_

#include "edk2-master/ArmPkg/Include/Library/ArmGicLib.h"
#include "edk2-master/ArmPkg/Include/Library/ArmLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/IoLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"

#include "edk2-master/MdePkg/Include/Protocol/Cpu.h"
#include "edk2-master/EmbeddedPkg/Include/Protocol/HardwareInterrupt.h"
#include "edk2-master/EmbeddedPkg/Include/Protocol/HardwareInterrupt2.h"

extern UINTN                       mGicNumInterrupts;
extern HARDWARE_INTERRUPT_HANDLER  *gRegisteredInterruptHandlers;

// Common API
EFI_STATUS
InstallAndRegisterInterruptService (
  IN EFI_HARDWARE_INTERRUPT_PROTOCOL   *InterruptProtocol,
  IN EFI_HARDWARE_INTERRUPT2_PROTOCOL  *Interrupt2Protocol,
  IN EFI_CPU_INTERRUPT_HANDLER         InterruptHandler,
  IN EFI_EVENT_NOTIFY                  ExitBootServicesEvent
  );

EFI_STATUS
EFIAPI
RegisterInterruptSource (
  IN EFI_HARDWARE_INTERRUPT_PROTOCOL  *This,
  IN HARDWARE_INTERRUPT_SOURCE        Source,
  IN HARDWARE_INTERRUPT_HANDLER       Handler
  );

// GicV2 API
EFI_STATUS
GicV2DxeInitialize (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

// GicV3 API
EFI_STATUS
GicV3DxeInitialize (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

// Shared code

/**
  Calculate GICD_ICFGRn base address and corresponding bit
  field Int_config[1] of the GIC distributor register.

  @param Source       Hardware source of the interrupt.
  @param RegAddress   Corresponding GICD_ICFGRn base address.
  @param Config1Bit   Bit number of F Int_config[1] bit in the register.

  @retval EFI_SUCCESS       Source interrupt supported.
  @retval EFI_UNSUPPORTED   Source interrupt is not supported.
**/
EFI_STATUS
GicGetDistributorIcfgBaseAndBit (
  IN HARDWARE_INTERRUPT_SOURCE  Source,
  OUT UINTN                     *RegAddress,
  OUT UINTN                     *Config1Bit
  );

#endif // ARM_GIC_DXE_H_
