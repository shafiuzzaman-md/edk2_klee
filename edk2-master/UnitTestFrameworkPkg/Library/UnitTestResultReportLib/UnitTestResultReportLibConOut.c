/** @file
  Implement UnitTestResultReportLib doing plain txt out to console

  Copyright (c) Microsoft Corporation.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PrintLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"

VOID
EFIAPI
ReportPrint (
  IN CONST CHAR8  *Format,
  ...
  )
{
  VA_LIST  Marker;
  CHAR16   String[256];
  UINTN    Length;

  VA_START (Marker, Format);
  Length = UnicodeVSPrintAsciiFormat (String, sizeof (String), Format, Marker);
  if (Length == 0) {
    DEBUG ((DEBUG_ERROR, "%a formatted string is too long\n", __func__));
  } else {
    gST->ConOut->OutputString (gST->ConOut, String);
  }

  VA_END (Marker);
}

VOID
ReportOutput (
  IN CONST CHAR8  *Output
  )
{
  CHAR8  AsciiString[128];
  UINTN  Length;
  UINTN  Index;

  Length = AsciiStrLen (Output);
  for (Index = 0; Index < Length; Index += (sizeof (AsciiString) - 1)) {
    AsciiStrnCpyS (AsciiString, sizeof (AsciiString), &Output[Index], sizeof (AsciiString) - 1);
    ReportPrint ("%a", AsciiString);
  }
}