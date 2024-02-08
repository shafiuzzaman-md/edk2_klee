/**@file

Copyright (c) 2006 - 2022, Intel Corporation. All rights reserved.<BR>
(C) Copyright 2020 Hewlett Packard Enterprise Development LP<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent


Module Name:
  WinHost.h

Abstract:
  Include file for Windows Host

**/

#ifndef _HOST_H_
#define _HOST_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/RedfishPkg/PrivateInclude/Crt/stdio.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/RedfishPkg/PrivateInclude/Crt/time.h"
#include "WinInclude.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiPei.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/PeImage.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Guid/FileInfo.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Guid/FileSystemInfo.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Guid/FileSystemVolumeLabelInfo.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmulatorPkg/Include/Ppi/EmuThunk.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Ppi/Reset2.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmulatorPkg/Include/Protocol/EmuThunk.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/SimpleFileSystem.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmulatorPkg/Include/Protocol/EmuBlockIo.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/BlockIo.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmulatorPkg/Include/Protocol/EmuSnp.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeCoffLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmulatorPkg/Include/Library/ThunkPpiList.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmulatorPkg/Include/Library/ThunkProtocolList.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PrintLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeiServicesLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PeCoffExtraActionLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/NetworkPkg/Include/Library/NetLib.h"

#define TEMPORARY_RAM_SIZE  0x20000

typedef struct {
  VOID     *Address;
  UINTN    Size;
} NT_FD_INFO;

typedef struct {
  EFI_PHYSICAL_ADDRESS    Memory;
  UINT64                  Size;
} NT_SYSTEM_MEMORY;

RETURN_STATUS
EFIAPI
SecPeCoffGetEntryPoint (
  IN     VOID  *Pe32Data,
  IN OUT VOID  **EntryPoint
  );

VOID
SecLoadSecCore (
  IN  UINTN  TemporaryRam,
  IN  UINTN  TemporaryRamSize,
  IN  VOID   *BootFirmwareVolumeBase,
  IN  UINTN  BootFirmwareVolumeSize,
  IN  VOID   *SecCorePe32File
  )

/*++

Routine Description:
  This is the service to load the SEC Core from the Firmware Volume

Arguments:
  TemporaryRam            - Memory to use for SEC.
  TemporaryRamSize        - Size of Memory to use for SEC
  BootFirmwareVolumeBase  - Start of the Boot FV
  SecCorePe32File         - SEC Core PE32

Returns:
  Success means control is transferred and thus we should never return

--*/
;

EFI_STATUS
EFIAPI
SecWinNtFdAddress (
  IN     UINTN                 Index,
  IN OUT EFI_PHYSICAL_ADDRESS  *FdBase,
  IN OUT UINT64                *FdSize
  )

/*++

Routine Description:

  TODO: Add function description

Arguments:

  Index   - TODO: add argument description
  FdBase  - TODO: add argument description
  FdSize  - TODO: add argument description

Returns:

  TODO: add return values

--*/
;

EFI_STATUS
EFIAPI
SecImageRead (
  IN     VOID   *FileHandle,
  IN     UINTN  FileOffset,
  IN OUT UINTN  *ReadSize,
  OUT    VOID   *Buffer
  )

/*++

Routine Description:

  TODO: Add function description

Arguments:

  FileHandle  - TODO: add argument description
  FileOffset  - TODO: add argument description
  ReadSize    - TODO: add argument description
  Buffer      - TODO: add argument description

Returns:

  TODO: add return values

--*/
;

CHAR16                            *
AsciiToUnicode (
  IN  CHAR8  *Ascii,
  IN  UINTN  *StrLen OPTIONAL
  )

/*++

Routine Description:

  TODO: Add function description

Arguments:

  Ascii   - TODO: add argument description
  StrLen  - TODO: add argument description

Returns:

  TODO: add return values

--*/
;

UINTN
CountSeparatorsInString (
  IN  CONST CHAR16  *String,
  IN  CHAR16        Separator
  )

/*++

Routine Description:

  TODO: Add function description

Arguments:

  String    - TODO: add argument description
  Separator - TODO: add argument description

Returns:

  TODO: add return values

--*/
;

BOOLEAN
EfiSystemMemoryRange (
  IN  VOID  *MemoryAddress
  );

VOID
SecInitializeThunk (
  VOID
  );

extern EMU_THUNK_PROTOCOL     gEmuThunkProtocol;
extern EMU_IO_THUNK_PROTOCOL  mWinNtWndThunkIo;
extern EMU_IO_THUNK_PROTOCOL  mWinNtFileSystemThunkIo;
extern EMU_IO_THUNK_PROTOCOL  mWinNtBlockIoThunkIo;
extern EMU_IO_THUNK_PROTOCOL  mWinNtSnpThunkIo;

#endif
