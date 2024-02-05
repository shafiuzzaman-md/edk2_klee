/** @file
  Dynamic Platform Info Repository

  Copyright (c) 2021, Arm Limited. All rights reserved.<BR>
  Copyright (C) 2024 Advanced Micro Devices, Inc. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

  @par Glossary:
    - Cm or CM   - Configuration Manager
    - Obj or OBJ - Object
**/

#include "edk2-master/DynamicTablesPkg/Include/Protocol/ConfigurationManagerProtocol.h"
#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"

#include "CmObjectTokenFixer.h"
#include "DynamicPlatRepoInternal.h"
#include "TokenGenerator.h"

/** Allocate a CM_OBJ_NODE.

  @param [in]  CmObjDesc  CmObj to wrap in a node.
                          All the fields of the CmObj (Data field included),
                          are copied.
  @param [in]  Token      Token to assign to this CmObj/node.
  @param [out] ObjNode    Allocated ObjNode.

  @retval EFI_SUCCESS           Success.
  @retval EFI_INVALID_PARAMETER A parameter is invalid.
  @retval EFI_OUT_OF_RESOURCES  An allocation has failed.
**/
STATIC
EFI_STATUS
EFIAPI
AllocCmObjNode (
  IN  CONST CM_OBJ_DESCRIPTOR  *CmObjDesc,
  IN        CM_OBJECT_TOKEN    Token,
  OUT       CM_OBJ_NODE        **ObjNode
  )
{
  CM_OBJ_NODE        *Node;
  CM_OBJ_DESCRIPTOR  *Desc;

  if ((CmObjDesc == NULL) || (ObjNode == NULL)) {
    ASSERT (0);
    return EFI_INVALID_PARAMETER;
  }

  Node = AllocateZeroPool (sizeof (CM_OBJ_NODE));
  if (Node == NULL) {
    ASSERT (0);
    return EFI_OUT_OF_RESOURCES;
  }

  // Initialise the list head.
  InitializeListHead (&Node->Link);
  Node->Token    = Token;
  Desc           = &Node->CmObjDesc;
  Desc->ObjectId = CmObjDesc->ObjectId;
  Desc->Size     = CmObjDesc->Size;
  Desc->Count    = CmObjDesc->Count;

  // Allocate and copy the CmObject Data.
  Desc->Data = AllocateCopyPool (CmObjDesc->Size, CmObjDesc->Data);
  if (Desc->Data == NULL) {
    FreePool (Node);
    ASSERT (0);
    return EFI_OUT_OF_RESOURCES;
  }

  *ObjNode = Node;
  return EFI_SUCCESS;
}

/** Free a CM_OBJ_NODE.

  @param [in]  ObjNode    ObjNode to free.

  @retval EFI_SUCCESS           Success.
  @retval EFI_INVALID_PARAMETER A parameter is invalid.
**/
STATIC
EFI_STATUS
EFIAPI
FreeCmObjNode (
  IN  CM_OBJ_NODE  *ObjNode
  )
{
  CM_OBJ_DESCRIPTOR  *Desc;

  if (ObjNode == NULL) {
    ASSERT (0);
    return EFI_INVALID_PARAMETER;
  }

  // Unlink Node
  RemoveEntryList (&ObjNode->Link);

  Desc = &ObjNode->CmObjDesc;
  if (Desc->Data != NULL) {
    FreePool (Desc->Data);
  }

  FreePool (ObjNode);
  return EFI_SUCCESS;
}

