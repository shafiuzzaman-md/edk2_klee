/** @file
  PE/Coff Extra Action library instances, it will report image debug info.

  Copyright (c) 2013 - 2018, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _PE_COFF_EXTRA_ACTION_LIB_H_
#define _PE_COFF_EXTRA_ACTION_LIB_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Base.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeCoffExtraActionLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/IoLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/SourceLevelDebugPkg/Include/ImageDebugSupport.h"

#define DEBUG_LOAD_IMAGE_METHOD_IO_HW_BREAKPOINT  1
#define DEBUG_LOAD_IMAGE_METHOD_SOFT_INT3         2

#define IO_HW_BREAKPOINT_VECTOR_NUM  1
#define SOFT_INT_VECTOR_NUM          3

extern UINTN  AsmInterruptHandle;

/**
  Read IDT entry to check if IDT entries are setup by Debug Agent.

  @param[in]  IdtDescriptor      Pointer to IDT Descriptor.
  @param[in]  InterruptType      Interrupt type.

  @retval  TRUE     IDT entries were setup by Debug Agent.
  @retval  FALSE    IDT entries were not setup by Debug Agent.

**/
BOOLEAN
CheckDebugAgentHandler (
  IN  IA32_DESCRIPTOR  *IdtDescriptor,
  IN  UINTN            InterruptType
  );

/**
  Save IDT entry for INT1 and update it.

  @param[in]  IdtDescriptor      Pointer to IDT Descriptor.
  @param[out] SavedIdtEntry      Original IDT entry returned.

**/
VOID
SaveAndUpdateIdtEntry1 (
  IN  IA32_DESCRIPTOR           *IdtDescriptor,
  OUT IA32_IDT_GATE_DESCRIPTOR  *SavedIdtEntry
  );

/**
  Restore IDT entry for INT1.

  @param[in]  IdtDescriptor      Pointer to IDT Descriptor.
  @param[in]  RestoredIdtEntry   IDT entry to be restored.

**/
VOID
RestoreIdtEntry1 (
  IN  IA32_DESCRIPTOR           *IdtDescriptor,
  IN  IA32_IDT_GATE_DESCRIPTOR  *RestoredIdtEntry
  );

#endif