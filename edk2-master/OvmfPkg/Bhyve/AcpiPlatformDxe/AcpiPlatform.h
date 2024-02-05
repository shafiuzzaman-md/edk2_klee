/** @file
  bhyve ACPI Platform Driver

  Copyright (c) 2020, Rebecca Cran <rebecca@bsdio.com>
  Copyright (c) 2008 - 2012, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _ACPI_PLATFORM_H_INCLUDED_
#define _ACPI_PLATFORM_H_INCLUDED_

#include "edk2-master/MdePkg/Include/PiDxe.h"
#include "edk2-master/MdePkg/Include/Protocol/AcpiTable.h"
#include "edk2-master/MdePkg/Include/Protocol/FirmwareVolume2.h"
#include "edk2-master/MdePkg/Include/Protocol/PciIo.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/OvmfPkg/Include/Library/XenPlatformLib.h"
#include "edk2-master/MdePkg/Include/IndustryStandard/Acpi.h"

typedef struct S3_CONTEXT S3_CONTEXT;

EFI_STATUS
EFIAPI
InstallAcpiTable (
  IN   EFI_ACPI_TABLE_PROTOCOL  *AcpiProtocol,
  IN   VOID                     *AcpiTableBuffer,
  IN   UINTN                    AcpiTableBufferSize,
  OUT  UINTN                    *TableKey
  );

EFI_STATUS
EFIAPI
BhyveInstallAcpiTable (
  IN   EFI_ACPI_TABLE_PROTOCOL  *AcpiProtocol,
  IN   VOID                     *AcpiTableBuffer,
  IN   UINTN                    AcpiTableBufferSize,
  OUT  UINTN                    *TableKey
  );

EFI_STATUS
EFIAPI
InstallXenTables (
  IN   EFI_ACPI_TABLE_PROTOCOL  *AcpiProtocol
  );

EFI_STATUS
EFIAPI
InstallAcpiTables (
  IN   EFI_ACPI_TABLE_PROTOCOL  *AcpiTable
  );

#endif /* _ACPI_PLATFORM_H_INCLUDED_ */
