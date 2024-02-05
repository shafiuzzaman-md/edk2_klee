/*++

Copyright (c) 2004 - 2008, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

Module Name:

  EmuBlockIo.h

Abstract:

  Produce block IO abstractions for real devices on your PC using Posix APIs.
  The configuration of what devices to mount or emulate comes from UNIX
  environment variables. The variables must be visible to the Microsoft*
  Developer Studio for them to work.

  * Other names and brands may be claimed as the property of others.

**/

#ifndef _EMU_BLOCK_IO_H_
#define _EMU_BLOCK_IO_H_

#include "edk2-master/MdePkg/Include/PiDxe.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuIoThunk.h"
#include "edk2-master/MdePkg/Include/Protocol/BlockIo.h"
#include "edk2-master/MdePkg/Include/Protocol/BlockIo2.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuBlockIo.h"

#include "edk2-master/EmulatorPkg/Include/Guid/EmuPhysicalDisk.h"
#include "edk2-master/EmulatorPkg/Include/Guid/EmuVirtualDisk.h"

#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiDriverEntryPoint.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"

//
// Language supported for driverconfiguration protocol
//

#define EMU_BLOCK_IO_PRIVATE_SIGNATURE  SIGNATURE_32 ('E', 'M', 'b', 'k')
typedef struct {
  UINTN                       Signature;
  EMU_IO_THUNK_PROTOCOL       *IoThunk;
  EMU_BLOCK_IO_PROTOCOL       *Io;

  EFI_HANDLE                  EfiHandle;
  EFI_BLOCK_IO_PROTOCOL       BlockIo;
  EFI_BLOCK_IO2_PROTOCOL      BlockIo2;
  EFI_BLOCK_IO_MEDIA          Media;

  EFI_UNICODE_STRING_TABLE    *ControllerNameTable;
} EMU_BLOCK_IO_PRIVATE;

#define EMU_BLOCK_IO_PRIVATE_DATA_FROM_THIS(a) \
         CR(a, EMU_BLOCK_IO_PRIVATE, BlockIo, EMU_BLOCK_IO_PRIVATE_SIGNATURE)

#define EMU_BLOCK_IO2_PRIVATE_DATA_FROM_THIS(a) \
         CR(a, EMU_BLOCK_IO_PRIVATE, BlockIo2, EMU_BLOCK_IO_PRIVATE_SIGNATURE)

//
// Block I/O Global Variables
//
extern EFI_DRIVER_BINDING_PROTOCOL        gEmuBlockIoDriverBinding;
extern EFI_COMPONENT_NAME_PROTOCOL        gEmuBlockIoComponentName;
extern EFI_COMPONENT_NAME2_PROTOCOL       gEmuBlockIoComponentName2;
extern EFI_DRIVER_CONFIGURATION_PROTOCOL  gEmuBlockIoDriverConfiguration;
extern EFI_DRIVER_DIAGNOSTICS_PROTOCOL    gEmuBlockIoDriverDiagnostics;
extern EFI_DRIVER_DIAGNOSTICS2_PROTOCOL   gEmuBlockIoDriverDiagnostics2;

#endif
