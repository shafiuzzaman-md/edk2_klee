/** @file
  Header file for USB Network Control Model driver

  Copyright (c) 2023, American Megatrends International LLC. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef USB_CDC_NCM_H_
#define USB_CDC_NCM_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiDriverEntryPoint.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiUsbLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/UsbIo.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Protocol/UsbEthernetProtocol.h"

typedef struct {
  UINTN                          Signature;
  EDKII_USB_ETHERNET_PROTOCOL    UsbEth;
  EFI_HANDLE                     UsbCdcDataHandle;
  EFI_USB_IO_PROTOCOL            *UsbIo;
  EFI_USB_CONFIG_DESCRIPTOR      *Config;
  UINT8                          NumOfInterface;
  UINT8                          BulkInEndpoint;
  UINT8                          BulkOutEndpoint;
  UINT8                          InterruptEndpoint;
  EFI_MAC_ADDRESS                MacAddress;
  UINT16                         BulkOutSequence;
  UINT8                          *BulkBuffer;
  UINT8                          TotalDatagram;
  UINT8                          NowDatagram;
} USB_ETHERNET_DRIVER;

#define USB_NCM_DRIVER_VERSION         1
#define USB_ETHERNET_BULK_TIMEOUT      1
#define USB_ETHERNET_TRANSFER_TIMEOUT  200
#define USB_NCM_MAX_NTB_SIZE           0xFFFF
#define USB_ETHERNET_FRAME_SIZE        0x5F2  // MAX ethernet frame size

// Defined in USB NCM 1.0 spec., section 3.2 and 3.3
#define USB_NCM_NTH_SIGN_16      0x484D434E
#define USB_NCM_NDP_SIGN_16      0x304D434E
#define USB_NCM_NDP_SIGN_16_CRC  0x314D434E
#define USB_NCM_NTH_LENGTH       0x000C
#define USB_NCM_NDP_LENGTH       0x0010// at least 16

// USB NCM Transfer header structure - UINT16
typedef struct {
  UINT32    Signature;
  UINT16    HeaderLength;
  UINT16    Sequence;
  UINT16    BlockLength;
  UINT16    NdpIndex;
} USB_NCM_TRANSFER_HEADER_16;

// USB NCM Datagram pointer structure - UINT16
typedef struct {
  UINT32    Signature;
  UINT16    Length;
  UINT16    NextNdpIndex;
} USB_NCM_DATAGRAM_POINTER_16;

// USB NCM Datagram structure
typedef struct {
  UINT16    DatagramIndex;
  UINT16    DatagramLength;
} USB_NCM_DATA_GRAM;

#define USB_ETHERNET_SIGNATURE  SIGNATURE_32('u', 'e', 't', 'h')
#define USB_ETHERNET_DEV_FROM_THIS(a)  CR (a, USB_ETHERNET_DRIVER, UsbEth, USB_ETHERNET_SIGNATURE)

typedef struct {
  UINT16    Src;
  UINT16    Dst;
} BIT_MAP;

extern EFI_COMPONENT_NAME2_PROTOCOL  gUsbNcmComponentName2;

EFI_STATUS
EFIAPI
UsbNcmDriverSupported (
  IN EFI_DRIVER_BINDING_PROTOCOL  *This,
  IN EFI_HANDLE                   ControllerHandle,
  IN EFI_DEVICE_PATH_PROTOCOL     *RemainingDevicePath
  );

EFI_STATUS
EFIAPI
UsbNcmDriverStart (
  IN EFI_DRIVER_BINDING_PROTOCOL  *This,
  IN EFI_HANDLE                   ControllerHandle,
  IN EFI_DEVICE_PATH_PROTOCOL     *RemainingDevicePath
  );

EFI_STATUS
EFIAPI
UsbNcmDriverStop (
  IN  EFI_DRIVER_BINDING_PROTOCOL  *This,
  IN  EFI_HANDLE                   ControllerHandle,
  IN  UINTN                        NumberOfChildren,
  IN  EFI_HANDLE                   *ChildHandleBuffer
  );

EFI_STATUS
LoadAllDescriptor (
  IN  EFI_USB_IO_PROTOCOL        *UsbIo,
  OUT EFI_USB_CONFIG_DESCRIPTOR  **ConfigDesc
  );

BOOLEAN
NextDescriptor (
  IN EFI_USB_CONFIG_DESCRIPTOR  *Desc,
  IN OUT UINTN                  *Offset
  );

EFI_STATUS
GetFunctionalDescriptor (
  IN  EFI_USB_CONFIG_DESCRIPTOR  *Config,
  IN  UINT8                      FunDescriptorType,
  OUT VOID                       *DataBuffer
  );

VOID
GetEndpoint (
  IN      EFI_USB_IO_PROTOCOL  *UsbIo,
  IN OUT  USB_ETHERNET_DRIVER  *UsbEthDriver
  );

EFI_STATUS
EFIAPI
UsbEthNcmReceive (
  IN     PXE_CDB                      *Cdb,
  IN     EDKII_USB_ETHERNET_PROTOCOL  *This,
  IN OUT VOID                         *Packet,
  IN OUT UINTN                        *PacketLength
  );

EFI_STATUS
EFIAPI
UsbEthNcmTransmit (
  IN      PXE_CDB                      *Cdb,
  IN      EDKII_USB_ETHERNET_PROTOCOL  *This,
  IN      VOID                         *Packet,
  IN OUT  UINTN                        *PacketLength
  );

EFI_STATUS
EFIAPI
UsbEthNcmInterrupt (
  IN EDKII_USB_ETHERNET_PROTOCOL  *This,
  IN BOOLEAN                      IsNewTransfer,
  IN UINTN                        PollingInterval,
  IN EFI_USB_DEVICE_REQUEST       *Request
  );

EFI_STATUS
EFIAPI
InterruptCallback (
  IN  VOID    *Data,
  IN  UINTN   DataLength,
  IN  VOID    *Context,
  IN  UINT32  Status
  );

EFI_STATUS
EFIAPI
GetUsbEthMacAddress (
  IN  EDKII_USB_ETHERNET_PROTOCOL  *This,
  OUT EFI_MAC_ADDRESS              *MacAddress
  );

EFI_STATUS
EFIAPI
UsbEthNcmBulkSize (
  IN  EDKII_USB_ETHERNET_PROTOCOL  *This,
  OUT UINTN                        *BulkSize
  );

EFI_STATUS
EFIAPI
GetUsbHeaderFunDescriptor (
  IN  EDKII_USB_ETHERNET_PROTOCOL  *This,
  OUT USB_HEADER_FUN_DESCRIPTOR    *UsbHeaderFunDescriptor
  );

EFI_STATUS
EFIAPI
GetUsbUnionFunDescriptor (
  IN  EDKII_USB_ETHERNET_PROTOCOL  *This,
  OUT USB_UNION_FUN_DESCRIPTOR     *UsbUnionFunDescriptor
  );

EFI_STATUS
EFIAPI
GetUsbEthFunDescriptor (
  IN  EDKII_USB_ETHERNET_PROTOCOL  *This,
  OUT USB_ETHERNET_FUN_DESCRIPTOR  *UsbEthFunDescriptor
  );

EFI_STATUS
EFIAPI
SetUsbEthMcastFilter (
  IN EDKII_USB_ETHERNET_PROTOCOL  *This,
  IN UINT16                       Value,
  IN VOID                         *McastAddr
  );

EFI_STATUS
EFIAPI
SetUsbEthPowerFilter (
  IN EDKII_USB_ETHERNET_PROTOCOL  *This,
  IN UINT16                       Value,
  IN UINT16                       Length,
  IN VOID                         *PatternFilter
  );

EFI_STATUS
EFIAPI
GetUsbEthPowerFilter (
  IN  EDKII_USB_ETHERNET_PROTOCOL  *This,
  IN  UINT16                       Value,
  OUT BOOLEAN                      *PatternActive
  );

EFI_STATUS
EFIAPI
SetUsbEthPacketFilter (
  IN EDKII_USB_ETHERNET_PROTOCOL  *This,
  IN UINT16                       Value
  );

EFI_STATUS
EFIAPI
GetUsbEthStatistic (
  IN  EDKII_USB_ETHERNET_PROTOCOL  *This,
  IN  UINT16                       FeatureSelector,
  OUT VOID                         *Statistic
  );

#endif
