/** @file
  SMBASE relocation for hot-plugged CPUs.

  Copyright (c) 2020, Red Hat, Inc.

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef SMBASE_H_
#define SMBASE_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi/UefiBaseType.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi/UefiSpec.h"

#include "ApicId.h"            // APIC_ID

EFI_STATUS
SmbaseAllocatePostSmmPen (
  OUT UINT32                   *PenAddress,
  IN  CONST EFI_BOOT_SERVICES  *BootServices
  );

VOID
SmbaseReinstallPostSmmPen (
  IN UINT32  PenAddress
  );

VOID
SmbaseReleasePostSmmPen (
  IN UINT32                   PenAddress,
  IN CONST EFI_BOOT_SERVICES  *BootServices
  );

VOID
SmbaseInstallFirstSmiHandler (
  VOID
  );

EFI_STATUS
SmbaseRelocate (
  IN APIC_ID  ApicId,
  IN UINTN    Smbase,
  IN UINT32   PenAddress
  );

#endif // SMBASE_H_
