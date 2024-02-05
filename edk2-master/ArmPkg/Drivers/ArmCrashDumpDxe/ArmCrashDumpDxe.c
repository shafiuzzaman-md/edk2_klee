/** @file

  Copyright (c) 2017, Linaro, Ltd. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "edk2-master/MdePkg/Include/PiDxe.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/ArmPkg/Include/Library/DefaultExceptionHandlerLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/MdePkg/Include/Protocol/Cpu.h"

STATIC EFI_CPU_ARCH_PROTOCOL  *mCpu;

EFI_STATUS
EFIAPI
ArmCrashDumpDxeInitialize (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS  Status;

  Status = gBS->LocateProtocol (&gEfiCpuArchProtocolGuid, NULL, (VOID **)&mCpu);
  ASSERT_EFI_ERROR (Status);

  return mCpu->RegisterInterruptHandler (
                 mCpu,
                 EXCEPT_AARCH64_SYNCHRONOUS_EXCEPTIONS,
                 &DefaultExceptionHandler
                 );
}
