/** @file
  Function declaration and internal data for XenBusDxe.

  Copyright (C) 2014, Citrix Ltd.

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __EFI_XENBUS_DXE_H__
#define __EFI_XENBUS_DXE_H__

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"

//
// Libraries
//
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PcdLib.h"

//
// UEFI Driver Model Protocols
//
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/DriverBinding.h"

//
// Consumed Protocols
//
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/Protocol/XenIo.h"

//
// Produced Protocols
//
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/Protocol/XenBus.h"

//
// Driver Version
//
#define XENBUS_DXE_VERSION  0x00000010

//
// Protocol instances
//
extern EFI_DRIVER_BINDING_PROTOCOL   gXenBusDxeDriverBinding;
extern EFI_COMPONENT_NAME2_PROTOCOL  gXenBusDxeComponentName2;
extern EFI_COMPONENT_NAME_PROTOCOL   gXenBusDxeComponentName;

//
// Include files with function prototypes
//
#include "DriverBinding.h"
#include "ComponentName.h"

//
// Other stuff
//
#include <IndustryStandard/Xen/xen.h>

typedef struct _XENBUS_DEVICE_PATH  XENBUS_DEVICE_PATH;
typedef struct _XENBUS_DEVICE       XENBUS_DEVICE;

// Have the state of the driver.
#define XENBUS_DEVICE_SIGNATURE  SIGNATURE_32 ('X','B','s','t')
struct _XENBUS_DEVICE {
  UINT32                         Signature;
  EFI_DRIVER_BINDING_PROTOCOL    *This;
  EFI_HANDLE                     ControllerHandle;
  XENIO_PROTOCOL                 *XenIo;
  EFI_EVENT                      ExitBootEvent;
  EFI_DEVICE_PATH_PROTOCOL       *DevicePath;
  LIST_ENTRY                     ChildList;

  shared_info_t                  *SharedInfo;
};

// There is one of this struct allocated for every child.
#define XENBUS_PRIVATE_DATA_SIGNATURE  SIGNATURE_32 ('X', 'B', 'p', 'd')
typedef struct {
  UINTN                 Signature;
  LIST_ENTRY            Link;
  EFI_HANDLE            Handle;
  XENBUS_PROTOCOL       XenBusIo;
  XENBUS_DEVICE         *Dev;
  XENBUS_DEVICE_PATH    *DevicePath;
} XENBUS_PRIVATE_DATA;

#define XENBUS_PRIVATE_DATA_FROM_THIS(a) \
  CR (a, XENBUS_PRIVATE_DATA, XenBusIo, XENBUS_PRIVATE_DATA_SIGNATURE)
#define XENBUS_PRIVATE_DATA_FROM_LINK(a) \
  CR (a, XENBUS_PRIVATE_DATA, Link, XENBUS_PRIVATE_DATA_SIGNATURE)

/*
 * Helpers
 */

/**
  Atomically test and clear a bit.

  @param Bit      Bit index to test in *Address
  @param Address  The Address to the buffer that contain the bit to test.

  @return Value of the Bit before it was cleared.
**/
INT32
EFIAPI
TestAndClearBit (
  IN INT32  Bit,
  IN VOID   *Address
  );

CHAR8 *
AsciiStrDup (
  IN CONST CHAR8  *Str
  );

#endif
