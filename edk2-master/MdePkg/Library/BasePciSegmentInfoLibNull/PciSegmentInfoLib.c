/** @file
  Default PCI Segment Information Library that returns one segment whose
  segment base address equals to PcdPciExpressBaseAddress.

  Copyright (c) 2017 - 2020, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "edk2-master/MdePkg/Include/Base.h"
#include "edk2-master/MdePkg/Include/Library/PciSegmentInfoLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"

/**
  Return an array of PCI_SEGMENT_INFO holding the segment information.

  Note: The returned array/buffer is owned by callee.

  @param  Count  Return the count of segments.

  @retval A callee owned array holding the segment information.
**/
PCI_SEGMENT_INFO *
EFIAPI
GetPciSegmentInfo (
  UINTN  *Count
  )
{
  ASSERT (FALSE);
  *Count = 0;
  return NULL;
}
