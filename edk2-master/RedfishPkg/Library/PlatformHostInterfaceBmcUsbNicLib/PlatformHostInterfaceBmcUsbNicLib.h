/** @file
  Header file to provide the platform Redfish Host Interface information
  of USB NIC Device exposed by BMC.

  Copyright (C) 2023 Advanced Micro Devices, Inc. All rights reserved.

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef PLATFORM_HOST_INTERFACE_BMC_USB_NIC_LIB_H_
#define PLATFORM_HOST_INTERFACE_BMC_USB_NIC_LIB_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/Ipmi.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/IpmiNetFnApp.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/IpmiNetFnTransport.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/RedfishPkg/Include/IndustryStandard/RedfishHostInterfaceIpmi.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/SmBios.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Library/IpmiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Library/IpmiCommandLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/RedfishPkg/Include/Library/RedfishHostInterfaceLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/RedfishPkg/Include/Library/RedfishDebugLib.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/SimpleNetwork.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/UsbIo.h"

#define BMC_USB_NIC_HOST_INTERFASCE_READINESS_GUID \
    {  \
      0xDD96F5D7, 0x4AE1, 0x4E6C, {0xA1, 0x30, 0xA5, 0xAC, 0x77, 0xDD, 0xE4, 0xA5} \
    }

//
// This is the structure for BMC exposed
// USB NIC information.
//
typedef struct {
  LIST_ENTRY                     NextInstance;              ///< Link to the next instance.
  BOOLEAN                        IsExposedByBmc;            ///< Flag indicates this USB NIC is
                                                            ///< exposed by BMC.
  BOOLEAN                        IsSuppportedHostInterface; ///< This BMC USB NIC is supported
                                                            ///< as Redfish host interface
  EFI_SIMPLE_NETWORK_PROTOCOL    *ThisSnp;                  ///< The SNP instance associated with
                                                            ///< this USB NIC.
  EFI_USB_IO_PROTOCOL            *ThisUsbIo;                ///< The USBIO instance associated with
                                                            ///< this USB NIC.
  UINT16                         UsbVendorId;               ///< USB Vendor ID of this BMC exposed USB NIC.
  UINT16                         UsbProductId;              ///< USB Product ID of this BMC exposed USB NIC.
  UINTN                          MacAddressSize;            ///< HW address size.
  UINT8                          *MacAddress;               ///< HW address.
  UINT8                          IpmiLanChannelNumber;      ///< BMC IPMI Lan Channel number.

  //
  // Below is the infortmation for building SMBIOS type 42.
  //
  UINT8                          IpAssignedType;          ///< Redfish service IP assign type.
  UINT8                          IpAddressFormat;         ///< Redfish service IP version.
  UINT8                          HostIpAddressIpv4[4];    ///< Host IP address.
  UINT8                          RedfishIpAddressIpv4[4]; ///< Redfish service IP address.
  UINT8                          SubnetMaskIpv4[4];       ///< Subnet mask.
  UINT8                          GatewayIpv4[4];          ///< Gateway IP address.
  UINT16                         VLanId;                  ///< VLAN ID.
  BOOLEAN                        CredentialBootstrapping; ///< If Credential bootstrapping is
                                                          ///< supported.
} HOST_INTERFACE_BMC_USB_NIC_INFO;

//
// This is the structure for caching
// BMC IPMI LAN Channel
//
typedef struct {
  LIST_ENTRY         NextInstance;            ///< Link to the next IPMI LAN Channel.
  UINT8              Channel;                 ///< IPMI Channel number.
  EFI_MAC_ADDRESS    MacAddress;              ///< IPMI LAN Channel MAC address.
  UINT8              MacAddressSize;          ///< MAC address size;
} BMC_IPMI_LAN_CHANNEL_INFO;
#endif
