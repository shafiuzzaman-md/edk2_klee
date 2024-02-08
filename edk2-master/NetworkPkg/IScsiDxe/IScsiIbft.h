/** @file
  Some extra definitions for iBFT.

Copyright (c) 2004 - 2018, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _ISCSI_IBFT_H_
#define _ISCSI_IBFT_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/Acpi.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/IScsiBootFirmwareTable.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/AcpiTable.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/PciIo.h"

#define IBFT_TABLE_VAR_NAME  L"iBFT"
#define IBFT_MAX_SIZE        4096
#define IBFT_HEAP_OFFSET     2048

#define IBFT_ROUNDUP(size)  NET_ROUNDUP ((size), EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_STRUCTURE_ALIGNMENT)

/**
  Publish and remove the iSCSI Boot Firmware Table according to the iSCSI
  session status.

**/
VOID
IScsiPublishIbft (
  IN VOID
  );

#endif
