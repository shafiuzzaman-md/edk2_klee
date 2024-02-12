/*++ @file
  This is the code that publishes the CPU I/O Protocol.
  The intent herein is to have a single I/O service that can load
  as early as possible, extend into runtime, and be layered upon by
  the implementations of architectural protocols and the PCI Root
  Bridge I/O Protocol.


Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>
Portions copyright (c) 2011, Apple Inc. All rights reserved.
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiDxe.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Cpu.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/CpuIo2.h"

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdeModulePkg/Include/Library/HiiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiDriverEntryPoint.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmulatorPkg/CpuRuntimeDxe/CpuDriver.h"

#define IA32_MAX_IO_ADDRESS   0xFFFF
#define IA32_MAX_MEM_ADDRESS  0xFFFFFFFF

EFI_STATUS
CpuIoCheckAddressRange (
  IN  EFI_CPU_IO_PROTOCOL_WIDTH  Width,
  IN  UINT64                     Address,
  IN  UINTN                      Count,
  IN  VOID                       *Buffer,
  IN  UINT64                     Limit
  );

EFI_STATUS
EFIAPI
CpuMemoryServiceRead (
  IN  EFI_CPU_IO2_PROTOCOL       *This,
  IN  EFI_CPU_IO_PROTOCOL_WIDTH  Width,
  IN  UINT64                     Address,
  IN  UINTN                      Count,
  IN  OUT VOID                   *Buffer
  )

/*++

Routine Description:

  Perform the Memory Access Read service for the CPU I/O Protocol

Arguments:

  Pointer to an instance of the CPU I/O Protocol
  Width of the Memory Access
  Address of the Memory access
  Count of the number of accesses to perform
  Pointer to the buffer to read or write from memory

Returns:

  Status

  EFI_SUCCESS             - The data was read from or written to the EFI
                            System.
  EFI_INVALID_PARAMETER   - Width is invalid for this EFI System.
  EFI_INVALID_PARAMETER   - Buffer is NULL.
  EFI_UNSUPPORTED         - The Buffer is not aligned for the given Width.
  EFI_UNSUPPORTED         - The address range specified by Address, Width,
                            and Count is not valid for this EFI System.

**/
{
  EFI_STATUS  Status;

  if (!Buffer) {
    return EFI_INVALID_PARAMETER;
  }

  Status = CpuIoCheckAddressRange (Width, Address, Count, Buffer, IA32_MAX_MEM_ADDRESS);
  if (EFI_ERROR (Status)) {
    return Status;
  }

  //
  // Do nothing for Nt32 version
  //
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
CpuMemoryServiceWrite (
  IN EFI_CPU_IO2_PROTOCOL        *This,
  IN  EFI_CPU_IO_PROTOCOL_WIDTH  Width,
  IN  UINT64                     Address,
  IN  UINTN                      Count,
  IN  OUT VOID                   *Buffer
  )

/*++

Routine Description:

  Perform the Memory Access Read service for the CPU I/O Protocol

Arguments:

  Pointer to an instance of the CPU I/O Protocol
  Width of the Memory Access
  Address of the Memory access
  Count of the number of accesses to perform
  Pointer to the buffer to read or write from memory

Returns:

  Status

  EFI_SUCCESS             - The data was read from or written to the EFI System.
  EFI_INVALID_PARAMETER   - Width is invalid for this EFI System.
  EFI_INVALID_PARAMETER   - Buffer is NULL.
  EFI_UNSUPPORTED         - The Buffer is not aligned for the given Width.
  EFI_UNSUPPORTED         - The address range specified by Address, Width, and
                            Count is not valid for this EFI System.

**/
{
  EFI_STATUS  Status;

  if (!Buffer) {
    return EFI_INVALID_PARAMETER;
  }

  Status = CpuIoCheckAddressRange (Width, Address, Count, Buffer, IA32_MAX_MEM_ADDRESS);
  if (EFI_ERROR (Status)) {
    return Status;
  }

  //
  // Do nothing for Nt32 version
  //
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
CpuIoServiceRead (
  IN EFI_CPU_IO2_PROTOCOL        *This,
  IN  EFI_CPU_IO_PROTOCOL_WIDTH  Width,
  IN  UINT64                     UserAddress,
  IN  UINTN                      Count,
  IN  OUT VOID                   *UserBuffer
  )

/*++

Routine Description:

  This is the service that implements the I/O read

Arguments:

  Pointer to an instance of the CPU I/O Protocol
  Width of the Memory Access
  Address of the I/O access
  Count of the number of accesses to perform
  Pointer to the buffer to read or write from I/O space

Returns:

  Status
  EFI_SUCCESS             - The data was read from or written to the EFI System.
  EFI_INVALID_PARAMETER   - Width is invalid for this EFI System.
  EFI_INVALID_PARAMETER   - Buffer is NULL.
  EFI_UNSUPPORTED         - The Buffer is not aligned for the given Width.
  EFI_UNSUPPORTED         - The address range specified by Address, Width, and
                            Count is not valid for this EFI System.
**/
{
  UINTN       Address;
  EFI_STATUS  Status;

  if (!UserBuffer) {
    return EFI_INVALID_PARAMETER;
  }

  Address = (UINTN)UserAddress;

  if (Width >= EfiCpuIoWidthMaximum) {
    return EFI_INVALID_PARAMETER;
  }

  Status = CpuIoCheckAddressRange (Width, Address, Count, UserBuffer, IA32_MAX_IO_ADDRESS);
  if (EFI_ERROR (Status)) {
    return Status;
  }

  //
  // Do nothing for Nt32 version
  //
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
CpuIoServiceWrite (
  IN EFI_CPU_IO2_PROTOCOL        *This,
  IN  EFI_CPU_IO_PROTOCOL_WIDTH  Width,
  IN  UINT64                     UserAddress,
  IN  UINTN                      Count,
  IN  OUT VOID                   *UserBuffer
  )

/*++

Routine Description:


  This is the service that implements the I/O Write

Arguments:

  Pointer to an instance of the CPU I/O Protocol
  Width of the Memory Access
  Address of the I/O access
  Count of the number of accesses to perform
  Pointer to the buffer to read or write from I/O space

Returns:

  Status

  Status
  EFI_SUCCESS             - The data was read from or written to the EFI System.
  EFI_INVALID_PARAMETER   - Width is invalid for this EFI System.
  EFI_INVALID_PARAMETER   - Buffer is NULL.
  EFI_UNSUPPORTED         - The Buffer is not aligned for the given Width.
  EFI_UNSUPPORTED         - The address range specified by Address, Width, and
                            Count is not valid for this EFI System.

**/
{
  UINTN       Address;
  EFI_STATUS  Status;

  if (!UserBuffer) {
    return EFI_INVALID_PARAMETER;
  }

  Address = (UINTN)UserAddress;

  if (Width >= EfiCpuIoWidthMaximum) {
    return EFI_INVALID_PARAMETER;
  }

  Status = CpuIoCheckAddressRange (Width, Address, Count, UserBuffer, IA32_MAX_IO_ADDRESS);
  if (EFI_ERROR (Status)) {
    return Status;
  }

  //
  // Do nothing for Nt32 version
  //
  return EFI_SUCCESS;
}

/*++

Routine Description:

Arguments:

  Width   - TODO: add argument description
  Address - TODO: add argument description
  Count   - TODO: add argument description
  Buffer  - TODO: add argument description
  Limit   - TODO: add argument description

Returns:

  EFI_UNSUPPORTED - TODO: Add description for return value
  EFI_UNSUPPORTED - TODO: Add description for return value
  EFI_UNSUPPORTED - TODO: Add description for return value
  EFI_SUCCESS - TODO: Add description for return value

**/
EFI_STATUS
CpuIoCheckAddressRange (
  IN  EFI_CPU_IO_PROTOCOL_WIDTH  Width,
  IN  UINT64                     Address,
  IN  UINTN                      Count,
  IN  VOID                       *Buffer,
  IN  UINT64                     Limit
  )
{
  UINTN  AlignMask;

  if (Address > Limit) {
    return EFI_UNSUPPORTED;
  }

  //
  // For FiFo type, the target address won't increase during the access, so treat count as 1
  //
  if ((Width >= EfiCpuIoWidthFifoUint8) && (Width <= EfiCpuIoWidthFifoUint64)) {
    Count = 1;
  }

  Width = Width & 0x03;
  if ((Address - 1 + LShiftU64 (Count, Width)) > Limit) {
    return EFI_UNSUPPORTED;
  }

  AlignMask = (1 << Width) - 1;
  if ((UINTN)Buffer & AlignMask) {
    return EFI_UNSUPPORTED;
  }

  return EFI_SUCCESS;
}