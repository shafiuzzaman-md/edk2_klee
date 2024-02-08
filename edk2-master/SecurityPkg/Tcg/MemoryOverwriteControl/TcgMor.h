/** @file
  The header file for TcgMor.

Copyright (c) 2009 - 2018, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __TCG_MOR_H__
#define __TCG_MOR_H__

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiDxe.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Guid/MemoryOverwriteControl.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiDriverEntryPoint.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/StorageSecurityCommand.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/BlockIo.h"

//
// Supported Security Protocols List Description.
// Refer to ATA8-ACS Spec 7.57.6.2 Table 69 or SPC4 7.7.1.3 Table 511.
//
typedef struct  {
  UINT8    Reserved1[6];
  UINT8    SupportedSecurityListLength[2];
  UINT8    SupportedSecurityProtocol[1];
} SUPPORTED_SECURITY_PROTOCOLS_PARAMETER_DATA;

#define SECURITY_PROTOCOL_TCG       0x02
#define SECURITY_PROTOCOL_IEEE1667  0xEE

#define ROUNDUP512(x)  (((x) % 512 == 0) ? (x) : ((x) / 512 + 1) * 512)

#endif
