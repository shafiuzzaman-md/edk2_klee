/** @file

  Copyright (C) 2016, Linaro Ltd. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __NON_DISCOVERABLE_PCI_DEVICE_IO_H__
#define __NON_DISCOVERABLE_PCI_DEVICE_IO_H__

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiDxe.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiLib.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/Pci.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/ComponentName.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Protocol/NonDiscoverableDevice.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Cpu.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/PciIo.h"

#define NON_DISCOVERABLE_PCI_DEVICE_SIG  SIGNATURE_32 ('P', 'P', 'I', 'D')

#define NON_DISCOVERABLE_PCI_DEVICE_FROM_PCI_IO(PciIoPointer) \
        CR (PciIoPointer, NON_DISCOVERABLE_PCI_DEVICE, PciIo, \
            NON_DISCOVERABLE_PCI_DEVICE_SIG)

#define DEV_SUPPORTED_ATTRIBUTES \
    (EFI_PCI_DEVICE_ENABLE | EFI_PCI_IO_ATTRIBUTE_DUAL_ADDRESS_CYCLE)

#define PCI_ID_VENDOR_UNKNOWN   0xffff
#define PCI_ID_DEVICE_DONTCARE  0x0000

extern EFI_CPU_ARCH_PROTOCOL  *mCpu;

typedef struct {
  //
  // The linked-list next pointer
  //
  LIST_ENTRY    List;
  //
  // The address of the uncached allocation
  //
  VOID          *HostAddress;
  //
  // The number of pages in the allocation
  //
  UINTN         NumPages;
  //
  // The attributes of the allocation
  //
  UINT64        Attributes;
} NON_DISCOVERABLE_DEVICE_UNCACHED_ALLOCATION;

typedef struct {
  UINT32                     Signature;
  //
  // The bound non-discoverable device protocol instance
  //
  NON_DISCOVERABLE_DEVICE    *Device;
  //
  // The exposed PCI I/O protocol instance.
  //
  EFI_PCI_IO_PROTOCOL        PciIo;
  //
  // The emulated PCI config space of the device. Only the minimally required
  // items are assigned.
  //
  PCI_TYPE00                 ConfigSpace;
  //
  // The first virtual BAR to assign based on the resources described
  // by the non-discoverable device.
  //
  UINT32                     BarOffset;
  //
  // The number of virtual BARs we expose based on the number of
  // resources
  //
  UINT32                     BarCount;
  //
  // The PCI I/O attributes for this device
  //
  UINT64                     Attributes;
  //
  // Whether this device has been enabled
  //
  BOOLEAN                    Enabled;
  //
  // Linked list to keep track of uncached allocations performed
  // on behalf of this device
  //
  LIST_ENTRY                 UncachedAllocationList;
  //
  // Unique ID for this device instance: needed so that we can report unique
  // segment/bus/device number for each device instance. Note that this number
  // may change when disconnecting/reconnecting the driver.
  //
  UINTN                      UniqueId;
} NON_DISCOVERABLE_PCI_DEVICE;

/**
  Initialize PciIo Protocol.

  @param  Device      Point to NON_DISCOVERABLE_PCI_DEVICE instance.

**/
VOID
InitializePciIoProtocol (
  NON_DISCOVERABLE_PCI_DEVICE  *Device
  );

extern EFI_COMPONENT_NAME_PROTOCOL   gComponentName;
extern EFI_COMPONENT_NAME2_PROTOCOL  gComponentName2;

#endif
