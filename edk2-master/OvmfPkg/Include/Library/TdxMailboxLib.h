/** @file

  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef TDX_MAILBOX_LIB_H_
#define TDX_MAILBOX_LIB_H_

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Uefi/UefiBaseType.h"
#include "edk2-master/MdePkg/Include/Uefi/UefiSpec.h"
#include "edk2-master/MdePkg/Include/Pi/PiPeiCis.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Protocol/DebugSupport.h"

/**
  This function will be called by BSP to get the CPU number.

  @retval   CPU number
**/
UINT32
EFIAPI
GetCpusNum (
  VOID
  );

/**
  Get the address of Td mailbox.
**/
volatile VOID *
EFIAPI
GetTdxMailBox (
  VOID
  );

/**
  This function will be called by BSP to wakeup APs the are spinning on mailbox
  in protected mode

  @param[in] Command          Command to send APs
  @param[in] WakeupVector     If used, address for APs to start executing
  @param[in] WakeArgsX        Args to pass to APs for excuting commands
**/
VOID
EFIAPI
MpSendWakeupCommand (
  IN UINT16  Command,
  IN UINT64  WakeupVector,
  IN UINT64  WakeupArgs1,
  IN UINT64  WakeupArgs2,
  IN UINT64  WakeupArgs3,
  IN UINT64  WakeupArgs4
  );

/**
  BSP wait until all the APs arriving. It means the task triggered by BSP is started.
**/
VOID
EFIAPI
MpSerializeStart (
  VOID
  );

/**
  BSP wait until all the APs arriving. It means the task triggered by BSP is ended.
**/
VOID
EFIAPI
MpSerializeEnd (
  VOID
  );

#endif
