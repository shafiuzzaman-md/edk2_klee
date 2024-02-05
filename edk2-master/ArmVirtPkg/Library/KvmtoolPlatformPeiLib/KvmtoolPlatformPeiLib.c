/** @file
  Kvmtool platform PEI library.

  Copyright (c) 2020, ARM Limited. All rights reserved.

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "edk2-master/MdePkg/Include/PiPei.h"

#include "edk2-master/ArmVirtPkg/Include/Guid/Early16550UartBaseAddress.h"
#include "edk2-master/EmbeddedPkg/Include/Guid/FdtHob.h"

#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/HobLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/MdePkg/Include/Library/PeiServicesLib.h"
#include "edk2-master/EmbeddedPkg/Include/libfdt.h"

/** Initialise Platform HOBs

  @retval EFI_SUCCESS             Success.
  @retval EFI_INVALID_PARAMETER   A parameter is invalid.
  @retval EFI_OUT_OF_RESOURCES    Out of resources.
**/
EFI_STATUS
EFIAPI
PlatformPeim (
  VOID
  )
{
  VOID    *Base;
  VOID    *NewBase;
  UINTN   FdtSize;
  UINTN   FdtPages;
  UINT64  *FdtHobData;
  UINT64  *UartHobData;

  Base = (VOID *)(UINTN)PcdGet64 (PcdDeviceTreeInitialBaseAddress);
  if ((Base == NULL) || (fdt_check_header (Base) != 0)) {
    ASSERT (0);
    return EFI_INVALID_PARAMETER;
  }

  FdtSize  = fdt_totalsize (Base) + PcdGet32 (PcdDeviceTreeAllocationPadding);
  FdtPages = EFI_SIZE_TO_PAGES (FdtSize);
  NewBase  = AllocatePages (FdtPages);
  if (NewBase == NULL) {
    ASSERT (0);
    return EFI_OUT_OF_RESOURCES;
  }

  fdt_open_into (Base, NewBase, EFI_PAGES_TO_SIZE (FdtPages));

  FdtHobData = BuildGuidHob (&gFdtHobGuid, sizeof (*FdtHobData));
  if (FdtHobData == NULL) {
    ASSERT (0);
    return EFI_OUT_OF_RESOURCES;
  }

  *FdtHobData = (UINTN)NewBase;

  UartHobData = BuildGuidHob (
                  &gEarly16550UartBaseAddressGuid,
                  sizeof (*UartHobData)
                  );
  if (UartHobData == NULL) {
    ASSERT (0);
    return EFI_OUT_OF_RESOURCES;
  }

  *UartHobData = PcdGet64 (PcdSerialRegisterBase);

  BuildFvHob (PcdGet64 (PcdFvBaseAddress), PcdGet32 (PcdFvSize));

  return EFI_SUCCESS;
}
