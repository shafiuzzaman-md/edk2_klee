/** @file
  Early Platform Hook Library instance for 16550 Uart.

  Copyright (c) 2020 - 2023, Arm Ltd. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "edk2-master/MdePkg/Include/Base.h"
#include "edk2-master/MdePkg/Include/Uefi.h"

#include "edk2-master/MdePkg/Include/Pi/PiBootMode.h"
#include "edk2-master/MdePkg/Include/Pi/PiHob.h"

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/HobLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/PlatformHookLib.h"
#include "edk2-master/ArmVirtPkg/Include/Library/FdtSerialPortAddressLib.h"

/** Platform hook to retrieve the 16550 UART base address from the platform
    Device tree and store it in PcdSerialRegisterBase.

  @retval RETURN_SUCCESS            Success.
  @retval RETURN_INVALID_PARAMETER  A parameter was invalid.
  @retval RETURN_NOT_FOUND          Serial port information not found.
  @retval RETURN_PROTOCOL_ERROR     Invalid information in the Device Tree.

**/
RETURN_STATUS
EFIAPI
PlatformHookSerialPortInitialize (
  VOID
  )
{
  RETURN_STATUS  Status;
  VOID           *DeviceTreeBase;
  UINT64         SerialConsoleAddress;

  if (PcdGet64 (PcdSerialRegisterBase) != 0) {
    return RETURN_SUCCESS;
  }

  DeviceTreeBase = (VOID *)(UINTN)PcdGet64 (PcdDeviceTreeInitialBaseAddress);
  if (DeviceTreeBase == NULL) {
    return RETURN_NOT_FOUND;
  }

  Status = FdtSerialGetConsolePort (DeviceTreeBase, &SerialConsoleAddress);
  if (RETURN_ERROR (Status)) {
    return Status;
  }

  return (EFI_STATUS)PcdSet64S (PcdSerialRegisterBase, SerialConsoleAddress);
}
