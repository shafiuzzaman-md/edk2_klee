/** @file
  Header file for the ISA BUS driver.

  Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent


**/

#ifndef _ISA_BUS_H_
#define _ISA_BUS_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/IsaHc.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/BaseTools/Source/C/Include/Protocol/DevicePath.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/ServiceBinding.h"

typedef struct {
  UINT32                          Signature;
  EFI_SERVICE_BINDING_PROTOCOL    ServiceBinding;
  EFI_ISA_HC_PROTOCOL             *IsaHc;       ///< ISA HC protocol produced by the ISA Host Controller driver
  EFI_HANDLE                      IsaHcHandle;  ///< ISA HC handle created by the ISA Host Controller driver
} ISA_BUS_PRIVATE_DATA;
#define ISA_BUS_PRIVATE_DATA_SIGNATURE  SIGNATURE_32 ('_', 'i', 's', 'b')
#define ISA_BUS_PRIVATE_DATA_FROM_THIS(a)  CR (a, ISA_BUS_PRIVATE_DATA, ServiceBinding, ISA_BUS_PRIVATE_DATA_SIGNATURE)

typedef struct {
  UINT32     Signature;
  BOOLEAN    InDestroying;                      ///< Flag to avoid DestroyChild() re-entry.
} ISA_BUS_CHILD_PRIVATE_DATA;
#define ISA_BUS_CHILD_PRIVATE_DATA_SIGNATURE  SIGNATURE_32 ('_', 'i', 's', 'c')

extern EFI_DRIVER_BINDING_PROTOCOL  gIsaBusDriverBinding;

#endif
