/** @file
  This driver installs SMBIOS information for OVMF

  Copyright (c) 2020, Rebecca Cran <rebecca@bsdio.com>
  Copyright (c) 2011, Bei Guan <gbtju85@gmail.com>
  Copyright (c) 2011, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _SMBIOS_PLATFORM_DXE_H_
#define _SMBIOS_PLATFORM_DXE_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiDxe.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Smbios.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/SmBios.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"

/**
  Locates the bhyve SMBIOS data if it exists

  @return SMBIOS_TABLE_ENTRY_POINT   Address of bhyve SMBIOS data

**/
SMBIOS_TABLE_ENTRY_POINT *
GetBhyveSmbiosTables (
  VOID
  );

/**
  Validates the SMBIOS entry point structure

  @param  EntryPointStructure  SMBIOS entry point structure

  @retval TRUE   The entry point structure is valid
  @retval FALSE  The entry point structure is not valid

**/
BOOLEAN
IsEntryPointStructureValid (
  IN SMBIOS_TABLE_ENTRY_POINT  *EntryPointStructure
  );

#endif /* _SMBIOS_PLATFORM_DXE_H_ */