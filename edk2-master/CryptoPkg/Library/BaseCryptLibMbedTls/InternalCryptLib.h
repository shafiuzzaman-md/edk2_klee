/** @file
  Internal include file for BaseCryptLib.

Copyright (c) 2023, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef INTERNAL_CRYPT_LIB_H_
#define INTERNAL_CRYPT_LIB_H_

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/CryptoPkg/Include/Library/BaseCryptLib.h"
#include "edk2-master/RedfishPkg/PrivateInclude/Crt/stdio.h"

//
// We should alwasy add mbedtls/config.h here
// to ensure the config override takes effect.
//
#include "edk2-master/CryptoPkg/Library/MbedTlsLib/Include/mbedtls/mbedtls_config.h"

#endif
