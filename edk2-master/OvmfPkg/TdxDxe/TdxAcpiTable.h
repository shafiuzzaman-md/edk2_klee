/** @file

  Copyright (c) 2008 - 2012, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef TDX_ACPI_TABLE_H_
#define TDX_ACPI_TABLE_H_

#include "edk2-master/MdePkg/Include/PiDxe.h"

#include "edk2-master/MdePkg/Include/Protocol/AcpiTable.h"
#include "edk2-master/MdePkg/Include/Protocol/FirmwareVolume2.h"
#include "edk2-master/MdePkg/Include/Protocol/PciIo.h"

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/OvmfPkg/Include/IndustryStandard/IntelTdx.h"
#include "edk2-master/MdePkg/Include/IndustryStandard/Acpi.h"

VOID
EFIAPI
AsmGetRelocationMap (
  OUT MP_RELOCATION_MAP  *AddressMap
  );

/**
  At the beginning of system boot, a 4K-aligned, 4K-size memory (Td mailbox) is
  pre-allocated by host VMM. BSP & APs do the page accept together in that memory
  region.

  After that TDVF is designed to relocate the mailbox to a 4K-aligned, 4K-size
  memory block which is allocated in the ACPI Nvs memory. APs are waken up and
  spin around the relocated mailbox for further command.

  @return   EFI_PHYSICAL_ADDRESS    Address of the relocated mailbox
**/
EFI_PHYSICAL_ADDRESS
EFIAPI
RelocateMailbox (
  VOID
  );

/**
  Alter the MADT when ACPI Table from QEMU is available.

  @param[in]  Event     Event whose notification function is being invoked
  @param[in]  Context   Pointer to the notification function's context
**/
VOID
EFIAPI
AlterAcpiTable (
  IN EFI_EVENT  Event,
  IN VOID       *Context
  );

#endif
