/** @file
  OVMF Platform definitions

  Copyright (C) 2015, Red Hat, Inc.
  Copyright (c) 2014, Gabriel L. Somlo <somlo@cmu.edu>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef __OVMF_PLATFORMS_H__
#define __OVMF_PLATFORMS_H__

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PciLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/Pci22.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/IndustryStandard/Q35MchIch9.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/IndustryStandard/I440FxPiix4.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/IndustryStandard/Bhyve.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/IndustryStandard/Microvm.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/IndustryStandard/CloudHv.h"

//
// OVMF Host Bridge DID Address
//
#define OVMF_HOSTBRIDGE_DID \
  PCI_LIB_ADDRESS (0, 0, 0, PCI_DEVICE_ID_OFFSET)

//
// Values we program into the PM base address registers
//
#define PIIX4_PMBA_VALUE   0xB000
#define ICH9_PMBASE_VALUE  0x0600

//
// Common bits in same-purpose registers
//
#define PMBA_RTE  BIT0

//
// Common IO ports relative to the Power Management Base Address
//
#define ACPI_TIMER_OFFSET  0x8

#endif
