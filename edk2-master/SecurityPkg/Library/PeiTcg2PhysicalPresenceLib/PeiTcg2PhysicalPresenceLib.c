/** @file
  Get TPM 2.0 physical presence information.

  This library will get TPM 2.0 physical presence information.

Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiPei.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/SecurityPkg/Include/Guid/Tcg2PhysicalPresenceData.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Ppi/ReadOnlyVariable2.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeiServicesLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeiServicesTablePointerLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/SecurityPkg/Include/Library/Tcg2PhysicalPresenceLib.h"

/**
  Return TPM2 ManagementFlags set by PP interface.

  @retval    ManagementFlags    TPM2 Management Flags.
**/
UINT32
EFIAPI
Tcg2PhysicalPresenceLibGetManagementFlags (
  VOID
  )
{
  EFI_STATUS                        Status;
  EFI_PEI_READ_ONLY_VARIABLE2_PPI   *VariablePpi;
  EFI_TCG2_PHYSICAL_PRESENCE_FLAGS  PpiFlags;
  UINTN                             DataSize;

  Status = PeiServicesLocatePpi (&gEfiPeiReadOnlyVariable2PpiGuid, 0, NULL, (VOID **)&VariablePpi);
  ASSERT_EFI_ERROR (Status);

  DataSize = sizeof (EFI_TCG2_PHYSICAL_PRESENCE_FLAGS);
  Status   = VariablePpi->GetVariable (
                            VariablePpi,
                            TCG2_PHYSICAL_PRESENCE_FLAGS_VARIABLE,
                            &gEfiTcg2PhysicalPresenceGuid,
                            NULL,
                            &DataSize,
                            &PpiFlags
                            );
  if (EFI_ERROR (Status)) {
    PpiFlags.PPFlags = PcdGet32 (PcdTcg2PhysicalPresenceFlags);
  }

  return PpiFlags.PPFlags;
}
