/*++ @file

Copyright (c) 2006, Intel Corporation. All rights reserved.<BR>
Portions copyright (c) 2011, Apple Inc. All rights reserved.
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __EMU_BUS_DRIVER_H__
#define __EMU_BUS_DRIVER_H__

#include "edk2-master/MdePkg/Include/PiDxe.h"

#include "edk2-master/BaseTools/Source/C/Include/Protocol/DevicePath.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuThunk.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuIoThunk.h"

#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiDriverEntryPoint.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"

extern EFI_DRIVER_BINDING_PROTOCOL   gEmuBusDriverBinding;
extern EFI_COMPONENT_NAME_PROTOCOL   gEmuBusDriverComponentName;
extern EFI_COMPONENT_NAME2_PROTOCOL  gEmuBusDriverComponentName2;

//
// Unix Bus Controller Structure
//
#define EMU_BUS_DEVICE_SIGNATURE  SIGNATURE_32 ('L', 'X', 'B', 'D')

typedef struct {
  UINT64                      Signature;
  EFI_UNICODE_STRING_TABLE    *ControllerNameTable;
} EMU_BUS_DEVICE;

//
// Unix Child Device Controller Structure
//
#define EMU_IO_DEVICE_SIGNATURE  SIGNATURE_32 ('L', 'X', 'V', 'D')

typedef struct {
  UINT64                      Signature;
  EFI_HANDLE                  Handle;
  EMU_IO_THUNK_PROTOCOL       EmuIoThunk;
  EFI_DEVICE_PATH_PROTOCOL    *DevicePath;

  //
  // Private data about the parent
  //
  EFI_HANDLE                  ControllerHandle;
  EFI_DEVICE_PATH_PROTOCOL    *ParentDevicePath;

  EFI_UNICODE_STRING_TABLE    *ControllerNameTable;
} EMU_IO_DEVICE;

#define EMU_IO_DEVICE_FROM_THIS(a) \
  CR(a, EMU_IO_DEVICE, EmuIoThunk, EMU_IO_DEVICE_SIGNATURE)

//
// Driver Binding Protocol function prototypes
//
EFI_STATUS
EFIAPI
EmuBusDriverBindingSupported (
  IN EFI_DRIVER_BINDING_PROTOCOL  *This,
  IN EFI_HANDLE                   Handle,
  IN EFI_DEVICE_PATH_PROTOCOL     *RemainingDevicePath
  );

EFI_STATUS
EFIAPI
EmuBusDriverBindingStart (
  IN EFI_DRIVER_BINDING_PROTOCOL  *This,
  IN EFI_HANDLE                   ParentHandle,
  IN EFI_DEVICE_PATH_PROTOCOL     *RemainingDevicePath
  );

EFI_STATUS
EFIAPI
EmuBusDriverBindingStop (
  IN  EFI_DRIVER_BINDING_PROTOCOL  *This,
  IN  EFI_HANDLE                   Handle,
  IN  UINTN                        NumberOfChildren,
  IN  EFI_HANDLE                   *ChildHandleBuffer
  );

//
// Unix Bus Driver private worker functions
//
EFI_DEVICE_PATH_PROTOCOL  *
EmuBusCreateDevicePath (
  IN  EFI_DEVICE_PATH_PROTOCOL  *RootDevicePath,
  IN  EFI_GUID                  *Guid,
  IN  UINT16                    InstanceNumber
  );

#endif
