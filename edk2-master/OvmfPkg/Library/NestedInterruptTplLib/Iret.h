/** @file
  Force interrupt handler to return with interrupts still disabled.

  Copyright (C) 2022, Fen Systems Ltd.

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef _IRET_H_
#define _IRET_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/DebugSupport.h"

VOID
DisableInterruptsOnIret (
  IN OUT EFI_SYSTEM_CONTEXT  SystemContext
  );

#endif // _IRET_H_
