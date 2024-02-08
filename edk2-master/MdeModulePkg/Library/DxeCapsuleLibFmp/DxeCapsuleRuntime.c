/** @file
  Capsule library runtime support.

  Copyright (c) 2016 - 2017, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiDxe.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Guid/FmpCapsule.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Guid/SystemResourceTable.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Guid/EventGroup.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DxeServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiRuntimeServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"

extern EFI_SYSTEM_RESOURCE_TABLE  *mEsrtTable;
EFI_EVENT                         mDxeRuntimeCapsuleLibVirtualAddressChangeEvent = NULL;
EFI_EVENT                         mDxeRuntimeCapsuleLibReadyToBootEvent          = NULL;

/**
  Convert EsrtTable physical address to virtual address.

  @param[in] Event      Event whose notification function is being invoked.
  @param[in] Context    The pointer to the notification function's context, which
                        is implementation-dependent.
**/
VOID
EFIAPI
DxeCapsuleLibVirtualAddressChangeEvent (
  IN  EFI_EVENT  Event,
  IN  VOID       *Context
  )
{
  gRT->ConvertPointer (EFI_OPTIONAL_PTR, (VOID **)&mEsrtTable);
}

/**
  Notify function for event group EFI_EVENT_GROUP_READY_TO_BOOT.

  @param[in]  Event   The Event that is being processed.
  @param[in]  Context The Event Context.

**/
STATIC
VOID
EFIAPI
DxeCapsuleLibReadyToBootEventNotify (
  IN EFI_EVENT  Event,
  IN VOID       *Context
  )
{
  UINTN                      Index;
  EFI_CONFIGURATION_TABLE    *ConfigEntry;
  EFI_SYSTEM_RESOURCE_TABLE  *EsrtTable;

  //
  // Get Esrt table first
  //
  ConfigEntry = gST->ConfigurationTable;
  for (Index = 0; Index < gST->NumberOfTableEntries; Index++) {
    if (CompareGuid (&gEfiSystemResourceTableGuid, &ConfigEntry->VendorGuid)) {
      break;
    }

    ConfigEntry++;
  }

  //
  // If no Esrt table installed in Configure Table
  //
  if (Index < gST->NumberOfTableEntries) {
    //
    // Search Esrt to check given capsule is qualified
    //
    EsrtTable = (EFI_SYSTEM_RESOURCE_TABLE *)ConfigEntry->VendorTable;

    mEsrtTable = AllocateRuntimeCopyPool (
                   sizeof (EFI_SYSTEM_RESOURCE_TABLE) +
                   EsrtTable->FwResourceCount * sizeof (EFI_SYSTEM_RESOURCE_ENTRY),
                   EsrtTable
                   );
    ASSERT (mEsrtTable != NULL);

    //
    // Set FwResourceCountMax to a sane value.
    //
    mEsrtTable->FwResourceCountMax = mEsrtTable->FwResourceCount;
  }
}

/**
  The constructor function hook VirtualAddressChange event to use ESRT table as capsule routing table.

  @param  ImageHandle   The firmware allocated handle for the EFI image.
  @param  SystemTable   A pointer to the EFI System Table.

  @retval EFI_SUCCESS   The constructor successfully .
**/
EFI_STATUS
EFIAPI
DxeRuntimeCapsuleLibConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS  Status;

  //
  // Make sure we can handle virtual address changes.
  //
  Status = gBS->CreateEventEx (
                  EVT_NOTIFY_SIGNAL,
                  TPL_NOTIFY,
                  DxeCapsuleLibVirtualAddressChangeEvent,
                  NULL,
                  &gEfiEventVirtualAddressChangeGuid,
                  &mDxeRuntimeCapsuleLibVirtualAddressChangeEvent
                  );
  ASSERT_EFI_ERROR (Status);

  //
  // Register notify function to cache the FMP capsule GUIDs at ReadyToBoot.
  //
  Status = gBS->CreateEventEx (
                  EVT_NOTIFY_SIGNAL,
                  TPL_CALLBACK,
                  DxeCapsuleLibReadyToBootEventNotify,
                  NULL,
                  &gEfiEventReadyToBootGuid,
                  &mDxeRuntimeCapsuleLibReadyToBootEvent
                  );
  ASSERT_EFI_ERROR (Status);

  return EFI_SUCCESS;
}

/**
  The destructor function closes the VirtualAddressChange event.

  @param  ImageHandle   The firmware allocated handle for the EFI image.
  @param  SystemTable   A pointer to the EFI System Table.

  @retval EFI_SUCCESS   The destructor completed successfully.
**/
EFI_STATUS
EFIAPI
DxeRuntimeCapsuleLibDestructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS  Status;

  //
  // Close the VirtualAddressChange event.
  //
  Status = gBS->CloseEvent (mDxeRuntimeCapsuleLibVirtualAddressChangeEvent);
  ASSERT_EFI_ERROR (Status);

  //
  // Close the ReadyToBoot event.
  //
  Status = gBS->CloseEvent (mDxeRuntimeCapsuleLibReadyToBootEvent);
  ASSERT_EFI_ERROR (Status);

  return EFI_SUCCESS;
}
