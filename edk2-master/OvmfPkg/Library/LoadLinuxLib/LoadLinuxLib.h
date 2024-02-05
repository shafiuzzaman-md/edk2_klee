/** @file
  Boot UEFI Linux.

  Copyright (c) 2008 - 2013, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _LOAD_LINUX_LIB_INCLUDED_
#define _LOAD_LINUX_LIB_INCLUDED_

#include "edk2-master/MdePkg/Include/Uefi.h"
#include "edk2-master/OvmfPkg/Include/Library/LoadLinuxLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"

#include "edk2-master/OvmfPkg/Include/IndustryStandard/LinuxBzimage.h"

#include "edk2-master/BaseTools/Source/C/Include/Protocol/GraphicsOutput.h"

VOID
EFIAPI
JumpToKernel (
  VOID  *KernelStart,
  VOID  *KernelBootParams
  );

VOID
EFIAPI
JumpToUefiKernel (
  EFI_HANDLE        ImageHandle,
  EFI_SYSTEM_TABLE  *SystemTable,
  VOID              *KernelBootParams,
  VOID              *KernelStart
  );

VOID
InitLinuxDescriptorTables (
  VOID
  );

VOID
SetLinuxDescriptorTables (
  VOID
  );

#endif
