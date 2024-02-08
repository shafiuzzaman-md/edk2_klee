/** @file
  This driver installs SMBIOS information for OVMF on Xen

  Copyright (C) 2021, Red Hat, Inc.
  Copyright (c) 2011, Bei Guan <gbtju85@gmail.com>
  Copyright (c) 2011, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef XEN_SMBIOS_PLATFORM_DXE_H_
#define XEN_SMBIOS_PLATFORM_DXE_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/IndustryStandard/SmBios.h"

/**
  Locates the Xen SMBIOS data if it exists

  @return SMBIOS_TABLE_ENTRY_POINT   Address of Xen SMBIOS data

**/
SMBIOS_TABLE_ENTRY_POINT *
GetXenSmbiosTables (
  VOID
  );

#endif
