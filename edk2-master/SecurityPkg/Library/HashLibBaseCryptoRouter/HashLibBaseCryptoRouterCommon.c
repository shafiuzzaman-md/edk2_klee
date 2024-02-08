/** @file
  This is BaseCrypto router support function.

Copyright (c) 2013 - 2016, Intel Corporation. All rights reserved. <BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/PiPei.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/SecurityPkg/Include/Library/Tpm2CommandLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/SecurityPkg/Include/Library/HashLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Tcg2Protocol.h"

typedef struct {
  EFI_GUID    Guid;
  UINT32      Mask;
} TPM2_HASH_MASK;

TPM2_HASH_MASK  mTpm2HashMask[] = {
  { HASH_ALGORITHM_SHA1_GUID,    HASH_ALG_SHA1    },
  { HASH_ALGORITHM_SHA256_GUID,  HASH_ALG_SHA256  },
  { HASH_ALGORITHM_SHA384_GUID,  HASH_ALG_SHA384  },
  { HASH_ALGORITHM_SHA512_GUID,  HASH_ALG_SHA512  },
  { HASH_ALGORITHM_SM3_256_GUID, HASH_ALG_SM3_256 },
};

/**
  The function get hash mask info from algorithm.

  @param HashGuid Hash Guid

  @return HashMask
**/
UINT32
EFIAPI
Tpm2GetHashMaskFromAlgo (
  IN EFI_GUID  *HashGuid
  )
{
  UINTN  Index;

  for (Index = 0; Index < sizeof (mTpm2HashMask)/sizeof (mTpm2HashMask[0]); Index++) {
    if (CompareGuid (HashGuid, &mTpm2HashMask[Index].Guid)) {
      return mTpm2HashMask[Index].Mask;
    }
  }

  return 0;
}

/**
  The function set digest to digest list.

  @param DigestList digest list
  @param Digest     digest data
**/
VOID
EFIAPI
Tpm2SetHashToDigestList (
  IN OUT TPML_DIGEST_VALUES  *DigestList,
  IN TPML_DIGEST_VALUES      *Digest
  )
{
  CopyMem (
    &DigestList->digests[DigestList->count],
    &Digest->digests[0],
    sizeof (Digest->digests[0])
    );
  DigestList->count++;
}