/** Add an object to the dynamic platform repository.

  @param [in]  This       This dynamic platform repository.
  @param [in]  CmObjDesc  CmObj to add. The data is copied.
  @param [out] Token      If not NULL, token allocated to this CmObj.

  @retval EFI_SUCCESS           Success.
  @retval EFI_INVALID_PARAMETER A parameter is invalid.
  @retval EFI_OUT_OF_RESOURCES  An allocation has failed.
**/
EFI_STATUS
EFIAPI
DynPlatRepoAddObject (
  IN        DYNAMIC_PLATFORM_REPOSITORY_INFO  *This,
  IN  CONST CM_OBJ_DESCRIPTOR                 *CmObjDesc,
  OUT       CM_OBJECT_TOKEN                   *Token OPTIONAL
  )
{
  EFI_STATUS       Status;
  CM_OBJ_NODE      *ObjNode;
  CM_OBJECT_ID     ArmNamespaceObjId;
  CM_OBJECT_TOKEN  NewToken;

  // The dynamic repository must be able to receive objects.
  if ((This == NULL)      ||
      (CmObjDesc == NULL) ||
      (This->RepoState != DynRepoTransient))
  {
    ASSERT (0);
    return EFI_INVALID_PARAMETER;
  }

  // Check the CmObjDesc:
  //  - only Arm objects are supported for now.
  //  - only EArmObjCmRef objects can be added as arrays.
  ArmNamespaceObjId = GET_CM_OBJECT_ID (CmObjDesc->ObjectId);
  if ((CmObjDesc->Size == 0)              ||
      (CmObjDesc->Count == 0)             ||
      (ArmNamespaceObjId >= EArmObjMax)   ||
      ((CmObjDesc->Count > 1)  && (ArmNamespaceObjId != EArmObjCmRef))  ||
      (GET_CM_NAMESPACE_ID (CmObjDesc->ObjectId) != EObjNameSpaceArm))
  {
    ASSERT (0);
    return EFI_INVALID_PARAMETER;
  }

  // Generate a token.
  NewToken = GenerateToken ();

  // Create an ObjNode.
  Status = AllocCmObjNode (CmObjDesc, NewToken, &ObjNode);
  if (EFI_ERROR (Status)) {
    ASSERT (0);
    return Status;
  }

  // Fixup self-token if necessary.
  Status = FixupCmObjectSelfToken (&ObjNode->CmObjDesc, NewToken);
  if (EFI_ERROR (Status)) {
    FreeCmObjNode (ObjNode);
    ASSERT (0);
    return Status;
  }

  // Add to link list.
  InsertTailList (&This->ArmCmObjList[ArmNamespaceObjId], &ObjNode->Link);
  This->ObjectCount += 1;

  if (Token != NULL) {
    *Token = NewToken;
  }

  return EFI_SUCCESS;
}

/** Group lists of CmObjNode from the ArmNameSpace to one array.

  @param [in]  This         This dynamic platform repository.
  @param [in]  ArmObjIndex  Index in EARM_OBJECT_ID
                            (must be < EArmObjMax).

  @retval EFI_SUCCESS           Success.
  @retval EFI_INVALID_PARAMETER A parameter is invalid.
  @retval EFI_BUFFER_TOO_SMALL    Buffer too small.
  @retval EFI_OUT_OF_RESOURCES  An allocation has failed.
**/
STATIC
EFI_STATUS
EFIAPI
GroupCmObjNodes (
  IN  DYNAMIC_PLATFORM_REPOSITORY_INFO  *This,
  IN  UINT32                            ArmObjIndex
  )
{
  EFI_STATUS         Status;
  UINTN              Count;
  UINTN              Size;
  UINT32             CmObjId;
  UINT8              *GroupedData;
  UINT8              *Data;
  CM_OBJ_DESCRIPTOR  *CmObjDesc;
  LIST_ENTRY         *ListHead;
  LIST_ENTRY         *Link;

  if ((This == NULL)  ||
      (ArmObjIndex >= EArmObjMax))
  {
    ASSERT (0);
    return EFI_INVALID_PARAMETER;
  }

  Count    = 0;
  Size     = 0;
  CmObjId  = CREATE_CM_ARM_OBJECT_ID (ArmObjIndex);
  ListHead = &This->ArmCmObjList[ArmObjIndex];
  Link     = GetFirstNode (ListHead);

  // Compute the total count and size of the CmObj in the list.
  while (Link != ListHead) {
    CmObjDesc = &((CM_OBJ_NODE *)Link)->CmObjDesc;

    if (CmObjDesc->ObjectId != CmObjId) {
      ASSERT (0);
      return EFI_INVALID_PARAMETER;
    }

    if ((CmObjDesc->Count != 1) && (ArmObjIndex != EArmObjCmRef)) {
      // We expect each descriptor to contain an individual object.
      // EArmObjCmRef objects are counted as groups, so +1 as well.
      ASSERT (0);
      return EFI_INVALID_PARAMETER;
    }

    Count++;
    Size += CmObjDesc->Size;

    // Next Link
    Link = GetNextNode (ListHead, Link);
  } // while

  if (Count == 0) {
    // No objects found.
    return EFI_SUCCESS;
  }

  GroupedData = AllocateZeroPool (Size);
  if (GroupedData == NULL) {
    ASSERT (0);
    return EFI_OUT_OF_RESOURCES;
  }

  // Copy the Object Data and add to the TokenMapper.
  Data = GroupedData;
  Link = GetFirstNode (ListHead);
  while (Link != ListHead) {
    CmObjDesc = &((CM_OBJ_NODE *)Link)->CmObjDesc;
    CopyMem (Data, CmObjDesc->Data, CmObjDesc->Size);

    // Add the object to the Token Mapper.
    // Note: The CmObject Data field of objects in the Token Mapper point
    //       to the memory in the GroupedData array.
    Status = TokenMapperAddObject (
               &This->TokenMapper,
               ((CM_OBJ_NODE *)Link)->Token,
               CmObjDesc->ObjectId,
               CmObjDesc->Size,
               Data
               );
    if (EFI_ERROR (Status)) {
      FreePool (GroupedData);
      return Status;
    }

    Data += CmObjDesc->Size;
    Link  = GetNextNode (ListHead, Link);
  } // while

  CmObjDesc           = &This->ArmCmObjArray[ArmObjIndex];
  CmObjDesc->ObjectId = CmObjId;
  CmObjDesc->Size     = (UINT32)Size;
  CmObjDesc->Count    = (UINT32)Count;
  CmObjDesc->Data     = GroupedData;

  return Status;
}

