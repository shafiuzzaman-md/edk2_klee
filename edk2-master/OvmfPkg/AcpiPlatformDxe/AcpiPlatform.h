/** @file
  OVMF ACPI Platform Driver

  Copyright (c) 2008 - 2012, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef ACPI_PLATFORM_H_
#define ACPI_PLATFORM_H_

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/AcpiTable.h"

EFI_STATUS
EFIAPI
InstallCloudHvTablesTdx (
  IN   EFI_ACPI_TABLE_PROTOCOL  *AcpiProtocol
  );

EFI_STATUS
EFIAPI
InstallCloudHvTables (
  IN   EFI_ACPI_TABLE_PROTOCOL  *AcpiProtocol
  );

EFI_STATUS
EFIAPI
InstallAcpiTables (
  IN   EFI_ACPI_TABLE_PROTOCOL  *AcpiTable
  );

#endif
