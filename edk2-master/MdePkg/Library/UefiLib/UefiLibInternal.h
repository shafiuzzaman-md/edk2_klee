/** @file
  Internal include file for UefiLib.

  Copyright (c) 2007 - 2017, Intel Corporation. All rights reserved.<BR>
   SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef __UEFI_LIB_INTERNAL_H_
#define __UEFI_LIB_INTERNAL_H_

#include "edk2-master/MdePkg/Include/Uefi.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverBinding.h"
#include "edk2-master/MdePkg/Include/Protocol/ComponentName.h"
#include "edk2-master/MdePkg/Include/Protocol/ComponentName2.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverConfiguration.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverConfiguration2.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverDiagnostics.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverDiagnostics2.h"
#include "edk2-master/MdePkg/Include/Protocol/LoadedImage.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/GraphicsOutput.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/UgaDraw.h"
#include "edk2-master/MdePkg/Include/Protocol/HiiFont.h"

#include "edk2-master/MdePkg/Include/Guid/EventGroup.h"
#include "edk2-master/MdePkg/Include/Guid/EventLegacyBios.h"
#include "edk2-master/MdePkg/Include/Guid/GlobalVariable.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/MdePkg/Include/Library/PrintLib.h"
#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"

#endif