/** Finalise the dynamic repository.

  Finalising means:
   - Preventing any further objects from being added.
   - Allowing to get objects from the dynamic repository
     (not possible before a call to this function).

  @param [in]  This       This dynamic platform repository.

  @retval EFI_SUCCESS           Success.
  @retval EFI_ALREADY_STARTED   Instance already initialised.
  @retval EFI_INVALID_PARAMETER A parameter is invalid.
  @retval EFI_BUFFER_TOO_SMALL  Buffer too small.
  @retval EFI_OUT_OF_RESOURCES  An allocation has failed.
**/
EFI_STATUS
EFIAPI
DynamicPlatRepoFinalise (
  IN  DYNAMIC_PLATFORM_REPOSITORY_INFO  *This
  )
{
  EFI_STATUS  Status;
  UINTN       ArmObjIndex;

  if ((This == NULL)  ||
      (This->RepoState != DynRepoTransient))
  {
    ASSERT (0);
    return EFI_INVALID_PARAMETER;
  }

  // Prevent any further objects from being added.
  This->RepoState = DynRepoFinalized;

  // Initialise the token mapper.
  Status = TokenMapperInitialise (&This->TokenMapper, This->ObjectCount);
  if (EFI_ERROR (Status)) {
    ASSERT (0);
    return Status;
  }

  // For each CM_OBJECT_ID:
  //  - Convert the list of nodes to an array
  //    (the array is wrapped in a CmObjDesc).
  //  - Add the Token/CmObj binding to the token mapper.
  for (ArmObjIndex = 0; ArmObjIndex < EArmObjMax; ArmObjIndex++) {
    Status = GroupCmObjNodes (This, (UINT32)ArmObjIndex);
    if (EFI_ERROR (Status)) {
      ASSERT (0);
      // Free the TokenMapper.
      // Ignore the returned Status since we already failed.
      TokenMapperShutdown (&This->TokenMapper);
      return Status;
    }
  } // for

  return EFI_SUCCESS;
}

