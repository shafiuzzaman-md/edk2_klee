/** @file
  Common Header file for Redfish Configuration Handler UEFI driver
  and DXE driver.

  (C) Copyright 2021 Hewlett Packard Enterprise Development LP<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef EFI_REDFISH_CONFIG_HANDLER_COMMON_H_
#define EFI_REDFISH_CONFIG_HANDLER_COMMON_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"

//
// Libraries
//
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/NetworkPkg/Include/Library/NetLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiDriverEntryPoint.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiLib.h"

//
// Consumed Protocols
//
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/RedfishPkg/Include/Protocol/EdkIIRedfishCredential.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/RedfishPkg/Include/Protocol/EdkIIRedfishConfigHandler.h"

//
// Driver Version
//
#define REDFISH_CONFIG_VERSION  0x00000001

///
///  Internal structure used by Redfish Config DXE driver.
///
typedef struct {
  UINT32                                CallerId;           ///< Caller ID used to indicate Redfish Config Handler
                                                            ///< has been initiated
  EFI_HANDLE                            Image;              ///< Image handle of Redfish Config Driver
  EFI_EVENT                             Event;              ///< Event for the notification of EFI_REDFISH_CONFIG_HANDLER_PROTOCOL
  REDFISH_CONFIG_SERVICE_INFORMATION    RedfishServiceInfo; /// Redfish Service information discovered
} REDFISH_CONFIG_DRIVER_DATA;

/**
  Common code of unloading image for both UEFI/DXE Redfish Configuration drivers.

  @param[in]  ImageHandle       Handle that identifies the image to be unloaded.

  @retval EFI_SUCCESS           The image has been unloaded.

**/
EFI_STATUS
RedfishConfigDriverCommonUnload (
  IN EFI_HANDLE  ImageHandle
  );

/**
  This is the common code for Redfish configuration UEFI and DXE driver
  initialization.

  @param[in]  ImageHandle       The firmware allocated handle for the UEFI image.
  @param[in]  SystemTable       A pointer to the EFI System Table.

  @retval EFI_SUCCESS           The operation completed successfully.
  @retval Others                An unexpected error occurred.
**/
EFI_STATUS
RedfishConfigCommonInit (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  This is the common code to stop EDK2 Redfish feature driver.

  @retval EFI_SUCCESS    All EDK2 Redfish feature drivers are
                         stopped.
  @retval Others         An unexpected error occurred.
**/
EFI_STATUS
RedfishConfigCommonStop (
  VOID
  );

/**
  Callback function executed when a Redfish Config Handler Protocol is installed
  by EDK2 Redfish Feature Drivers.

**/
VOID
RedfishConfigHandlerInitialization (
  VOID
  );

#endif