/** @file
  The header file of SMM access DXE.

Copyright (c) 2014 - 2021, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef SMM_ACCESS_DRIVER_H_
#define SMM_ACCESS_DRIVER_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiDxe.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/SmmAccess2.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/HobLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Guid/SmramMemoryReserve.h"

#define  SMM_ACCESS_PRIVATE_DATA_SIGNATURE  SIGNATURE_32 ('S', 'M', 'M', 'A')

typedef struct {
  UINTN                       Signature;
  EFI_HANDLE                  Handle;
  EFI_SMM_ACCESS2_PROTOCOL    SmmAccess;
  //
  // Local Data for SMM Access interface goes here
  //
  UINT32                      SmmRegionState;
  UINT32                      NumberRegions;
  EFI_SMRAM_DESCRIPTOR        *SmramDesc;
} SMM_ACCESS_PRIVATE_DATA;

#endif
