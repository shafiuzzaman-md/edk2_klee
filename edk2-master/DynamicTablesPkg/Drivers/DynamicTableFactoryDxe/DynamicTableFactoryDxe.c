/** @file
  Dynamic Table Factory Dxe

  Copyright (c) 2017 - 2019, ARM Limited. All rights reserved.

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Protocol/AcpiTable.h"

// Module specific include files.
#include "edk2-master/DynamicTablesPkg/Include/AcpiTableGenerator.h"
#include "edk2-master/DynamicTablesPkg/Include/ConfigurationManagerObject.h"
#include "edk2-master/DynamicTablesPkg/Include/ConfigurationManagerHelper.h"
#include "edk2-master/DynamicTablesPkg/Include/DeviceTreeTableGenerator.h"
#include "edk2-master/DynamicTablesPkg/Include/Library/TableHelperLib.h"
#include "edk2-master/DynamicTablesPkg/Include/Protocol/ConfigurationManagerProtocol.h"
#include "edk2-master/DynamicTablesPkg/Include/Protocol/DynamicTableFactoryProtocol.h"
#include "edk2-master/DynamicTablesPkg/Include/SmbiosTableGenerator.h"

#include "DynamicTableFactory.h"

/** The Dynamic Table Factory protocol structure that holds the
    list of registered ACPI and SMBIOS table generators.
*/
EDKII_DYNAMIC_TABLE_FACTORY_INFO  TableFactoryInfo;

/** A structure describing the Dynamic Table Factory protocol.
*/
STATIC
CONST
EDKII_DYNAMIC_TABLE_FACTORY_PROTOCOL  DynamicTableFactoryProtocol = {
  CREATE_REVISION (1,             0),
  GetAcpiTableGenerator,
  RegisterAcpiTableGenerator,
  DeregisterAcpiTableGenerator,
  GetSmbiosTableGenerator,
  RegisterSmbiosTableGenerator,
  DeregisterSmbiosTableGenerator,
  GetDtTableGenerator,
  RegisterDtTableGenerator,
  DeregisterDtTableGenerator,
  &TableFactoryInfo
};

/** Entrypoint for Dynamic Table Factory Dxe.

  @param  ImageHandle
  @param  SystemTable

  @retval EFI_SUCCESS           Success.
  @retval EFI_OUT_OF_RESOURCES  Memory allocation failed.
  @retval EFI_NOT_FOUND         Required interface/object was not found.
  @retval EFI_INVALID_PARAMETER Some parameter is incorrect/invalid.
**/
EFI_STATUS
EFIAPI
DynamicTableFactoryDxeInitialize (
  IN  EFI_HANDLE        ImageHandle,
  IN  EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS  Status;

  Status = gBS->InstallProtocolInterface (
                  &ImageHandle,
                  &gEdkiiDynamicTableFactoryProtocolGuid,
                  EFI_NATIVE_INTERFACE,
                  (VOID *)&DynamicTableFactoryProtocol
                  );
  if (EFI_ERROR (Status)) {
    DEBUG ((
      DEBUG_ERROR,
      "ERROR: Failed to install the Dynamic Table Factory Protocol." \
      " Status = %r\n",
      Status
      ));
  }

  return Status;
}
