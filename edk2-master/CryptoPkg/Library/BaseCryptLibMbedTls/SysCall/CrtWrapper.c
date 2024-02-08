/** @file
  C Run-Time Libraries (CRT) Wrapper Implementation for MbedTLS-based
  Cryptographic Library.

Copyright (c) 2023, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Base.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/RedfishPkg/PrivateInclude/Crt/stdio.h"

/**dummy mbedtls_printf function. **/
int
mbedtls_printf (
  char const  *fmt,
  ...
  )
{
  ASSERT (FALSE);
  return 0;
}

/**dummy mbedtls_vsnprintf function. **/
int
mbedtls_vsnprintf (
  char        *str,
  size_t      size,
  const char  *format,
  ...
  )
{
  ASSERT (FALSE);
  return 0;
}

/**strchr function. **/
char *
strchr (
  const char  *str,
  int         ch
  )
{
  return ScanMem8 (str, AsciiStrSize (str), (char)ch);
}

/**strcmp function. **/
int
strcmp (
  const char  *s1,
  const char  *s2
  )
{
  return (int)AsciiStrCmp (s1, s2);
}
