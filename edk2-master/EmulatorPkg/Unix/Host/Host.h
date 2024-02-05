/*++ @file

Copyright (c) 2006 - 2019, Intel Corporation. All rights reserved.<BR>
Portions copyright (c) 2008 - 2011, Apple Inc. All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _SEC_MAIN_H__
#define _SEC_MAIN_H__

//
// Name mangle to prevent build errors. I.e conflicts between EFI and OS
//
#define NTOHL   _UNIX_EFI_NAME_MANGLE_NTOHL_
#define NTOHLL  _UNIX_EFI_NAME_MANGLE_NTOHLL_
#define HTONL   _UNIX_EFI_NAME_MANGLE_HTONL_
#define HTONLL  _UNIX_EFI_NAME_MANGLE_HTONLL_
#define NTOHS   _UNIX_EFI_NAME_MANGLE_NTOHS_
#define HTONS   _UNIX_EFI_NAME_MANGLE_HTOHS_
#define B0      _UNIX_EFI_NAME_MANGLE_B0_

#include "edk2-master/RedfishPkg/PrivateInclude/Crt/stdio.h"
#include "edk2-master/RedfishPkg/PrivateInclude/Crt/stdlib.h"

#include "edk2-master/RedfishPkg/PrivateInclude/Crt/sys/types.h"
#include <sys/stat.h>
#include <sys/termios.h>
#include "edk2-master/RedfishPkg/PrivateInclude/Crt/sys/time.h"

#if __CYGWIN__
  #include <sys/dirent.h>
#else
  #include <sys/dir.h>
#endif

#include <sys/mman.h>
#include <dlfcn.h>

#include "edk2-master/CryptoPkg/Library/Include/unistd.h"
#include <poll.h>
#include "edk2-master/CryptoPkg/Library/Include/fcntl.h"
#include "edk2-master/RedfishPkg/PrivateInclude/Crt/time.h"
#include <signal.h>
#include "edk2-master/RedfishPkg/PrivateInclude/Crt/errno.h"
#include "edk2-master/RedfishPkg/PrivateInclude/Crt/string.h"
#include "edk2-master/RedfishPkg/PrivateInclude/Crt/stdlib.h"
#include <sys/ioctl.h>
#include <sys/statvfs.h>

#include "edk2-master/CryptoPkg/Library/Include/sys/socket.h"
#include <netdb.h>
#include "edk2-master/CryptoPkg/Library/Include/netinet/in.h"
#include <net/if.h>
#include <ifaddrs.h>

#ifdef __APPLE__
  #include <net/if_dl.h>
  #include <net/bpf.h>
#include "edk2-master/CryptoPkg/Library/Include/sys/param.h"
  #include <sys/mount.h>
  #include <sys/disk.h>
#define _XOPEN_SOURCE
  #ifndef _Bool
#define _Bool  char  // for clang debug
  #endif
#else
  #include <termio.h>
  #include <sys/vfs.h>
  #include <linux/fs.h>
#endif

#include <utime.h>

#undef NTOHL
#undef NTOHLL
#undef HTONL
#undef HTONLL
#undef NTOHS
#undef HTONS
#undef B0
#undef CR3

#include "edk2-master/MdePkg/Include/PiPei.h"
#include "edk2-master/MdePkg/Include/Uefi.h"

#include "edk2-master/MdePkg/Include/Library/PeCoffLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/PrintLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/ReportStatusCodeLib.h"

#include "edk2-master/EmulatorPkg/Include/Library/ThunkPpiList.h"
#include "edk2-master/EmulatorPkg/Include/Library/ThunkProtocolList.h"
#include "edk2-master/MdePkg/Include/Library/PeiServicesLib.h"
#include "edk2-master/MdePkg/Include/Library/PeCoffGetEntryPointLib.h"
#include "edk2-master/EmulatorPkg/Include/Library/EmuMagicPageLib.h"

#include "edk2-master/EmulatorPkg/Include/Ppi/EmuThunk.h"
#include "edk2-master/MdePkg/Include/Ppi/StatusCode.h"

#include "edk2-master/MdePkg/Include/Protocol/SimplePointer.h"
#include "edk2-master/MdePkg/Include/Protocol/SimpleTextIn.h"
#include "edk2-master/MdePkg/Include/Protocol/SimpleTextInEx.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/UgaDraw.h"
#include "edk2-master/MdePkg/Include/Protocol/SimpleFileSystem.h"

#include "edk2-master/EmulatorPkg/Include/Protocol/EmuThunk.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuIoThunk.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuGraphicsWindow.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuThread.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuBlockIo.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuSnp.h"

#include "edk2-master/MdePkg/Include/Guid/FileInfo.h"
#include "edk2-master/MdePkg/Include/Guid/FileSystemInfo.h"
#include "edk2-master/MdePkg/Include/Guid/FileSystemVolumeLabelInfo.h"

#include "Gasket.h"

#define STACK_SIZE  0x20000

typedef struct {
  EFI_PHYSICAL_ADDRESS    Address;
  UINT64                  Size;
} EMU_FD_INFO;

typedef struct {
  EFI_PHYSICAL_ADDRESS    Memory;
  UINT64                  Size;
} EMU_SYSTEM_MEMORY;

#define MAX_IMAGE_CONTEXT_TO_MOD_HANDLE_ARRAY_SIZE  0x100

typedef struct {
  PE_COFF_LOADER_IMAGE_CONTEXT    *ImageContext;
  VOID                            *ModHandle;
} IMAGE_CONTEXT_TO_MOD_HANDLE;

EFI_STATUS
EFIAPI
SecUnixPeiLoadFile (
  VOID                  *Pe32Data,
  EFI_PHYSICAL_ADDRESS  *ImageAddress,
  UINT64                *ImageSize,
  EFI_PHYSICAL_ADDRESS  *EntryPoint
  );

int
main (
  IN  int   Argc,
  IN  char  **Argv,
  IN  char  **Envp
  );

VOID
SecLoadFromCore (
  IN  UINTN  LargestRegion,
  IN  UINTN  LargestRegionSize,
  IN  UINTN  BootFirmwareVolumeBase,
  IN  VOID   *PeiCoreFile
  );

EFI_STATUS
SecLoadFile (
  IN  VOID                  *Pe32Data,
  IN  EFI_PHYSICAL_ADDRESS  *ImageAddress,
  IN  UINT64                *ImageSize,
  IN  EFI_PHYSICAL_ADDRESS  *EntryPoint
  );

EFI_STATUS
SecFfsFindPeiCore (
  IN  EFI_FIRMWARE_VOLUME_HEADER  *FwVolHeader,
  OUT VOID                        **Pe32Data
  );

EFI_STATUS
SecFfsFindNextFile (
  IN EFI_FV_FILETYPE             SearchType,
  IN EFI_FIRMWARE_VOLUME_HEADER  *FwVolHeader,
  IN OUT EFI_FFS_FILE_HEADER     **FileHeader
  );

EFI_STATUS
SecFfsFindSectionData (
  IN EFI_SECTION_TYPE     SectionType,
  IN EFI_FFS_FILE_HEADER  *FfsFileHeader,
  IN OUT VOID             **SectionData
  );

EFI_STATUS
EFIAPI
SecUnixPeCoffLoaderLoadAsDll (
  IN CHAR8  *PdbFileName,
  IN VOID   **ImageEntryPoint,
  OUT VOID  **ModHandle
  );

EFI_STATUS
EFIAPI
SecUnixPeCoffLoaderFreeLibrary (
  OUT VOID  *ModHandle
  );

EFI_STATUS
SecUnixFdAddress (
  IN     UINTN                 Index,
  IN OUT EFI_PHYSICAL_ADDRESS  *FdBase,
  IN OUT UINT64                *FdSize,
  IN OUT EFI_PHYSICAL_ADDRESS  *FixUp
  )
;

EFI_STATUS
EFIAPI
GasketSecUnixFdAddress (
  IN     UINTN                 Index,
  IN OUT EFI_PHYSICAL_ADDRESS  *FdBase,
  IN OUT UINT64                *FdSize,
  IN OUT EFI_PHYSICAL_ADDRESS  *FixUp
  )
;

EFI_STATUS
GetImageReadFunction (
  IN PE_COFF_LOADER_IMAGE_CONTEXT  *ImageContext,
  IN EFI_PHYSICAL_ADDRESS          *TopOfMemory
  );

EFI_STATUS
EFIAPI
SecImageRead (
  IN     VOID   *FileHandle,
  IN     UINTN  FileOffset,
  IN OUT UINTN  *ReadSize,
  OUT    VOID   *Buffer
  );

CHAR16                            *
AsciiToUnicode (
  IN  CHAR8  *Ascii,
  IN  UINTN  *StrLen OPTIONAL
  );

UINTN
CountSeparatorsInString (
  IN  const CHAR16  *String,
  IN  CHAR16        Separator
  );

EFI_STATUS
EFIAPI
SecTemporaryRamSupport (
  IN CONST EFI_PEI_SERVICES  **PeiServices,
  IN EFI_PHYSICAL_ADDRESS    TemporaryMemoryBase,
  IN EFI_PHYSICAL_ADDRESS    PermanentMemoryBase,
  IN UINTN                   CopySize
  );

EFI_STATUS
EFIAPI
GasketSecTemporaryRamSupport (
  IN CONST EFI_PEI_SERVICES  **PeiServices,
  IN EFI_PHYSICAL_ADDRESS    TemporaryMemoryBase,
  IN EFI_PHYSICAL_ADDRESS    PermanentMemoryBase,
  IN UINTN                   CopySize
  );

RETURN_STATUS
EFIAPI
SecPeCoffGetEntryPoint (
  IN     VOID  *Pe32Data,
  IN OUT VOID  **EntryPoint
  );

VOID
EFIAPI
SecPeCoffRelocateImageExtraAction (
  IN OUT PE_COFF_LOADER_IMAGE_CONTEXT  *ImageContext
  );

VOID
EFIAPI
SecPeCoffLoaderUnloadImageExtraAction (
  IN OUT PE_COFF_LOADER_IMAGE_CONTEXT  *ImageContext
  );

VOID
PeiSwitchStacks (
  IN      SWITCH_STACK_ENTRY_POINT  EntryPoint,
  IN      VOID                      *Context1   OPTIONAL,
  IN      VOID                      *Context2   OPTIONAL,
  IN      VOID                      *NewStack
  );

VOID
SecInitThunkProtocol (
  VOID
  );

EFI_PHYSICAL_ADDRESS *
MapMemory (
  INTN    fd,
  UINT64  length,
  INTN    prot,
  INTN    flags
  );

EFI_STATUS
MapFile (
  IN  CHAR8                     *FileName,
  IN OUT  EFI_PHYSICAL_ADDRESS  *BaseAddress,
  OUT UINT64                    *Length
  );

EFI_STATUS
MapFd0 (
  IN  CHAR8                     *FileName,
  IN OUT  EFI_PHYSICAL_ADDRESS  *BaseAddress,
  OUT UINT64                    *Length
  );

BOOLEAN
EfiSystemMemoryRange (
  IN  VOID  *MemoryAddress
  );

VOID
SecSleep (
  UINT64  Nanoseconds
  );

VOID
SecEnableInterrupt (
  VOID
  );

VOID
SecDisableInterrupt (
  VOID
  );

BOOLEAN
SecInterruptEanbled (
  VOID
  );

extern EMU_THUNK_PROTOCOL     gEmuThunkProtocol;
extern EMU_IO_THUNK_PROTOCOL  gX11ThunkIo;
extern EMU_IO_THUNK_PROTOCOL  gPosixFileSystemThunkIo;
extern EMU_IO_THUNK_PROTOCOL  gPthreadThunkIo;
extern EMU_IO_THUNK_PROTOCOL  gBlockIoThunkIo;
extern EMU_IO_THUNK_PROTOCOL  gSnpThunkIo;

#endif
