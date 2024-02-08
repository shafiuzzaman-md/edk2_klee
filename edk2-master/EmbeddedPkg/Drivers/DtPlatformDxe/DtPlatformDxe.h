/** @file
*
*  Copyright (c) 2017, Linaro Limited. All rights reserved.
*
*  SPDX-License-Identifier: BSD-2-Clause-Patent
*
**/

#ifndef __DT_PLATFORM_DXE_H__
#define __DT_PLATFORM_DXE_H__

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Guid/HiiPlatformSetupFormset.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmbeddedPkg/Include/Guid/DtPlatformFormSet.h"

#define DT_ACPI_SELECT_DT    0x0
#define DT_ACPI_SELECT_ACPI  0x1

#define DT_ACPI_VARIABLE_NAME  L"DtAcpiPref"

typedef struct {
  UINT8    Pref;
  UINT8    Reserved[3];
} DT_ACPI_VARSTORE_DATA;

#endif
