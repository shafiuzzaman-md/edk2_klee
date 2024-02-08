/** @file
  Entry point to the DXE Core.

Copyright (c) 2006 - 2018, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiDxe.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DxeCoreEntryPoint.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"

//
// Cache copy of HobList pointer.
//
VOID  *gHobList = NULL;

/**
  The entry point of PE/COFF Image for the DXE Core.

  This function is the entry point for the DXE Core. This function is required to call
  ProcessModuleEntryPointList() and ProcessModuleEntryPointList() is never expected to return.
  The DXE Core is responsible for calling ProcessLibraryConstructorList() as soon as the EFI
  System Table and the image handle for the DXE Core itself have been established.
  If ProcessModuleEntryPointList() returns, then ASSERT() and halt the system.

  @param  HobStart  The pointer to the beginning of the HOB List passed in from the PEI Phase.

**/
VOID
EFIAPI
_ModuleEntryPoint (
  IN VOID  *HobStart
  )
{
  //
  // Cache a pointer to the HobList
  //
  gHobList = HobStart;

  //
  // Call the DXE Core entry point
  //
  ProcessModuleEntryPointList (HobStart);

  //
  // Should never return
  //
  ASSERT (FALSE);
  CpuDeadLoop ();
}

/**
  Required by the EBC compiler and identical in functionality to _ModuleEntryPoint().

  This function is required to call _ModuleEntryPoint() passing in HobStart.

  @param  HobStart  The pointer to the beginning of the HOB List passed in from the PEI Phase.

**/
VOID
EFIAPI
EfiMain (
  IN VOID  *HobStart
  )
{
  _ModuleEntryPoint (HobStart);
}
