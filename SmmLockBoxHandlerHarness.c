#include "edk2-master/MdeModulePkg/Universal/LockBox/SmmLockBox/SmmLockBox.c"
#include <stdint.h>
#include <stddef.h>

void DSE_to_SmmLockBoxHandler()
{
  EFI_HANDLE  DispatchHandle;
  CONST VOID  *RegisterContext;
  UINT32    sym_Command;
  UINTN *CommBufferSize = malloc(sizeof(UINTN)); // Allocate memory for one UINTN.
  
  klee_make_symbolic(CommBufferSize, sizeof(UINTN), "CommBufferSize"); // Make the allocated memory symbolic.

  EFI_SMM_LOCK_BOX_PARAMETER_HEADER *CommBuffer = malloc(sizeof(EFI_SMM_LOCK_BOX_PARAMETER_HEADER)); // Allocate memory for one UINTN.
 
 // klee_make_symbolic(CommBuffer, sizeof(EFI_SMM_LOCK_BOX_PARAMETER_HEADER), "CommBuffer"); // Make the allocated memory symbolic.
  
  klee_make_symbolic(&sym_Command, sizeof(sym_Command), "CommBuffer->Command");
  CommBuffer->Command = sym_Command;

  klee_make_symbolic(&mLocked, sizeof(mLocked), "mLocked");
  SmmLockBoxHandler ( DispatchHandle, RegisterContext, CommBuffer, CommBufferSize);
}