/** Get a CmObj from the dynamic repository.

  @param [in]      This        Pointer to the Dynamic Platform Repository.
  @param [in]      CmObjectId  The Configuration Manager Object ID.
  @param [in]      Token       An optional token identifying the object. If
                               unused this must be CM_NULL_TOKEN.
  @param [in, out] CmObjDesc   Pointer to the Configuration Manager Object
                               descriptor describing the requested Object.

  @retval EFI_SUCCESS           Success.
  @retval EFI_INVALID_PARAMETER A parameter is invalid.
  @retval EFI_NOT_FOUND         The required object information is not found.
**/
EFI_STATUS
EFIAPI
DynamicPlatRepoGetObject (
  IN      DYNAMIC_PLATFORM_REPOSITORY_INFO  *This,
  IN      CM_OBJECT_ID                      CmObjectId,
  IN      CM_OBJECT_TOKEN                   Token OPTIONAL,
  IN  OUT CM_OBJ_DESCRIPTOR                 *CmObjDesc
  )
{
  EFI_STATUS         Status;
  CM_OBJ_DESCRIPTOR  *Desc;
  CM_OBJECT_ID       ArmNamespaceObjId;

  if ((This == NULL)      ||
      (CmObjDesc == NULL) ||
      (This->RepoState != DynRepoFinalized))
  {
    ASSERT (0);
    return EFI_INVALID_PARAMETER;
  }

  ArmNamespaceObjId = GET_CM_OBJECT_ID (CmObjectId);
  if (ArmNamespaceObjId >= EArmObjMax) {
    ASSERT (0);
    return EFI_INVALID_PARAMETER;
  }

  if (Token != CM_NULL_TOKEN) {
    // Search in the Token Mapper and return the object.
    Status = TokenMapperGetObject (
               &This->TokenMapper,
               Token,
               CmObjectId,
               CmObjDesc
               );
    ASSERT_EFI_ERROR (Status);
    return Status;
  }

  if (ArmNamespaceObjId == EArmObjCmRef) {
    // EArmObjCmRef object must be requested using a valid token.
    ASSERT (0);
    return EFI_INVALID_PARAMETER;
  }

  Desc = &This->ArmCmObjArray[ArmNamespaceObjId];

  // Nothing here.
  if (Desc->Count == 0) {
    return EFI_NOT_FOUND;
  } else {
    // Return the full array.
    CmObjDesc->ObjectId = Desc->ObjectId;
    CmObjDesc->Size     = Desc->Size;
    CmObjDesc->Data     = Desc->Data;
    CmObjDesc->Count    = Desc->Count;
  }

  return EFI_SUCCESS;
}

/** Initialize the dynamic platform repository.

  @param [out]  DynPlatRepo   If success, contains the initialised dynamic
                              platform repository.

  @retval EFI_SUCCESS           Success.
  @retval EFI_INVALID_PARAMETER A parameter is invalid.
  @retval EFI_OUT_OF_RESOURCES  An allocation has failed.
**/
EFI_STATUS
EFIAPI
DynamicPlatRepoInit (
  OUT DYNAMIC_PLATFORM_REPOSITORY_INFO  **DynPlatRepo
  )
{
  UINTN                             Index;
  DYNAMIC_PLATFORM_REPOSITORY_INFO  *Repo;

  if (DynPlatRepo == NULL) {
    ASSERT (0);
    return EFI_INVALID_PARAMETER;
  }

  Repo = AllocateZeroPool (sizeof (DYNAMIC_PLATFORM_REPOSITORY_INFO));
  if (Repo == NULL) {
    ASSERT (0);
    return EFI_OUT_OF_RESOURCES;
  }

  // Initialise the CmObject List.
  for (Index = 0; Index < EArmObjMax; Index++) {
    InitializeListHead (&Repo->ArmCmObjList[Index]);
  }

  Repo->ObjectCount = 0;
  Repo->RepoState   = DynRepoTransient;

  *DynPlatRepo = Repo;

  return EFI_SUCCESS;
}

/** Shutdown the dynamic platform repository.

  Free all the memory allocated for the dynamic platform repository.

  @param [in]  DynPlatRepo    The dynamic platform repository.

  @retval EFI_INVALID_PARAMETER A parameter is invalid.
  @retval EFI_SUCCESS           Success.
**/
EFI_STATUS
EFIAPI
DynamicPlatRepoShutdown (
  IN  DYNAMIC_PLATFORM_REPOSITORY_INFO  *DynPlatRepo
  )
{
  EFI_STATUS         Status;
  UINT32             Index;
  LIST_ENTRY         *ListHead;
  CM_OBJ_DESCRIPTOR  *CmObjDesc;
  VOID               *Data;

  if (DynPlatRepo == NULL) {
    ASSERT (0);
    return EFI_INVALID_PARAMETER;
  }

  // Free the list of objects.
  for (Index = 0; Index < EArmObjMax; Index++) {
    // Free all the nodes with this object Id.
    ListHead = &DynPlatRepo->ArmCmObjList[Index];
    while (!IsListEmpty (ListHead)) {
      FreeCmObjNode ((CM_OBJ_NODE *)GetFirstNode (ListHead));
    } // while
  } // for

  // Free the arrays.
  CmObjDesc = DynPlatRepo->ArmCmObjArray;
  for (Index = 0; Index < EArmObjMax; Index++) {
    Data = CmObjDesc[Index].Data;
    if (Data != NULL) {
      FreePool (Data);
    }
  } // for

  // Free the TokenMapper
  Status = TokenMapperShutdown (&DynPlatRepo->TokenMapper);
  ASSERT_EFI_ERROR (Status);
  FreePool (DynPlatRepo);
  return Status;
}
