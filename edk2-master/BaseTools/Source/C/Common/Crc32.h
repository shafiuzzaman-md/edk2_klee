/** @file
Header file for CalculateCrc32 routine

Copyright (c) 2004 - 2018, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _CRC32_H
#define _CRC32_H

#include "edk2-master/BaseTools/Source/C/Include/Common/UefiBaseTypes.h"

/**
  The CalculateCrc32 routine.

  @param Data        The buffer containing the data to be processed
  @param DataSize    The size of data to be processed
  @param CrcOut      A pointer to the caller allocated UINT32 that on
                    contains the CRC32 checksum of Data

  @retval EFI_SUCCESS               - Calculation is successful.
  @retval EFI_INVALID_PARAMETER     - Data / CrcOut = NULL, or DataSize = 0
**/
EFI_STATUS
CalculateCrc32 (
  IN  UINT8                             *Data,
  IN  UINTN                             DataSize,
  IN OUT UINT32                         *CrcOut
  )
;

#endif
