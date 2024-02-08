/** @file

  Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Library/LockBoxLib/LockBoxLib.h"

/**
  Allocates a buffer of type EfiACPIMemoryNVS.

  Allocates the number bytes specified by AllocationSize of type
  EfiACPIMemoryNVS and returns a pointer to the allocated buffer.
  If AllocationSize is 0, then a valid buffer of 0 size is
  returned.  If there is not enough memory remaining to satisfy
  the request, then NULL is returned.

  @param  AllocationSize        The number of bytes to allocate.

  @return A pointer to the allocated buffer or NULL if allocation fails.

**/
VOID *
EFIAPI
AllocateAcpiNvsPool (
  IN UINTN  AllocationSize
  )
{
  ASSERT_EFI_ERROR (RETURN_UNSUPPORTED);
  return NULL;
}
