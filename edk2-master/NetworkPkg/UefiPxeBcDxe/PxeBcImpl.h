/** @file
  This EFI_PXE_BASE_CODE_PROTOCOL and EFI_LOAD_FILE_PROTOCOL.
  interfaces declaration.

  Copyright (c) 2007 - 2019, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __EFI_PXEBC_IMPL_H__
#define __EFI_PXEBC_IMPL_H__

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Guid/SmBios.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/SmBios.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/Dhcp.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/NetworkInterfaceIdentifier.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Arp.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Ip4.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Ip4Config2.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Ip6.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Ip6Config.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Udp4.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Udp6.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Dhcp4.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Dhcp6.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Dns6.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Mtftp4.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Mtftp6.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/PxeBaseCode.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/LoadFile.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/PxeBaseCodeCallBack.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/ServiceBinding.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/DriverBinding.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/AdapterInformation.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiDriverEntryPoint.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/NetworkPkg/Include/Library/NetLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/NetworkPkg/Include/Library/DpcLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PcdLib.h"

typedef struct _PXEBC_PRIVATE_DATA      PXEBC_PRIVATE_DATA;
typedef struct _PXEBC_PRIVATE_PROTOCOL  PXEBC_PRIVATE_PROTOCOL;
typedef struct _PXEBC_VIRTUAL_NIC       PXEBC_VIRTUAL_NIC;

#include "PxeBcDriver.h"
#include "PxeBcDhcp4.h"
#include "PxeBcDhcp6.h"
#include "PxeBcMtftp.h"
#include "PxeBcBoot.h"
#include "PxeBcSupport.h"

#define PXEBC_DEFAULT_HOPLIMIT      64
#define PXEBC_DEFAULT_LIFETIME      50000      // 50 ms, unit is microsecond
#define PXEBC_UDP_TIMEOUT           30000000   // 3 seconds, unit is 100nanosecond
#define PXEBC_DAD_ADDITIONAL_DELAY  30000000   // 3 seconds
#define PXEBC_MTFTP_TIMEOUT         4
#define PXEBC_MTFTP_RETRIES         6
#define PXEBC_DHCP_RETRIES          4          // refers to mPxeDhcpTimeout, also by PXE2.1 spec.
#define PXEBC_MENU_MAX_NUM          24
#define PXEBC_OFFER_MAX_NUM         16

#define PXEBC_CHECK_MEDIA_WAITING_TIME  EFI_TIMER_PERIOD_SECONDS(20)

#define PXEBC_PRIVATE_DATA_SIGNATURE  SIGNATURE_32 ('P', 'X', 'E', 'P')
#define PXEBC_VIRTUAL_NIC_SIGNATURE   SIGNATURE_32 ('P', 'X', 'E', 'V')
#define PXEBC_PRIVATE_DATA_FROM_PXEBC(a)    CR (a, PXEBC_PRIVATE_DATA, PxeBc, PXEBC_PRIVATE_DATA_SIGNATURE)
#define PXEBC_PRIVATE_DATA_FROM_ID(a)       CR (a, PXEBC_PRIVATE_DATA, Id, PXEBC_PRIVATE_DATA_SIGNATURE)
#define PXEBC_VIRTUAL_NIC_FROM_LOADFILE(a)  CR (a, PXEBC_VIRTUAL_NIC, LoadFile, PXEBC_VIRTUAL_NIC_SIGNATURE)

#define PXE_ENABLED   0x01
#define PXE_DISABLED  0x00

typedef union {
  PXEBC_DHCP4_PACKET_CACHE    Dhcp4;
  PXEBC_DHCP6_PACKET_CACHE    Dhcp6;
} PXEBC_DHCP_PACKET_CACHE;

struct _PXEBC_PRIVATE_PROTOCOL {
  UINT64    Reserved;
};

struct _PXEBC_VIRTUAL_NIC {
  UINT32                      Signature;
  EFI_HANDLE                  Controller;
  EFI_LOAD_FILE_PROTOCOL      LoadFile;
  EFI_DEVICE_PATH_PROTOCOL    *DevicePath;
  PXEBC_PRIVATE_DATA          *Private;
};

struct _PXEBC_PRIVATE_DATA {
  UINT32                                       Signature;
  EFI_HANDLE                                   Controller;
  EFI_HANDLE                                   Image;

  PXEBC_PRIVATE_PROTOCOL                       Id;
  EFI_SIMPLE_NETWORK_PROTOCOL                  *Snp;

  PXEBC_VIRTUAL_NIC                            *Ip4Nic;
  PXEBC_VIRTUAL_NIC                            *Ip6Nic;

  EFI_HANDLE                                   ArpChild;
  EFI_HANDLE                                   Ip4Child;
  EFI_HANDLE                                   Dhcp4Child;
  EFI_HANDLE                                   Mtftp4Child;
  EFI_HANDLE                                   Udp4ReadChild;
  EFI_HANDLE                                   Udp4WriteChild;

  EFI_ARP_PROTOCOL                             *Arp;
  EFI_IP4_PROTOCOL                             *Ip4;
  EFI_IP4_CONFIG2_PROTOCOL                     *Ip4Config2;
  EFI_DHCP4_PROTOCOL                           *Dhcp4;
  EFI_MTFTP4_PROTOCOL                          *Mtftp4;
  EFI_UDP4_PROTOCOL                            *Udp4Read;
  EFI_UDP4_PROTOCOL                            *Udp4Write;

  EFI_HANDLE                                   Ip6Child;
  EFI_HANDLE                                   Dhcp6Child;
  EFI_HANDLE                                   Mtftp6Child;
  EFI_HANDLE                                   Udp6ReadChild;
  EFI_HANDLE                                   Udp6WriteChild;

  EFI_IP6_PROTOCOL                             *Ip6;
  EFI_IP6_CONFIG_PROTOCOL                      *Ip6Cfg;
  EFI_DHCP6_PROTOCOL                           *Dhcp6;
  EFI_MTFTP6_PROTOCOL                          *Mtftp6;
  EFI_UDP6_PROTOCOL                            *Udp6Read;
  EFI_UDP6_PROTOCOL                            *Udp6Write;
  EFI_DNS6_PROTOCOL                            *Dns6;

  EFI_NETWORK_INTERFACE_IDENTIFIER_PROTOCOL    *Nii;
  EFI_PXE_BASE_CODE_PROTOCOL                   PxeBc;
  EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL          LoadFileCallback;
  EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL          *PxeBcCallback;
  EFI_DEVICE_PATH_PROTOCOL                     *DevicePath;

  EFI_PXE_BASE_CODE_MODE                       Mode;
  EFI_PXE_BASE_CODE_FUNCTION                   Function;
  UINT32                                       Ip6Policy;
  UINT32                                       SolicitTimes;
  UINT64                                       ElapsedTime;

  EFI_UDP4_CONFIG_DATA                         Udp4CfgData;
  EFI_UDP6_CONFIG_DATA                         Udp6CfgData;
  EFI_IP4_CONFIG_DATA                          Ip4CfgData;
  EFI_IP6_CONFIG_DATA                          Ip6CfgData;

  EFI_EVENT                                    UdpTimeOutEvent;
  EFI_EVENT                                    ArpUpdateEvent;
  EFI_IP4_COMPLETION_TOKEN                     IcmpToken;
  EFI_IP6_COMPLETION_TOKEN                     Icmp6Token;

  BOOLEAN                                      IsAddressOk;
  BOOLEAN                                      IsOfferSorted;
  BOOLEAN                                      IsProxyRecved;
  BOOLEAN                                      IsDoDiscover;

  EFI_IP_ADDRESS                               TmpStationIp;
  EFI_IP_ADDRESS                               StationIp;
  EFI_IP_ADDRESS                               SubnetMask;
  EFI_IP_ADDRESS                               GatewayIp;
  EFI_IP_ADDRESS                               ServerIp;
  EFI_IPv6_ADDRESS                             *DnsServer;
  UINT16                                       CurSrcPort;
  UINT32                                       IaId;

  UINT32                                       Ip4MaxPacketSize;
  UINT32                                       Ip6MaxPacketSize;
  UINT8                                        *BootFileName;
  UINTN                                        BootFileSize;
  UINTN                                        BlockSize;

  PXEBC_DHCP_PACKET_CACHE                      ProxyOffer;
  PXEBC_DHCP_PACKET_CACHE                      DhcpAck;
  PXEBC_DHCP_PACKET_CACHE                      PxeReply;
  EFI_DHCP6_PACKET                             *Dhcp6Request;
  EFI_DHCP4_PACKET                             SeedPacket;

  //
  // OfferIndex records the index of DhcpOffer[] buffer, and OfferCount records the num of each type of offer.
  //
  // It supposed that
  //
  //   OfferNum:    8
  //   OfferBuffer: [ProxyBinl, ProxyBinl, DhcpOnly, ProxyPxe10, DhcpOnly, DhcpPxe10, DhcpBinl, ProxyBinl]
  //   (OfferBuffer is 0-based.)
  //
  // And assume that (DhcpPxe10 is the first priority actually.)
  //
  //   SelectIndex:     2
  //   SelectProxyType: PXEBC_OFFER_TYPE_PROXY_BINL
  //   (SelectIndex is 1-based, and 0 means no one is selected.)
  //
  // So it should be
  //
  //                 DhcpOnly  DhcpPxe10  DhcpWfm11a  DhcpBinl  ProxyPxe10  ProxyWfm11a  ProxyBinl  Bootp
  //   OfferCount:  [    2(n),      1(n),       0(n),     1(n),       1(1),        0(1),      3(n),  1(1)]
  //
  //   OfferIndex: {[       2,         5,          0,        6,          3,           0,        *0,     0]
  //                [       4,         0,          0,        0,          0,           0,         1,     0]
  //                [       0,         0,          0,        0,          0,           0,         7,     0]
  //                ...                                                                                  ]}
  //   (OfferIndex is 0-based.)
  //
  //
  UINT32                     SelectIndex;
  UINT32                     SelectProxyType;
  PXEBC_DHCP_PACKET_CACHE    OfferBuffer[PXEBC_OFFER_MAX_NUM];
  UINT32                     OfferNum;
  UINT32                     OfferCount[PxeOfferTypeMax];
  UINT32                     OfferIndex[PxeOfferTypeMax][PXEBC_OFFER_MAX_NUM];
};

extern EFI_PXE_BASE_CODE_PROTOCOL           gPxeBcProtocolTemplate;
extern EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL  gPxeBcCallBackTemplate;
extern EFI_LOAD_FILE_PROTOCOL               gLoadFileProtocolTemplate;

#endif
