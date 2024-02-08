/** @file
  Copyright (c) 2014, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _UFS_PCI_HOST_CONTROLLER_PEI_H_
#define _UFS_PCI_HOST_CONTROLLER_PEI_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiPei.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Ppi/MasterBootMode.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Ppi/UfsHostController.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/Pci.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PciLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeiServicesLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"

#define UFS_HC_PEI_SIGNATURE  SIGNATURE_32 ('U', 'F', 'S', 'P')
#define MAX_UFS_HCS           8

typedef struct {
  UINTN                            Signature;
  EDKII_UFS_HOST_CONTROLLER_PPI    UfsHostControllerPpi;
  EFI_PEI_PPI_DESCRIPTOR           PpiList;
  UINTN                            TotalUfsHcs;
  UINTN                            UfsHcPciAddr[MAX_UFS_HCS];
} UFS_HC_PEI_PRIVATE_DATA;

#define UFS_HC_PEI_PRIVATE_DATA_FROM_THIS(a)  CR (a, UFS_HC_PEI_PRIVATE_DATA, UfsHostControllerPpi, UFS_HC_PEI_SIGNATURE)

/**
  Get the MMIO base address of UFS host controller.

  @param[in]  This               The protocol instance pointer.
  @param[in]  ControllerId       The ID of the UFS host controller.
  @param[out] MmioBar            Pointer to the UFS host controller MMIO base address.

  @retval EFI_SUCCESS            The operation succeeds.
  @retval EFI_INVALID_PARAMETER  The parameters are invalid.

**/
EFI_STATUS
EFIAPI
GetUfsHcMmioBar (
  IN     EDKII_UFS_HOST_CONTROLLER_PPI  *This,
  IN     UINT8                          ControllerId,
  OUT UINTN                             *MmioBar
  );

#endif
