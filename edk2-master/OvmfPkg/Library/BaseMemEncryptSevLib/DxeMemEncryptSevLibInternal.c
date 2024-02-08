/** @file

  Secure Encrypted Virtualization (SEV) library helper function

  Copyright (c) 2017 - 2020, AMD Incorporated. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/Library/MemEncryptSevLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/PcdLib.h"
#include <Register/Amd/Cpuid.h>
#include <Register/Amd/Msr.h>
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/UefiCpuPkg/Include/Register/Cpuid.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi/UefiBaseType.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/ConfidentialComputingGuestAttr.h"

STATIC UINT64   mCurrentAttr            = 0;
STATIC BOOLEAN  mCurrentAttrRead        = FALSE;
STATIC UINT64   mSevEncryptionMask      = 0;
STATIC BOOLEAN  mSevEncryptionMaskSaved = FALSE;

/**
  The function check if the specified Attr is set.

  @param[in]  CurrentAttr   The current attribute.
  @param[in]  Attr          The attribute to check.

  @retval  TRUE      The specified Attr is set.
  @retval  FALSE     The specified Attr is not set.

**/
STATIC
BOOLEAN
AmdMemEncryptionAttrCheck (
  IN  UINT64                             CurrentAttr,
  IN  CONFIDENTIAL_COMPUTING_GUEST_ATTR  Attr
  )
{
  switch (Attr) {
    case CCAttrAmdSev:
      //
      // SEV is automatically enabled if SEV-ES or SEV-SNP is active.
      //
      return CurrentAttr >= CCAttrAmdSev;
    case CCAttrAmdSevEs:
      //
      // SEV-ES is automatically enabled if SEV-SNP is active.
      //
      return CurrentAttr >= CCAttrAmdSevEs;
    case CCAttrAmdSevSnp:
      return CurrentAttr == CCAttrAmdSevSnp;
    default:
      return FALSE;
  }
}

/**
  Check if the specified confidential computing attribute is active.

  @param[in]  Attr          The attribute to check.

  @retval TRUE   The specified Attr is active.
  @retval FALSE  The specified Attr is not active.

**/
STATIC
BOOLEAN
EFIAPI
ConfidentialComputingGuestHas (
  IN  CONFIDENTIAL_COMPUTING_GUEST_ATTR  Attr
  )
{
  //
  // Get the current CC attribute.
  //
  // We avoid reading the PCD on every check because this routine could be indirectly
  // called during the virtual pointer conversion. And its not safe to access the
  // PCDs during the virtual pointer conversion.
  //
  if (!mCurrentAttrRead) {
    mCurrentAttr     = PcdGet64 (PcdConfidentialComputingGuestAttr);
    mCurrentAttrRead = TRUE;
  }

  //
  // If attr is for the AMD group then call AMD specific checks.
  //
  if (((RShiftU64 (mCurrentAttr, 8)) & 0xff) == 1) {
    return AmdMemEncryptionAttrCheck (mCurrentAttr, Attr);
  }

  return (mCurrentAttr == Attr);
}

/**
  Returns a boolean to indicate whether SEV-SNP is enabled.

  @retval TRUE           SEV-SNP is enabled
  @retval FALSE          SEV-SNP is not enabled
**/
BOOLEAN
EFIAPI
MemEncryptSevSnpIsEnabled (
  VOID
  )
{
  return ConfidentialComputingGuestHas (CCAttrAmdSevSnp);
}

/**
  Returns a boolean to indicate whether SEV-ES is enabled.

  @retval TRUE           SEV-ES is enabled
  @retval FALSE          SEV-ES is not enabled
**/
BOOLEAN
EFIAPI
MemEncryptSevEsIsEnabled (
  VOID
  )
{
  return ConfidentialComputingGuestHas (CCAttrAmdSevEs);
}

/**
  Returns a boolean to indicate whether SEV is enabled.

  @retval TRUE           SEV is enabled
  @retval FALSE          SEV is not enabled
**/
BOOLEAN
EFIAPI
MemEncryptSevIsEnabled (
  VOID
  )
{
  return ConfidentialComputingGuestHas (CCAttrAmdSev);
}

/**
  Returns the SEV encryption mask.

  @return  The SEV pagtable encryption mask
**/
UINT64
EFIAPI
MemEncryptSevGetEncryptionMask (
  VOID
  )
{
  if (!mSevEncryptionMaskSaved) {
    mSevEncryptionMask      = PcdGet64 (PcdPteMemoryEncryptionAddressOrMask);
    mSevEncryptionMaskSaved = TRUE;
  }

  return mSevEncryptionMask;
}
