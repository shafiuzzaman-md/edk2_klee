#include "edk2-master/MdeModulePkg/Core/PiSmmCore/SmramProfileRecord.c"

//
// Physical pointer to private structure shared between SMM IPL and the SMM Core
//
SMM_CORE_PRIVATE_DATA  *gSmmCorePrivate;
LIST_ENTRY  mSmmPoolLists[SmmPoolTypeMax][MAX_POOL_INDEX];

DSE_to_SmramProfileHandler()
{
  EFI_HANDLE  DispatchHandle;
  CONST VOID  *RegisterContext;

  SMRAM_PROFILE_PARAMETER_HEADER *CommBuffer = malloc(sizeof(SMRAM_PROFILE_PARAMETER_HEADER)); // Allocate memory
  klee_make_symbolic(CommBuffer, sizeof(SMRAM_PROFILE_PARAMETER_HEADER), "CommBuffer");  // Make the allocated memory symbolic.


  UINTN *CommBufferSize = malloc(sizeof(UINTN)); // Allocate memory.
  klee_make_symbolic(CommBufferSize, sizeof(UINTN), "CommBufferSize"); // Make the allocated memory symbolic.
  klee_make_symbolic(&mSmramReadyToLock, sizeof(mSmramReadyToLock), "mSmramReadyToLock"); 
  SmramProfileHandler ( DispatchHandle, RegisterContext, CommBuffer, CommBufferSize);
}