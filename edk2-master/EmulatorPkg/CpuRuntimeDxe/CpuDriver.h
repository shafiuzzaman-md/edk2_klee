/*++ @file

Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>
Portions copyright (c) 2011, Apple Inc. All rights reserved.

SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _CPU_ARCHITECTURAL_PROTOCOL_DRIVER_H_
#define _CPU_ARCHITECTURAL_PROTOCOL_DRIVER_H_

#include "edk2-master/MdePkg/Include/PiDxe.h"
#include "edk2-master/MdePkg/Include/IndustryStandard/SmBios.h"

#include "edk2-master/MdePkg/Include/Protocol/Cpu.h"
#include "edk2-master/MdePkg/Include/Protocol/Smbios.h"
#include "edk2-master/MdePkg/Include/Protocol/MpService.h"
#include "edk2-master/EmulatorPkg/Include/Protocol/EmuThread.h"
#include "edk2-master/MdePkg/Include/Protocol/CpuIo2.h"

#include "edk2-master/MdeModulePkg/Include/Guid/IdleLoopEvent.h"

#include "edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiDriverEntryPoint.h"
#include "edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "edk2-master/EmulatorPkg/Include/Library/EmuThunkLib.h"
#include "edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "edk2-master/MdePkg/Include/Library/PcdLib.h"

//
// Internal Data Structures
//
#define CPU_ARCH_PROT_PRIVATE_SIGNATURE  SIGNATURE_32 ('c', 'a', 'p', 'd')

typedef struct {
  UINTN                    Signature;
  EFI_HANDLE               Handle;

  EFI_CPU_ARCH_PROTOCOL    Cpu;
  EFI_CPU_IO2_PROTOCOL     CpuIo;

  //
  // Local Data for CPU interface goes here
  //
  BOOLEAN                  InterruptState;
} CPU_ARCH_PROTOCOL_PRIVATE;

#define CPU_ARCH_PROTOCOL_PRIVATE_DATA_FROM_THIS(a) \
  CR (a, \
      CPU_ARCH_PROTOCOL_PRIVATE, \
      Cpu, \
      CPU_ARCH_PROT_PRIVATE_SIGNATURE \
      )

typedef enum {
  CPU_STATE_IDLE,
  CPU_STATE_BLOCKED,
  CPU_STATE_READY,
  CPU_STATE_BUSY,
  CPU_STATE_FINISHED
} PROCESSOR_STATE;

//
// Define Individual Processor Data block.
//
typedef struct {
  EFI_PROCESSOR_INFORMATION    Info;
  EFI_AP_PROCEDURE             Procedure;
  VOID                         *Parameter;
  VOID                         *StateLock;
  VOID                         *ProcedureLock;
  PROCESSOR_STATE              State;
  EFI_EVENT                    CheckThisAPEvent;
} PROCESSOR_DATA_BLOCK;

//
// Define MP data block which consumes individual processor block.
//
typedef struct {
  UINTN                   NumberOfProcessors;
  UINTN                   NumberOfEnabledProcessors;
  EFI_EVENT               CheckAllAPsEvent;
  EFI_EVENT               WaitEvent;
  UINTN                   FinishCount;
  UINTN                   StartCount;
  EFI_AP_PROCEDURE        Procedure;
  VOID                    *ProcedureArgument;
  BOOLEAN                 SingleThread;
  UINTN                   StartedNumber;
  PROCESSOR_DATA_BLOCK    *ProcessorData;
  UINTN                   Timeout;
  UINTN                   *FailedList;
  UINTN                   FailedListIndex;
  BOOLEAN                 TimeoutActive;
} MP_SYSTEM_DATA;

EFI_STATUS
EFIAPI
CpuMemoryServiceRead (
  IN  EFI_CPU_IO2_PROTOCOL       *This,
  IN  EFI_CPU_IO_PROTOCOL_WIDTH  Width,
  IN  UINT64                     Address,
  IN  UINTN                      Count,
  IN  OUT VOID                   *Buffer
  );

EFI_STATUS
EFIAPI
CpuMemoryServiceWrite (
  IN EFI_CPU_IO2_PROTOCOL        *This,
  IN  EFI_CPU_IO_PROTOCOL_WIDTH  Width,
  IN  UINT64                     Address,
  IN  UINTN                      Count,
  IN  OUT VOID                   *Buffer
  );

EFI_STATUS
EFIAPI
CpuIoServiceRead (
  IN EFI_CPU_IO2_PROTOCOL        *This,
  IN  EFI_CPU_IO_PROTOCOL_WIDTH  Width,
  IN  UINT64                     UserAddress,
  IN  UINTN                      Count,
  IN  OUT VOID                   *UserBuffer
  );

EFI_STATUS
EFIAPI
CpuIoServiceWrite (
  IN EFI_CPU_IO2_PROTOCOL        *This,
  IN  EFI_CPU_IO_PROTOCOL_WIDTH  Width,
  IN  UINT64                     UserAddress,
  IN  UINTN                      Count,
  IN  OUT VOID                   *UserBuffer
  );

EFI_STATUS
EFIAPI
InitializeCpu (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

EFI_STATUS
EFIAPI
EmuFlushCpuDataCache (
  IN EFI_CPU_ARCH_PROTOCOL  *This,
  IN EFI_PHYSICAL_ADDRESS   Start,
  IN UINT64                 Length,
  IN EFI_CPU_FLUSH_TYPE     FlushType
  );

EFI_STATUS
EFIAPI
EmuEnableInterrupt (
  IN EFI_CPU_ARCH_PROTOCOL  *This
  );

EFI_STATUS
EFIAPI
EmuDisableInterrupt (
  IN EFI_CPU_ARCH_PROTOCOL  *This
  );

EFI_STATUS
EFIAPI
EmuGetInterruptState (
  IN EFI_CPU_ARCH_PROTOCOL  *This,
  OUT BOOLEAN               *State
  );

EFI_STATUS
EFIAPI
EmuInit (
  IN EFI_CPU_ARCH_PROTOCOL  *This,
  IN EFI_CPU_INIT_TYPE      InitType
  );

EFI_STATUS
EFIAPI
EmuRegisterInterruptHandler (
  IN EFI_CPU_ARCH_PROTOCOL      *This,
  IN EFI_EXCEPTION_TYPE         InterruptType,
  IN EFI_CPU_INTERRUPT_HANDLER  InterruptHandler
  );

EFI_STATUS
EFIAPI
EmuGetTimerValue (
  IN  EFI_CPU_ARCH_PROTOCOL  *This,
  IN  UINT32                 TimerIndex,
  OUT UINT64                 *TimerValue,
  OUT UINT64                 *TimerPeriod OPTIONAL
  );

EFI_STATUS
EFIAPI
EmuSetMemoryAttributes (
  IN EFI_CPU_ARCH_PROTOCOL  *This,
  IN EFI_PHYSICAL_ADDRESS   BaseAddress,
  IN UINT64                 Length,
  IN UINT64                 Attributes
  );

EFI_STATUS
CpuMpServicesInit (
  OUT UINTN  *MaxCores
  );

EFI_STATUS
EFIAPI
CpuMpServicesWhoAmI (
  IN EFI_MP_SERVICES_PROTOCOL  *This,
  OUT UINTN                    *ProcessorNumber
  );

extern EFI_MP_SERVICES_PROTOCOL  mMpServicesTemplate;

#endif
