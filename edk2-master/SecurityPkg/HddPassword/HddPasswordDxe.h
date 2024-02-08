/** @file

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  Copyright (c) Microsoft Corporation.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _HDD_PASSWORD_DXE_H_
#define _HDD_PASSWORD_DXE_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/Atapi.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/Pci.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/AtaPassThru.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/PciIo.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/HiiConfigAccess.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Guid/MdeModuleHii.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Guid/EventGroup.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Guid/S3StorageDeviceInitList.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiDriverEntryPoint.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DxeServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Library/UefiHiiServicesLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Library/HiiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PrintLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Library/LockBoxLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/S3BootScriptLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PciLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/CryptoPkg/Include/Library/BaseCryptLib.h"

#include "HddPasswordCommon.h"
#include "HddPasswordHiiDataStruc.h"

//
// This is the generated IFR binary data for each formset defined in VFR.
// This data array is ready to be used as input of HiiAddPackages() to
// create a packagelist (which contains Form packages, String packages, etc).
//
extern UINT8  HddPasswordBin[];

//
// This is the generated String package data for all .UNI files.
// This data array is ready to be used as input of HiiAddPackages() to
// create a packagelist (which contains Form packages, String packages, etc).
//
extern UINT8  HddPasswordDxeStrings[];

#define HDD_PASSWORD_DXE_PRIVATE_SIGNATURE  SIGNATURE_32 ('H', 'D', 'D', 'P')

typedef struct _HDD_PASSWORD_CONFIG_FORM_ENTRY {
  LIST_ENTRY                    Link;
  EFI_HANDLE                    Controller;
  UINTN                         Bus;
  UINTN                         Device;
  UINTN                         Function;
  UINT16                        Port;
  UINT16                        PortMultiplierPort;
  EFI_DEVICE_PATH_PROTOCOL      *DevicePath;
  CHAR16                        HddString[64];
  CHAR8                         Password[HDD_PASSWORD_MAX_LENGTH];
  EFI_STRING_ID                 TitleToken;
  EFI_STRING_ID                 TitleHelpToken;

  HDD_PASSWORD_CONFIG           IfrData;
  EFI_ATA_PASS_THRU_PROTOCOL    *AtaPassThru;
} HDD_PASSWORD_CONFIG_FORM_ENTRY;

typedef struct _HDD_PASSWORD_DXE_PRIVATE_DATA {
  UINTN                             Signature;
  EFI_HANDLE                        DriverHandle;
  EFI_HII_HANDLE                    HiiHandle;
  EFI_HII_CONFIG_ACCESS_PROTOCOL    ConfigAccess;
  HDD_PASSWORD_CONFIG_FORM_ENTRY    *Current;
} HDD_PASSWORD_DXE_PRIVATE_DATA;

#define HDD_PASSWORD_DXE_PRIVATE_FROM_THIS(a)  CR (a, HDD_PASSWORD_DXE_PRIVATE_DATA, ConfigAccess, HDD_PASSWORD_DXE_PRIVATE_SIGNATURE)

#define PASSWORD_SALT_SIZE  32

#define HDD_PASSWORD_REQUEST_VARIABLE_NAME  L"HddPasswordRequest"

//
// It needs to be locked before EndOfDxe.
//
#define HDD_PASSWORD_VARIABLE_NAME  L"HddPassword"

#pragma pack(1)

typedef struct {
  HDD_PASSWORD_DEVICE     Device;
  HDD_PASSWORD_REQUEST    Request;
} HDD_PASSWORD_REQUEST_VARIABLE;

//
// It will be used to validate HDD password when the device is at frozen state.
//
typedef struct {
  HDD_PASSWORD_DEVICE    Device;
  UINT8                  PasswordHash[SHA256_DIGEST_SIZE];
  UINT8                  PasswordSalt[PASSWORD_SALT_SIZE];
} HDD_PASSWORD_VARIABLE;

///
/// HII specific Vendor Device Path definition.
///
typedef struct {
  VENDOR_DEVICE_PATH          VendorDevicePath;
  EFI_DEVICE_PATH_PROTOCOL    End;
} HII_VENDOR_DEVICE_PATH;

#pragma pack()

//
// Time out value for ATA pass through protocol
//
#define ATA_TIMEOUT  EFI_TIMER_PERIOD_SECONDS (3)

typedef struct {
  UINT32                      Address;
  S3_BOOT_SCRIPT_LIB_WIDTH    Width;
} HDD_HC_PCI_REGISTER_SAVE;

#endif
