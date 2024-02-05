/** @file
  Header file for a generic GOP driver.

Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent


**/

#ifndef _GRAPHICS_OUTPUT_DXE_H_
#define _GRAPHICS_OUTPUT_DXE_H_
#include "edk2-master/MdePkg/Include/PiDxe.h"

#include "edk2-master/MdePkg/Include/IndustryStandard/Pci.h"
#include "edk2-master/MdePkg/Include/IndustryStandard/Acpi.h"
#include "edk2-master/MdePkg/Include/Guid/GraphicsInfoHob.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverBinding.h"
#include "edk2-master/MdePkg/Include/Protocol/PciIo.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/DevicePath.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/GraphicsOutput.h"
#include "edk2-master/MdePkg/Include/Protocol/ComponentName.h"
#include "edk2-master/MdePkg/Include/Protocol/ComponentName2.h"

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/HobLib.h"
#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/FrameBufferBltLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"

#define MAX_PCI_BAR  6

typedef struct {
  UINT32                               Signature;
  EFI_HANDLE                           GraphicsOutputHandle;
  EFI_GRAPHICS_OUTPUT_PROTOCOL         GraphicsOutput;
  EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE    GraphicsOutputMode;
  EFI_DEVICE_PATH_PROTOCOL             *DevicePath;
  EFI_PCI_IO_PROTOCOL                  *PciIo;
  UINT64                               PciAttributes;
  FRAME_BUFFER_CONFIGURE               *FrameBufferBltLibConfigure;
  UINTN                                FrameBufferBltLibConfigureSize;
} GRAPHICS_OUTPUT_PRIVATE_DATA;

#define GRAPHICS_OUTPUT_PRIVATE_DATA_SIGNATURE  SIGNATURE_32 ('g', 'g', 'o', 'p')
#define GRAPHICS_OUTPUT_PRIVATE_FROM_THIS(a) \
  CR(a, GRAPHICS_OUTPUT_PRIVATE_DATA, GraphicsOutput, GRAPHICS_OUTPUT_PRIVATE_DATA_SIGNATURE)

extern EFI_COMPONENT_NAME_PROTOCOL   mGraphicsOutputComponentName;
extern EFI_COMPONENT_NAME2_PROTOCOL  mGraphicsOutputComponentName2;
#endif
