/**@file

Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>
Portions copyright (c) 2008 - 2010, Apple Inc. All rights reserved.<BR>
Portions copyright (c) 2011 - 2012, ARM Ltd. All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiDxe.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeCoffLib.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeCoffExtraActionLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PrintLib.h"

/**
  Performs additional actions after a PE/COFF image has been loaded and relocated.

  If ImageContext is NULL, then ASSERT().

  @param  ImageContext  Pointer to the image context structure that describes the
                        PE/COFF image that has already been loaded and relocated.

**/
VOID
EFIAPI
PeCoffLoaderRelocateImageExtraAction (
  IN OUT PE_COFF_LOADER_IMAGE_CONTEXT  *ImageContext
  )
{
#ifdef __GNUC__
  if (ImageContext->PdbPointer) {
    DEBUG ((
      DEBUG_LOAD | DEBUG_INFO,
      "add-symbol-file %a 0x%p\n",
      ImageContext->PdbPointer,
      (UINTN)(ImageContext->ImageAddress + ImageContext->SizeOfHeaders)
      ));
    return;
  }
#endif

  DEBUG ((
    DEBUG_LOAD | DEBUG_INFO,
    "Loading driver at 0x%11p EntryPoint=0x%11p\n",
    (VOID *)(UINTN)ImageContext->ImageAddress,
    FUNCTION_ENTRY_POINT (ImageContext->EntryPoint)
    ));
}

/**
  Performs additional actions just before a PE/COFF image is unloaded.  Any resources
  that were allocated by PeCoffLoaderRelocateImageExtraAction() must be freed.

  If ImageContext is NULL, then ASSERT().

  @param  ImageContext  Pointer to the image context structure that describes the
                        PE/COFF image that is being unloaded.

**/
VOID
EFIAPI
PeCoffLoaderUnloadImageExtraAction (
  IN OUT PE_COFF_LOADER_IMAGE_CONTEXT  *ImageContext
  )
{
#ifdef __GNUC__
  if (ImageContext->PdbPointer) {
    DEBUG ((
      DEBUG_LOAD | DEBUG_INFO,
      "remove-symbol-file %a 0x%08x\n",
      ImageContext->PdbPointer,
      (UINTN)(ImageContext->ImageAddress + ImageContext->SizeOfHeaders)
      ));
    return;
  }
#endif

  DEBUG ((
    DEBUG_LOAD | DEBUG_INFO,
    "Unloading driver at 0x%11p\n",
    (VOID *)(UINTN)ImageContext->ImageAddress
    ));
}
