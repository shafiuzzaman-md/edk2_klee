/** @file
  Main file for NULL named library for Profile1 shell command functions.

  Copyright (c) 2010 - 2016, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _UEFI_SHELL_DRIVER1_COMMANDS_LIB_H_
#define _UEFI_SHELL_DRIVER1_COMMANDS_LIB_H_

#include "edk2-master/MdePkg/Include/Uefi.h"

#include "edk2-master/MdePkg/Include/Guid/GlobalVariable.h"
#include "edk2-master/MdeModulePkg/Include/Guid/ConsoleInDevice.h"
#include "edk2-master/MdeModulePkg/Include/Guid/ConsoleOutDevice.h"
#include "edk2-master/ShellPkg/Include/Guid/ShellLibHiiGuid.h"

#include "edk2-master/MdePkg/Include/IndustryStandard/Pci.h"

#include "edk2-master/MdePkg/Include/Pi/PiFirmwareVolume.h"
#include "edk2-master/MdePkg/Include/Pi/PiFirmwareFile.h"
#include "edk2-master/MdePkg/Include/Protocol/FirmwareVolume2.h"

#include "edk2-master/MdePkg/Include/Protocol/Shell.h"
#include "edk2-master/MdePkg/Include/Protocol/ShellParameters.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/DevicePath.h"
#include "edk2-master/MdePkg/Include/Protocol/LoadedImage.h"
#include "edk2-master/MdePkg/Include/Protocol/UnicodeCollation.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverDiagnostics2.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverDiagnostics.h"
#include "edk2-master/MdePkg/Include/Protocol/PlatformDriverOverride.h"
#include "edk2-master/MdePkg/Include/Protocol/BusSpecificDriverOverride.h"
#include "edk2-master/MdePkg/Include/Protocol/PlatformToDriverConfiguration.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverSupportedEfiVersion.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverFamilyOverride.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverHealth.h"
#include "edk2-master/MdePkg/Include/Protocol/PciIo.h"
#include "edk2-master/MdePkg/Include/Protocol/PciRootBridgeIo.h"

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/ShellPkg/Include/Library/ShellCommandLib.h"
#include "edk2-master/ShellPkg/Include/Library/ShellLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/SortLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/HiiLib.h"
#include "edk2-master/MdePkg/Include/Library/FileHandleLib.h"
#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "edk2-master/MdePkg/Include/Library/PrintLib.h"
#include "edk2-master/ShellPkg/Include/Library/HandleParsingLib.h"
#include "edk2-master/MdePkg/Include/Library/PeCoffGetEntryPointLib.h"
#include "edk2-master/ShellPkg/Include/Library/HandleParsingLib.h"

extern        EFI_HII_HANDLE  gShellDriver1HiiHandle;
extern        BOOLEAN         gInReconnect;

/**
  Function for 'connect' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunConnect (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Function for 'devices' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunDevices (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Function for 'openinfo' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunOpenInfo (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Function for 'devtree' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunDevTree (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Function for 'dh' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunDh (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Function for 'disconnect' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunDisconnect (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Function for 'drivers' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunDrivers (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Function for 'drvcfg' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunDrvCfg (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Function for 'drvdiag' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunDrvDiag (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Function for 'reconnect' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunReconnect (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Function for 'unload' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunUnload (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Do a connect from an EFI variable via it's key name.

  @param[in] Key      The name of the EFI Variable.

  @retval EFI_SUCCESS   The operation was successful.
**/
EFI_STATUS
ShellConnectFromDevPaths (
  IN CONST CHAR16  *Key
  );

#endif
