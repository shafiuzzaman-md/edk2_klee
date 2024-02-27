#include "edk2-master/MdeModulePkg/Universal/FaultTolerantWriteDxe/FaultTolerantWriteSmm.c"

DSE_to_SmmFaultTolerantWriteHandler()
{
  EFI_HANDLE  DispatchHandle;
  CONST VOID  *RegisterContext;
  VOID        *CommBuffer = malloc(sizeof(VOID));
  UINTN *CommBufferSize = malloc(sizeof(UINTN)); 
 
  klee_make_symbolic(CommBuffer, sizeof(VOID), "CommBuffer"); 
  klee_make_symbolic(CommBufferSize, sizeof(UINTN), "CommBufferSize");
  SmmFaultTolerantWriteHandler ( DispatchHandle, RegisterContext, CommBuffer, CommBufferSize);
}