/** @file
  Provides interface to advanced shell functionality for parsing both handle and protocol database.

  Copyright (c) 2011 - 2018, Intel Corporation. All rights reserved.<BR>
  (C) Copyright 2016 Hewlett Packard Enterprise Development LP<BR>
  (C) Copyright 2013-2016 Hewlett-Packard Development Company, L.P.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _UEFI_HANDLE_PARSING_LIB_INTERNAL_H_
#define _UEFI_HANDLE_PARSING_LIB_INTERNAL_H_

#include "edk2-master/MdePkg/Include/Uefi.h"

#include "edk2-master/MdePkg/Include/Guid/FileInfo.h"
#include "edk2-master/MdeModulePkg/Include/Guid/ConsoleInDevice.h"
#include "edk2-master/MdeModulePkg/Include/Guid/ConsoleOutDevice.h"
#include "edk2-master/MdeModulePkg/Include/Guid/StandardErrorDevice.h"
#include "edk2-master/MdePkg/Include/Guid/GlobalVariable.h"
#include "edk2-master/MdePkg/Include/Guid/Gpt.h"
#include "edk2-master/MdePkg/Include/Guid/FileSystemInfo.h"
#include "edk2-master/ShellPkg/Include/Guid/ShellLibHiiGuid.h"

#include "edk2-master/MdePkg/Include/Protocol/SimpleFileSystem.h"
#include "edk2-master/MdePkg/Include/Protocol/LoadedImage.h"
#include "edk2-master/ShellPkg/Include/Protocol/EfiShellInterface.h"
#include "edk2-master/ShellPkg/Include/Protocol/EfiShellEnvironment2.h"
#include "edk2-master/MdePkg/Include/Protocol/Shell.h"
#include "edk2-master/MdePkg/Include/Protocol/ShellParameters.h"
#include "edk2-master/MdePkg/Include/Protocol/DevicePathToText.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverBinding.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverConfiguration2.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverConfiguration.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverDiagnostics2.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverDiagnostics.h"
#include "edk2-master/MdePkg/Include/Protocol/ComponentName2.h"
#include "edk2-master/MdePkg/Include/Protocol/ComponentName.h"
#include "edk2-master/MdePkg/Include/Protocol/PlatformDriverOverride.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/DevicePathUtilities.h"
#include "edk2-master/MdePkg/Include/Protocol/DevicePathFromText.h"
#include "edk2-master/MdePkg/Include/Protocol/BusSpecificDriverOverride.h"
#include "edk2-master/MdePkg/Include/Protocol/PlatformToDriverConfiguration.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverSupportedEfiVersion.h"
#include "edk2-master/MdePkg/Include/Protocol/SimpleTextInEx.h"
#include "edk2-master/MdePkg/Include/Protocol/SimplePointer.h"
#include "edk2-master/MdePkg/Include/Protocol/SerialIo.h"
#include "edk2-master/MdePkg/Include/Protocol/AbsolutePointer.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/GraphicsOutput.h"
#include "edk2-master/MdePkg/Include/Protocol/EdidDiscovered.h"
#include "edk2-master/MdePkg/Include/Protocol/EdidActive.h"
#include "edk2-master/MdePkg/Include/Protocol/EdidOverride.h"
#include "edk2-master/MdePkg/Include/Protocol/LoadFile.h"
#include "edk2-master/MdePkg/Include/Protocol/LoadFile2.h"
#include "edk2-master/MdePkg/Include/Protocol/TapeIo.h"
#include "edk2-master/MdePkg/Include/Protocol/DiskIo.h"
#include "edk2-master/MdePkg/Include/Protocol/BlockIo.h"
#include "edk2-master/MdePkg/Include/Protocol/UnicodeCollation.h"
#include "edk2-master/MdePkg/Include/Protocol/PciRootBridgeIo.h"
#include "edk2-master/MdePkg/Include/Protocol/PciIo.h"
#include "edk2-master/MdePkg/Include/Protocol/ScsiPassThru.h"
#include "edk2-master/MdePkg/Include/Protocol/ScsiPassThruExt.h"
#include "edk2-master/MdePkg/Include/Protocol/ScsiIo.h"
#include "edk2-master/MdePkg/Include/Protocol/IScsiInitiatorName.h"
#include "edk2-master/MdePkg/Include/Protocol/UsbIo.h"
#include "edk2-master/MdePkg/Include/Protocol/UsbHostController.h"
#include "edk2-master/MdePkg/Include/Protocol/Usb2HostController.h"
#include "edk2-master/MdePkg/Include/Protocol/DebugSupport.h"
#include "edk2-master/MdePkg/Include/Protocol/DebugPort.h"
#include "edk2-master/MdePkg/Include/Protocol/Decompress.h"
#include "edk2-master/MdePkg/Include/Protocol/AcpiTable.h"
#include "edk2-master/MdePkg/Include/Protocol/Ebc.h"
#include "edk2-master/MdePkg/Include/Protocol/SimpleNetwork.h"
#include "edk2-master/MdePkg/Include/Protocol/NetworkInterfaceIdentifier.h"
#include "edk2-master/MdePkg/Include/Protocol/PxeBaseCode.h"
#include "edk2-master/MdePkg/Include/Protocol/PxeBaseCodeCallBack.h"
#include "edk2-master/MdePkg/Include/Protocol/Bis.h"
#include "edk2-master/MdePkg/Include/Protocol/ManagedNetwork.h"
#include "edk2-master/MdePkg/Include/Protocol/Arp.h"
#include "edk2-master/MdePkg/Include/Protocol/Dhcp4.h"
#include "edk2-master/MdePkg/Include/Protocol/Tcp4.h"
#include "edk2-master/MdePkg/Include/Protocol/Ip4.h"
#include "edk2-master/MdePkg/Include/Protocol/Ip4Config.h"
#include "edk2-master/MdePkg/Include/Protocol/Ip4Config2.h"
#include "edk2-master/MdePkg/Include/Protocol/Udp4.h"
#include "edk2-master/MdePkg/Include/Protocol/Mtftp4.h"
#include "edk2-master/MdePkg/Include/Protocol/AuthenticationInfo.h"
#include "edk2-master/MdePkg/Include/Protocol/Hash.h"
#include "edk2-master/MdePkg/Include/Protocol/HiiFont.h"
#include "edk2-master/MdePkg/Include/Protocol/HiiString.h"
#include "edk2-master/MdePkg/Include/Protocol/HiiImage.h"
#include "edk2-master/MdePkg/Include/Protocol/HiiDatabase.h"
#include "edk2-master/MdePkg/Include/Protocol/HiiConfigRouting.h"
#include "edk2-master/MdePkg/Include/Protocol/HiiConfigAccess.h"
#include "edk2-master/MdePkg/Include/Protocol/FormBrowser2.h"
#include "edk2-master/MdePkg/Include/Protocol/DeviceIo.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/UgaDraw.h"
#include "edk2-master/MdePkg/Include/Protocol/UgaIo.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverConfiguration.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverConfiguration2.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/DevicePathUtilities.h"
// #include <Protocol/FirmwareVolume.h>
// #include <Protocol/FirmwareVolume2.h>
#include "edk2-master/MdePkg/Include/Protocol/DriverFamilyOverride.h"
#include "edk2-master/MdePkg/Include/Protocol/Pcd.h"
#include "edk2-master/MdePkg/Include/Protocol/TcgService.h"
#include "edk2-master/MdePkg/Include/Protocol/HiiPackageList.h"
#include "edk2-master/MdePkg/Include/Protocol/Ip6.h"
#include "edk2-master/MdePkg/Include/Protocol/Ip6Config.h"
#include "edk2-master/MdePkg/Include/Protocol/Mtftp6.h"
#include "edk2-master/MdePkg/Include/Protocol/Dhcp6.h"
#include "edk2-master/MdePkg/Include/Protocol/Udp6.h"
#include "edk2-master/MdePkg/Include/Protocol/Tcp6.h"
#include "edk2-master/MdePkg/Include/Protocol/VlanConfig.h"
#include "edk2-master/MdePkg/Include/Protocol/Eap.h"
#include "edk2-master/MdePkg/Include/Protocol/EapManagement.h"
#include "edk2-master/MdePkg/Include/Protocol/Ftp4.h"
#include "edk2-master/MdePkg/Include/Protocol/IpSecConfig.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverHealth.h"
#include "edk2-master/MdePkg/Include/Protocol/DeferredImageLoad.h"
#include "edk2-master/MdePkg/Include/Protocol/UserCredential.h"
#include "edk2-master/MdePkg/Include/Protocol/UserManager.h"
#include "edk2-master/MdePkg/Include/Protocol/AtaPassThru.h"
#include "edk2-master/MdePkg/Include/Protocol/FirmwareManagement.h"
#include "edk2-master/MdePkg/Include/Protocol/IpSec.h"
#include "edk2-master/MdePkg/Include/Protocol/Kms.h"
#include "edk2-master/MdePkg/Include/Protocol/BlockIo2.h"
#include "edk2-master/MdePkg/Include/Protocol/StorageSecurityCommand.h"
#include "edk2-master/MdePkg/Include/Protocol/UserCredential2.h"
#include "edk2-master/MdePkg/Include/Protocol/IdeControllerInit.h"
#include "edk2-master/MdePkg/Include/Protocol/DiskIo2.h"
#include "edk2-master/MdePkg/Include/Protocol/AdapterInformation.h"
#include "edk2-master/MdePkg/Include/Protocol/ShellDynamicCommand.h"
#include "edk2-master/MdePkg/Include/Protocol/DiskInfo.h"
#include "edk2-master/MdePkg/Include/Protocol/PartitionInfo.h"

#include "edk2-master/ShellPkg/Include/Library/HandleParsingLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/MdePkg/Include/Library/PrintLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/HiiLib.h"
#include "edk2-master/ShellPkg/Include/Library/ShellLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/SortLib.h"
#include "edk2-master/ShellPkg/Include/Library/ShellCommandLib.h"
#include "edk2-master/MdePkg/Include/Library/PeCoffGetEntryPointLib.h"

#define   EFI_FIRMWARE_IMAGE_DESCRIPTOR_VERSION_V1  1
#define   EFI_FIRMWARE_IMAGE_DESCRIPTOR_VERSION_V2  2

///
/// EFI_FIRMWARE_IMAGE_DESCRIPTOR in UEFI spec < 2.4a
///
typedef struct {
  ///
  /// A unique number identifying the firmware image within the device.  The number is
  /// between 1 and DescriptorCount.
  ///
  UINT8       ImageIndex;
  ///
  /// A unique number identifying the firmware image type.
  ///
  EFI_GUID    ImageTypeId;
  ///
  /// A unique number identifying the firmware image.
  ///
  UINT64      ImageId;
  ///
  /// A pointer to a null-terminated string representing the firmware image name.
  ///
  CHAR16      *ImageIdName;
  ///
  /// Identifies the version of the device firmware. The format is vendor specific and new
  /// version must have a greater value than an old version.
  ///
  UINT32      Version;
  ///
  /// A pointer to a null-terminated string representing the firmware image version name.
  ///
  CHAR16      *VersionName;
  ///
  /// Size of the image in bytes.  If size=0, then only ImageIndex and ImageTypeId are valid.
  ///
  UINTN       Size;
  ///
  /// Image attributes that are supported by this device.  See 'Image Attribute Definitions'
  /// for possible returned values of this parameter.  A value of 1 indicates the attribute is
  /// supported and the current setting value is indicated in AttributesSetting.  A
  /// value of 0 indicates the attribute is not supported and the current setting value in
  /// AttributesSetting is meaningless.
  ///
  UINT64      AttributesSupported;
  ///
  /// Image attributes.  See 'Image Attribute Definitions' for possible returned values of
  /// this parameter.
  ///
  UINT64      AttributesSetting;
  ///
  /// Image compatibilities.  See 'Image Compatibility Definitions' for possible returned
  /// values of this parameter.
  ///
  UINT64      Compatibilities;
} EFI_FIRMWARE_IMAGE_DESCRIPTOR_V1;

///
/// EFI_FIRMWARE_IMAGE_DESCRIPTOR in UEFI spec > 2.4a and < 2.5
///
typedef struct {
  ///
  /// A unique number identifying the firmware image within the device.  The number is
  /// between 1 and DescriptorCount.
  ///
  UINT8       ImageIndex;
  ///
  /// A unique number identifying the firmware image type.
  ///
  EFI_GUID    ImageTypeId;
  ///
  /// A unique number identifying the firmware image.
  ///
  UINT64      ImageId;
  ///
  /// A pointer to a null-terminated string representing the firmware image name.
  ///
  CHAR16      *ImageIdName;
  ///
  /// Identifies the version of the device firmware. The format is vendor specific and new
  /// version must have a greater value than an old version.
  ///
  UINT32      Version;
  ///
  /// A pointer to a null-terminated string representing the firmware image version name.
  ///
  CHAR16      *VersionName;
  ///
  /// Size of the image in bytes.  If size=0, then only ImageIndex and ImageTypeId are valid.
  ///
  UINTN       Size;
  ///
  /// Image attributes that are supported by this device.  See 'Image Attribute Definitions'
  /// for possible returned values of this parameter.  A value of 1 indicates the attribute is
  /// supported and the current setting value is indicated in AttributesSetting.  A
  /// value of 0 indicates the attribute is not supported and the current setting value in
  /// AttributesSetting is meaningless.
  ///
  UINT64      AttributesSupported;
  ///
  /// Image attributes.  See 'Image Attribute Definitions' for possible returned values of
  /// this parameter.
  ///
  UINT64      AttributesSetting;
  ///
  /// Image compatibilities.  See 'Image Compatibility Definitions' for possible returned
  /// values of this parameter.
  ///
  UINT64      Compatibilities;
  ///
  /// Describes the lowest ImageDescriptor version that the device will accept. Only
  /// present in version 2 or higher.
  UINT32      LowestSupportedImageVersion;
} EFI_FIRMWARE_IMAGE_DESCRIPTOR_V2;

typedef struct {
  LIST_ENTRY    Link;
  EFI_HANDLE    TheHandle;
  UINTN         TheIndex;
} HANDLE_LIST;

typedef struct {
  HANDLE_LIST    List;
  UINTN          NextIndex;
} HANDLE_INDEX_LIST;

typedef
CHAR16 *
(EFIAPI *DUMP_PROTOCOL_INFO)(
  IN CONST EFI_HANDLE TheHandle,
  IN CONST BOOLEAN    Verbose
  );

typedef struct _GUID_INFO_BLOCK {
  EFI_STRING_ID         StringId;
  EFI_GUID              *GuidId;
  DUMP_PROTOCOL_INFO    DumpInfo;
} GUID_INFO_BLOCK;

#endif
