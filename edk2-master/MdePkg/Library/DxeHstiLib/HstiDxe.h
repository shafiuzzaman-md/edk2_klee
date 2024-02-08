/** @file

  Copyright (c) 2015 - 2018, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _HSTI_DXE_H_
#define _HSTI_DXE_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiDxe.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/Hsti.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/AdapterInformation.h"

#define HSTI_AIP_PRIVATE_SIGNATURE  SIGNATURE_32('H', 'S', 'T', 'I')

typedef struct {
  UINT32                              Signature;
  LIST_ENTRY                          Link;
  EFI_ADAPTER_INFORMATION_PROTOCOL    Aip;
  VOID                                *Hsti;
  UINTN                               HstiSize;
  UINTN                               HstiMaxSize;
} HSTI_AIP_PRIVATE_DATA;

#define HSTI_AIP_PRIVATE_DATA_FROM_THIS(a) \
  CR (a, \
      HSTI_AIP_PRIVATE_DATA, \
      Aip, \
      HSTI_AIP_PRIVATE_SIGNATURE \
      )

#define HSTI_DEFAULT_ERROR_STRING_LEN  255

extern EFI_ADAPTER_INFORMATION_PROTOCOL  mAdapterInformationProtocol;

/**
  Return if input HSTI data follows HSTI specification.

  @param HstiData  HSTI data
  @param HstiSize  HSTI size

  @retval TRUE  HSTI data follows HSTI specification.
  @retval FALSE HSTI data does not follow HSTI specification.
**/
BOOLEAN
InternalHstiIsValidTable (
  IN VOID   *HstiData,
  IN UINTN  HstiSize
  );

#endif
