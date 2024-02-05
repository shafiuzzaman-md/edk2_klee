/** @file
  The header file for Tcg2 SMM driver.

Copyright (c) 2015 - 2018, Intel Corporation. All rights reserved.<BR>
Copyright (c) Microsoft Corporation.
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __TCG2_SMM_H__
#define __TCG2_SMM_H__

#include "edk2-master/MdePkg/Include/PiMm.h"

#include "edk2-master/MdePkg/Include/Guid/MemoryOverwriteControl.h"
#include "edk2-master/SecurityPkg/Include/Guid/TpmInstance.h"
#include "edk2-master/SecurityPkg/Include/Guid/TpmNvsMm.h"

#include "edk2-master/MdePkg/Include/Protocol/MmReadyToLock.h"
#include "edk2-master/MdePkg/Include/Protocol/SmmSwDispatch2.h"
#include "edk2-master/MdePkg/Include/Protocol/AcpiTable.h"
#include "edk2-master/MdeModulePkg/Include/Protocol/SmmVariable.h"
#include "edk2-master/MdePkg/Include/Protocol/Tcg2Protocol.h"

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MmServicesTableLib.h"
#include "edk2-master/SecurityPkg/Include/Library/Tpm2CommandLib.h"
#include "edk2-master/SecurityPkg/Include/Library/Tcg2PhysicalPresenceLib.h"
#include "edk2-master/MdePkg/Include/Library/IoLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/SecurityPkg/Include/Library/Tpm2DeviceLib.h"

#include "edk2-master/MdePkg/Include/IndustryStandard/TpmPtp.h"

//
// The definition for TCG MOR
//
#define ACPI_FUNCTION_DSM_MEMORY_CLEAR_INTERFACE  1
#define ACPI_FUNCTION_PTS_CLEAR_MOR_BIT           2

//
// The return code for Memory Clear Interface Functions
//
#define MOR_REQUEST_SUCCESS          0
#define MOR_REQUEST_GENERAL_FAILURE  1

/**
  Notify the system that the SMM variable driver is ready.
**/
VOID
Tcg2NotifyMmReady (
  VOID
  );

/**
  This function is an abstraction layer for implementation specific Mm buffer validation routine.

  @param Buffer  The buffer start address to be checked.
  @param Length  The buffer length to be checked.

  @retval TRUE  This buffer is valid per processor architecture and not overlap with SMRAM.
  @retval FALSE This buffer is not valid per processor architecture or overlap with SMRAM.
**/
BOOLEAN
IsBufferOutsideMmValid (
  IN EFI_PHYSICAL_ADDRESS  Buffer,
  IN UINT64                Length
  );

/**
  The driver's common initialization routine.

  It install callbacks for TPM physical presence and MemoryClear, and locate
  SMM variable to be used in the callback function.

  @retval EFI_SUCCESS     The entry point is executed successfully.
  @retval Others          Some error occurs when executing this entry point.

**/
EFI_STATUS
InitializeTcgCommon (
  VOID
  );

#endif // __TCG_SMM_H__
