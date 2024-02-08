/*++ @file
  UEFI/PI PEIM to abstract construction of firmware volume in a Unix environment.

Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>
Portions copyright (c) 2010 - 2011, Apple Inc. All rights reserved.
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiPei.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeimEntryPoint.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/HobLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeiServicesLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeiServicesTablePointerLib.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmulatorPkg/Include/Ppi/EmuThunk.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmulatorPkg/Include/Protocol/EmuThunk.h"

EFI_STATUS
EFIAPI
PeiInitialzeThunkPpiToProtocolPei (
  IN       EFI_PEI_FILE_HANDLE  FileHandle,
  IN CONST EFI_PEI_SERVICES     **PeiServices
  )

/*++

Routine Description:

  Perform a call-back into the SEC simulator to get Unix Stuff

Arguments:

  PeiServices - General purpose services available to every PEIM.

Returns:

  None

**/
{
  EFI_STATUS              Status;
  EFI_PEI_PPI_DESCRIPTOR  *PpiDescriptor;
  EMU_THUNK_PPI           *Thunk;
  VOID                    *Ptr;

  DEBUG ((DEBUG_ERROR, "Emu Thunk PEIM Loaded\n"));

  Status = PeiServicesLocatePpi (
             &gEmuThunkPpiGuid,         // GUID
             0,                         // INSTANCE
             &PpiDescriptor,            // EFI_PEI_PPI_DESCRIPTOR
             (VOID **)&Thunk            // PPI
             );
  ASSERT_EFI_ERROR (Status);

  Ptr = Thunk->Thunk ();

  BuildGuidDataHob (
    &gEmuThunkProtocolGuid,              // Guid
    &Ptr,                                // Buffer
    sizeof (VOID *)                      // Sizeof Buffer
    );
  return Status;
}
