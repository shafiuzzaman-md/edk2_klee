/** @file
  Base Reset System Library Shutdown API implementation for bhyve.

  Copyright (C) 2020, Rebecca Cran <rebecca@bsdio.com>
  Copyright (C) 2020, Red Hat, Inc.
  Copyright (c) 2006 - 2019, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "edk2-master/MdePkg/Include/Base.h"

#include "edk2-master/OvmfPkg/Include/IndustryStandard/Bhyve.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/IoLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/ResetSystemLib.h"

/**
  Calling this function causes the system to enter a power state equivalent
  to the ACPI G2/S5 or G3 states.

  System shutdown should not return, if it returns, it means the system does
  not support shut down reset.
**/
VOID
EFIAPI
ResetShutdown (
  VOID
  )
{
  IoBitFieldWrite16 (BHYVE_PM_REG, 10, 13, 5);
  IoOr16 (BHYVE_PM_REG, BIT13);
  CpuDeadLoop ();
}
