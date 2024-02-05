/** @file
  Mock implementation of the UEFI Runtime Services Table Library.

  Copyright (C) Microsoft Corporation.
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "edk2-master/MdePkg/Include/Uefi.h"

extern EFI_RUNTIME_SERVICES  MockRuntime;

EFI_RUNTIME_SERVICES  *gRT = &MockRuntime;
