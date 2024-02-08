/** @file
  Internal include file for TlsLib.

Copyright (c) 2016 - 2017, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __INTERNAL_TLS_LIB_H__
#define __INTERNAL_TLS_LIB_H__

#undef _WIN32
#undef _WIN64

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/CryptoPkg/Include/Library/BaseCryptLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/SafeIntLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Tls.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/Tls1.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PcdLib.h"
#include <openssl/obj_mac.h>
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/CryptoPkg/Library/OpensslLib/OpensslGen/include/openssl/ssl.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/CryptoPkg/Library/OpensslLib/OpensslGen/include/openssl/bio.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/CryptoPkg/Library/OpensslLib/OpensslGen/include/openssl/err.h"

typedef struct {
  //
  // Main SSL Connection which is created by a server or a client
  // per established connection.
  //
  SSL    *Ssl;
  //
  // Memory BIO for the TLS/SSL Reading operations.
  //
  BIO    *InBio;
  //
  // Memory BIO for the TLS/SSL Writing operations.
  //
  BIO    *OutBio;
} TLS_CONNECTION;

#endif
