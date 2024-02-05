/** @file
  Main header for XenPvBlkDxe

  Copyright (C) 2014, Citrix Ltd.

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __EFI_XEN_PV_BLK_DXE_H__
#define __EFI_XEN_PV_BLK_DXE_H__

#include "edk2-master/MdePkg/Include/Uefi.h"

#define xen_mb()   MemoryFence()
#define xen_rmb()  MemoryFence()
#define xen_wmb()  MemoryFence()

//
// Libraries
//
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"

//
// UEFI Driver Model Protocols
//
#include "edk2-master/MdePkg/Include/Protocol/DriverBinding.h"
#include "edk2-master/MdePkg/Include/Protocol/ComponentName2.h"
#include "edk2-master/MdePkg/Include/Protocol/ComponentName.h"

//
// Consumed Protocols
//
#include "edk2-master/OvmfPkg/Include/Protocol/XenBus.h"

//
// Produced Protocols
//
#include "edk2-master/MdePkg/Include/Protocol/BlockIo.h"

//
// Driver Version
//
#define XEN_PV_BLK_DXE_VERSION  0x00000010

//
// Protocol instances
//
extern EFI_DRIVER_BINDING_PROTOCOL   gXenPvBlkDxeDriverBinding;
extern EFI_COMPONENT_NAME2_PROTOCOL  gXenPvBlkDxeComponentName2;
extern EFI_COMPONENT_NAME_PROTOCOL   gXenPvBlkDxeComponentName;

//
// Include files with function prototypes
//
#include "DriverBinding.h"
#include "ComponentName.h"
#include "BlockIo.h"

#endif
