/** @file

  Copyright (c) 2014 - 2018, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiPei.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/HobLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeiServicesLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/IntelFsp2Pkg/Include/Library/FspCommonLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/IntelFsp2Pkg/Include/FspGlobalData.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/IntelFsp2Pkg/Include/FspEas.h"

/**
  Get system memory resource descriptor by owner.

  @param[in] OwnerGuid   resource owner guid
**/
EFI_HOB_RESOURCE_DESCRIPTOR *
EFIAPI
FspGetResourceDescriptorByOwner (
  IN EFI_GUID  *OwnerGuid
  )
{
  EFI_PEI_HOB_POINTERS  Hob;

  //
  // Get the HOB list for processing
  //
  Hob.Raw = GetHobList ();

  //
  // Collect memory ranges
  //
  while (!END_OF_HOB_LIST (Hob)) {
    if (Hob.Header->HobType == EFI_HOB_TYPE_RESOURCE_DESCRIPTOR) {
      if ((Hob.ResourceDescriptor->ResourceType == EFI_RESOURCE_MEMORY_RESERVED) && \
          (CompareGuid (&Hob.ResourceDescriptor->Owner, OwnerGuid)))
      {
        return Hob.ResourceDescriptor;
      }
    }

    Hob.Raw = GET_NEXT_HOB (Hob);
  }

  return NULL;
}

/**
  Get system memory from HOB.

  @param[in,out] LowMemoryLength   less than 4G memory length
  @param[in,out] HighMemoryLength  greater than 4G memory length
**/
VOID
EFIAPI
FspGetSystemMemorySize (
  IN OUT UINT64  *LowMemoryLength,
  IN OUT UINT64  *HighMemoryLength
  )
{
  EFI_STATUS                   Status;
  EFI_BOOT_MODE                BootMode;
  EFI_RESOURCE_ATTRIBUTE_TYPE  ResourceAttribute;
  EFI_PEI_HOB_POINTERS         Hob;

  ResourceAttribute = (
                       EFI_RESOURCE_ATTRIBUTE_PRESENT |
                       EFI_RESOURCE_ATTRIBUTE_INITIALIZED |
                       EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE |
                       EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE |
                       EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE |
                       EFI_RESOURCE_ATTRIBUTE_WRITE_BACK_CACHEABLE
                       );

  Status = PeiServicesGetBootMode (&BootMode);
  ASSERT_EFI_ERROR (Status);

  if (BootMode != BOOT_ON_S3_RESUME) {
    ResourceAttribute |= EFI_RESOURCE_ATTRIBUTE_TESTED;
  }

  *HighMemoryLength = 0;
  *LowMemoryLength  = SIZE_1MB;
  //
  // Get the HOB list for processing
  //
  Hob.Raw = GetHobList ();

  //
  // Collect memory ranges
  //
  while (!END_OF_HOB_LIST (Hob)) {
    if (Hob.Header->HobType == EFI_HOB_TYPE_RESOURCE_DESCRIPTOR) {
      if ((Hob.ResourceDescriptor->ResourceType == EFI_RESOURCE_SYSTEM_MEMORY) ||
          ((Hob.ResourceDescriptor->ResourceType == EFI_RESOURCE_MEMORY_RESERVED) &&
           (Hob.ResourceDescriptor->ResourceAttribute == ResourceAttribute)))
      {
        //
        // Need memory above 1MB to be collected here
        //
        if ((Hob.ResourceDescriptor->PhysicalStart >= BASE_1MB) &&
            (Hob.ResourceDescriptor->PhysicalStart < (EFI_PHYSICAL_ADDRESS)BASE_4GB))
        {
          *LowMemoryLength += (UINT64)(Hob.ResourceDescriptor->ResourceLength);
        } else if (Hob.ResourceDescriptor->PhysicalStart >= (EFI_PHYSICAL_ADDRESS)BASE_4GB) {
          *HighMemoryLength += (UINT64)(Hob.ResourceDescriptor->ResourceLength);
        }
      }
    }

    Hob.Raw = GET_NEXT_HOB (Hob);
  }
}
