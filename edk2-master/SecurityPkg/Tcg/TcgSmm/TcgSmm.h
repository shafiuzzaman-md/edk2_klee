/** @file
  The header file for TCG SMM driver.

Copyright (c) 2012 - 2018, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __TCG_SMM_H__
#define __TCG_SMM_H__

#include "edk2-master/MdePkg/Include/PiDxe.h"
#include "edk2-master/MdePkg/Include/IndustryStandard/Acpi.h"
#include "edk2-master/MdePkg/Include/IndustryStandard/UefiTcgPlatform.h"

#include "edk2-master/SecurityPkg/Include/Guid/PhysicalPresenceData.h"
#include "edk2-master/MdePkg/Include/Guid/MemoryOverwriteControl.h"
#include "edk2-master/SecurityPkg/Include/Guid/TpmInstance.h"

#include "edk2-master/MdePkg/Include/Protocol/SmmSwDispatch2.h"
#include "edk2-master/MdePkg/Include/Protocol/AcpiTable.h"
#include "edk2-master/MdeModulePkg/Include/Protocol/SmmVariable.h"

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/SmmServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiDriverEntryPoint.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Library/DxeServicesLib.h"
#include "edk2-master/MdeModulePkg/Include/Library/TpmMeasurementLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"
#include "edk2-master/SecurityPkg/Include/Library/TcgPpVendorLib.h"

#pragma pack(1)
typedef struct {
  UINT8     SoftwareSmi;
  UINT32    Parameter;
  UINT32    Response;
  UINT32    Request;
  UINT32    LastRequest;
  UINT32    ReturnCode;
} PHYSICAL_PRESENCE_NVS;

typedef struct {
  UINT8     SoftwareSmi;
  UINT32    Parameter;
  UINT32    Request;
  UINT32    ReturnCode;
} MEMORY_CLEAR_NVS;

typedef struct {
  PHYSICAL_PRESENCE_NVS    PhysicalPresence;
  MEMORY_CLEAR_NVS         MemoryClear;
  UINT32                   PPRequestUserConfirm;
} TCG_NVS;

typedef struct {
  UINT8     OpRegionOp;
  UINT32    NameString;
  UINT8     RegionSpace;
  UINT8     DWordPrefix;
  UINT32    RegionOffset;
  UINT8     BytePrefix;
  UINT8     RegionLen;
} AML_OP_REGION_32_8;
#pragma pack()

//
// The definition for TCG physical presence ACPI function
//
#define ACPI_FUNCTION_GET_PHYSICAL_PRESENCE_INTERFACE_VERSION    1
#define ACPI_FUNCTION_SUBMIT_REQUEST_TO_BIOS                     2
#define ACPI_FUNCTION_GET_PENDING_REQUEST_BY_OS                  3
#define ACPI_FUNCTION_GET_PLATFORM_ACTION_TO_TRANSITION_TO_BIOS  4
#define ACPI_FUNCTION_RETURN_REQUEST_RESPONSE_TO_OS              5
#define ACPI_FUNCTION_SUBMIT_PREFERRED_USER_LANGUAGE             6
#define ACPI_FUNCTION_SUBMIT_REQUEST_TO_BIOS_2                   7
#define ACPI_FUNCTION_GET_USER_CONFIRMATION_STATUS_FOR_REQUEST   8

//
// The return code for Return TPM Operation Response to OS Environment
//
#define PP_RETURN_TPM_OPERATION_RESPONSE_SUCCESS  0
#define PP_RETURN_TPM_OPERATION_RESPONSE_FAILURE  1

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

#endif // __TCG_SMM_H__
