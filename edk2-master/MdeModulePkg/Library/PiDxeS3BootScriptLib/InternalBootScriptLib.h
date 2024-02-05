/** @file
  Support for S3 boot script lib. This file defined some internal macro and internal
  data structure

  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __INTERNAL_BOOT_SCRIPT_LIB__
#define __INTERNAL_BOOT_SCRIPT_LIB__

#include "edk2-master/MdePkg/Include/PiDxe.h"

#include "edk2-master/MdePkg/Include/Guid/EventGroup.h"
#include "edk2-master/MdePkg/Include/Protocol/SmmBase2.h"
#include "edk2-master/MdePkg/Include/Protocol/DxeSmmReadyToLock.h"
#include "edk2-master/MdePkg/Include/Protocol/SmmReadyToLock.h"
#include "edk2-master/MdeModulePkg/Include/Protocol/SmmExitBootServices.h"
#include "edk2-master/MdeModulePkg/Include/Protocol/SmmLegacyBoot.h"

#include "edk2-master/MdePkg/Include/Library/S3BootScriptLib.h"

#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/MdePkg/Include/Library/SmbusLib.h"
#include "edk2-master/MdePkg/Include/Library/IoLib.h"
#include "edk2-master/MdePkg/Include/Library/PciSegmentLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/TimerLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/LockBoxLib.h"

#include "BootScriptInternalFormat.h"

#define MAX_IO_ADDRESS  0xFFFF

//
// Macro to convert a UEFI PCI address + segment to a PCI Segment Library PCI address
//
#define PCI_ADDRESS_ENCODE(S, A)  PCI_SEGMENT_LIB_ADDRESS(\
                                   S, \
                                   ((((UINTN)(A)) & 0xff000000) >> 24), \
                                   ((((UINTN)(A)) & 0x00ff0000) >> 16), \
                                   ((((UINTN)(A)) & 0xff00) >> 8), \
                                   ((RShiftU64 ((A), 32) & 0xfff) | ((A) & 0xff)) \
                                   )

typedef union {
  UINT8 volatile     *Buf;
  UINT8 volatile     *Uint8;
  UINT16 volatile    *Uint16;
  UINT32 volatile    *Uint32;
  UINT64 volatile    *Uint64;
  UINTN volatile     Uint;
} PTR;

// Minimum and maximum length for SMBus bus block protocols defined in SMBus spec 2.0.
//
#define MIN_SMBUS_BLOCK_LEN  1
#define MAX_SMBUS_BLOCK_LEN  32

//
// The boot script private data.
//
typedef struct {
  UINT8      *TableBase;
  UINT32     TableLength;           // Record the actual memory length
  UINT16     TableMemoryPageNumber; // Record the page number Allocated for the table
  BOOLEAN    InSmm;                 // Record if this library is in SMM.
  BOOLEAN    AtRuntime;             // Record if current state is after SmmExitBootServices or SmmLegacyBoot.
  UINT32     BootTimeScriptLength;  // Maintain boot time script length in LockBox after SmmReadyToLock in SMM.
  BOOLEAN    SmmLocked;             // Record if current state is after SmmReadyToLock
  BOOLEAN    BackFromS3;            // Indicate that the system is back from S3.
} SCRIPT_TABLE_PRIVATE_DATA;

typedef
EFI_STATUS
(EFIAPI *DISPATCH_ENTRYPOINT_FUNC)(
  IN EFI_HANDLE ImageHandle,
  IN VOID       *Context
  );

extern SCRIPT_TABLE_PRIVATE_DATA  *mS3BootScriptTablePtr;

//
// Define Opcode for Label which is implementation specific and no standard spec define.
//
#define  S3_BOOT_SCRIPT_LIB_LABEL_OPCODE  0xFE

///
/// The opcode indicate the start of the boot script table.
///
#define S3_BOOT_SCRIPT_LIB_TABLE_OPCODE  0xAA
///
/// The opcode indicate the end of the boot script table.
///
#define S3_BOOT_SCRIPT_LIB_TERMINATE_OPCODE  0xFF

#endif //__INTERNAL_BOOT_SCRIPT_LIB__
