/** @file
  Find Cloud Hypervisor SMBIOS data.

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "edk2-master/OvmfPkg/Include/IndustryStandard/CloudHv.h"
#include "edk2-master/MdePkg/Include/IndustryStandard/SmBios.h"

/**
  Locates and extracts Cloud Hypervisor SMBIOS data

  @return                 Address of extracted Cloud Hypervisor SMBIOS data

**/
UINT8 *
GetCloudHvSmbiosTables (
  VOID
  )
{
  SMBIOS_TABLE_3_0_ENTRY_POINT  *CloudHvTables = (VOID *)CLOUDHV_SMBIOS_ADDRESS;

  if ((CloudHvTables->AnchorString[0] == '_') &&
      (CloudHvTables->AnchorString[1] == 'S') &&
      (CloudHvTables->AnchorString[2] == 'M') &&
      (CloudHvTables->AnchorString[3] == '3') &&
      (CloudHvTables->AnchorString[4] == '_'))
  {
    return (UINT8 *)(UINTN)CloudHvTables->TableAddress;
  }

  return NULL;
}
