/** @file
  Find and extract QEMU SMBIOS data from fw_cfg.

  Copyright (C) 2014, Gabriel L. Somlo <somlo@cmu.edu>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/OvmfPkg/Include/Library/QemuFwCfgLib.h"

/**
  Locates and extracts the QEMU SMBIOS data if present in fw_cfg

  @return                 Address of extracted QEMU SMBIOS data

**/
UINT8 *
GetQemuSmbiosTables (
  VOID
  )
{
  EFI_STATUS            Status;
  FIRMWARE_CONFIG_ITEM  Tables;
  UINTN                 TablesSize;
  UINT8                 *QemuTables;

  if (!PcdGetBool (PcdQemuSmbiosValidated)) {
    return NULL;
  }

  Status = QemuFwCfgFindFile (
             "etc/smbios/smbios-tables",
             &Tables,
             &TablesSize
             );
  ASSERT_EFI_ERROR (Status);
  ASSERT (TablesSize > 0);

  QemuTables = AllocatePool (TablesSize);
  if (QemuTables == NULL) {
    return NULL;
  }

  QemuFwCfgSelectItem (Tables);
  QemuFwCfgReadBytes (TablesSize, QemuTables);

  return QemuTables;
}
