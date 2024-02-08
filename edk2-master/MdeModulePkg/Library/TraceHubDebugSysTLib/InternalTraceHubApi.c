/** @file
Functions implementation in this file are not common for all type of TraceHubDebugSysTLib.

Copyright (c) 2023, Intel Corporation. All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Base.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Guid/TraceHubDebugInfoHob.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/HobLib.h"
#include "InternalTraceHubApi.h"

/**
  Count the total number of Trace Hub debug instance in the system.

  @retval UINT32      The total number of Trace Hub debug instance in the system.
**/
UINT32
EFIAPI
CountThDebugInstance (
  VOID
  )
{
  UINT8   *DbgContext;
  UINT32  DbgInstCount;

  DbgInstCount = 0;

  DbgContext = (UINT8 *)GetFirstGuidHob (&gTraceHubDebugInfoHobGuid);
  if (DbgContext != NULL) {
    while (DbgContext != NULL) {
      DbgInstCount++;
      DbgContext = (UINT8 *)GetNextGuidHob (&gTraceHubDebugInfoHobGuid, GET_NEXT_HOB (DbgContext));
    }
  } else {
    DbgInstCount++;
  }

  return DbgInstCount;
}

/**
  Pack Trace Hub debug instances in the system.

  @param[in, out]  ThPtr     A pointer to TRACEHUB_DEBUG_INFO_HOB structure.
  @param[in]       Count     Number of Trace Hub HOBs.
**/
VOID
EFIAPI
PackThDebugInstance (
  IN OUT TRACEHUB_DEBUG_INFO_HOB  *ThPtr,
  IN     UINT32                   Count
  )
{
  UINT8   *DbgContext;
  UINT16  Index;

  DbgContext = GetFirstGuidHob (&gTraceHubDebugInfoHobGuid);
  if (DbgContext != NULL) {
    for (Index = 0; Index < Count; Index++) {
      CopyMem (&ThPtr[Index], GET_GUID_HOB_DATA (DbgContext), sizeof (TRACEHUB_DEBUG_INFO_HOB));
      DbgContext = GetNextGuidHob (&gTraceHubDebugInfoHobGuid, GET_NEXT_HOB (DbgContext));
    }
  } else {
    for (Index = 0; Index < Count; Index++) {
      ThPtr[Index].TraceHubMmioAddress = FixedPcdGet64 (PcdTraceHubDebugMmioAddress);
      ThPtr[Index].Flag                = FixedPcdGetBool (PcdEnableTraceHubDebugMsg);
      ThPtr[Index].DebugLevel          = FixedPcdGet8 (PcdTraceHubDebugLevel);
    }
  }
}
