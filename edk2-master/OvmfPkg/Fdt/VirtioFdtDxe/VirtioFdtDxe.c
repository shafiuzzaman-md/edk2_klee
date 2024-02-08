/** @file
*  Virtio FDT client protocol driver for virtio,mmio DT node
*
*  Copyright (c) 2014 - 2016, Linaro Ltd. All rights reserved.<BR>
*
*  SPDX-License-Identifier: BSD-2-Clause-Patent
*
**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DevicePathLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiDriverEntryPoint.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/Library/VirtioMmioDeviceLib.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/Guid/VirtioMmioTransport.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmbeddedPkg/Include/Protocol/FdtClient.h"

#pragma pack (1)
typedef struct {
  VENDOR_DEVICE_PATH          Vendor;
  UINT64                      PhysBase;
  EFI_DEVICE_PATH_PROTOCOL    End;
} VIRTIO_TRANSPORT_DEVICE_PATH;
#pragma pack ()

EFI_STATUS
EFIAPI
InitializeVirtioFdtDxe (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS                    Status, FindNodeStatus;
  FDT_CLIENT_PROTOCOL           *FdtClient;
  INT32                         Node;
  CONST UINT64                  *Reg;
  UINT32                        RegSize;
  VIRTIO_TRANSPORT_DEVICE_PATH  *DevicePath;
  EFI_HANDLE                    Handle;
  UINT64                        RegBase;

  Status = gBS->LocateProtocol (
                  &gFdtClientProtocolGuid,
                  NULL,
                  (VOID **)&FdtClient
                  );
  ASSERT_EFI_ERROR (Status);

  for (FindNodeStatus = FdtClient->FindCompatibleNode (
                                     FdtClient,
                                     "virtio,mmio",
                                     &Node
                                     );
       !EFI_ERROR (FindNodeStatus);
       FindNodeStatus = FdtClient->FindNextCompatibleNode (
                                     FdtClient,
                                     "virtio,mmio",
                                     Node,
                                     &Node
                                     ))
  {
    Status = FdtClient->GetNodeProperty (
                          FdtClient,
                          Node,
                          "reg",
                          (CONST VOID **)&Reg,
                          &RegSize
                          );
    if (EFI_ERROR (Status)) {
      DEBUG ((
        DEBUG_ERROR,
        "%a: GetNodeProperty () failed (Status == %r)\n",
        __func__,
        Status
        ));
      continue;
    }

    ASSERT (RegSize == 16);

    //
    // Create a unique device path for this transport on the fly
    //
    RegBase    = SwapBytes64 (*Reg);
    DevicePath = (VIRTIO_TRANSPORT_DEVICE_PATH *)CreateDeviceNode (
                                                   HARDWARE_DEVICE_PATH,
                                                   HW_VENDOR_DP,
                                                   sizeof (VIRTIO_TRANSPORT_DEVICE_PATH)
                                                   );
    if (DevicePath == NULL) {
      DEBUG ((DEBUG_ERROR, "%a: Out of memory\n", __func__));
      continue;
    }

    CopyGuid (&DevicePath->Vendor.Guid, &gVirtioMmioTransportGuid);
    DevicePath->PhysBase = RegBase;
    SetDevicePathNodeLength (
      &DevicePath->Vendor,
      sizeof (*DevicePath) - sizeof (DevicePath->End)
      );
    SetDevicePathEndNode (&DevicePath->End);

    Handle = NULL;
    Status = gBS->InstallProtocolInterface (
                    &Handle,
                    &gEfiDevicePathProtocolGuid,
                    EFI_NATIVE_INTERFACE,
                    DevicePath
                    );
    if (EFI_ERROR (Status)) {
      DEBUG ((
        DEBUG_ERROR,
        "%a: Failed to install the EFI_DEVICE_PATH "
        "protocol on a new handle (Status == %r)\n",
        __func__,
        Status
        ));
      FreePool (DevicePath);
      continue;
    }

    Status = VirtioMmioInstallDevice (RegBase, Handle);
    if (EFI_ERROR (Status)) {
      DEBUG ((
        DEBUG_ERROR,
        "%a: Failed to install VirtIO transport @ 0x%Lx "
        "on handle %p (Status == %r)\n",
        __func__,
        RegBase,
        Handle,
        Status
        ));

      Status = gBS->UninstallProtocolInterface (
                      Handle,
                      &gEfiDevicePathProtocolGuid,
                      DevicePath
                      );
      ASSERT_EFI_ERROR (Status);
      FreePool (DevicePath);
      continue;
    }
  }

  if (EFI_ERROR (FindNodeStatus) && (FindNodeStatus != EFI_NOT_FOUND)) {
    DEBUG ((
      DEBUG_ERROR,
      "%a: Error occurred while iterating DT nodes "
      "(FindNodeStatus == %r)\n",
      __func__,
      FindNodeStatus
      ));
  }

  return EFI_SUCCESS;
}
