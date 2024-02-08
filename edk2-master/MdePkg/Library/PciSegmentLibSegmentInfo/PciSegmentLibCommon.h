/** @file
  Provide common routines used by BasePciSegmentLibSegmentInfo and
  DxeRuntimePciSegmentLibSegmentInfo libraries.

  Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _PCI_SEGMENT_LIB_COMMON_H_
#define _PCI_SEGMENT_LIB_COMMON_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Base.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/PciExpress21.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/IoLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PciSegmentLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PciSegmentInfoLib.h"

/**
  Return the linear address for the physical address.

  @param  Address  The physical address.

  @retval The linear address.
**/
UINTN
PciSegmentLibVirtualAddress (
  IN UINTN  Address
  );

/**
  Internal function that converts PciSegmentLib format address that encodes the PCI Bus, Device,
  Function and Register to ECAM (Enhanced Configuration Access Mechanism) address.

  @param Address     The address that encodes the PCI Bus, Device, Function and
                     Register.
  @param SegmentInfo An array of PCI_SEGMENT_INFO holding the segment information.
  @param Count       Number of segments.

  @retval ECAM address.
**/
UINTN
PciSegmentLibGetEcamAddress (
  IN UINT64                  Address,
  IN CONST PCI_SEGMENT_INFO  *SegmentInfo,
  IN UINTN                   Count
  );

#endif
