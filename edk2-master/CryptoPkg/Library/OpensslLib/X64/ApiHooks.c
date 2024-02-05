/** @file
  OpenSSL Library API hooks.

Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "edk2-master/MdePkg/Include/Uefi.h"

/**
  Stub function for win64 API call.

**/
VOID *
__imp_RtlVirtualUnwind (
  VOID  *Args
  )
{
  return NULL;
}
