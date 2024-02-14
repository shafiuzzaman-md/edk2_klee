#include "edk2-master/MdeModulePkg/Core/PiSmmCore/SmramProfileRecord.c"


DSE_to_SmramProfileHandler()
{
  EFI_HANDLE  DispatchHandle;
  CONST VOID  *RegisterContext;

  SMRAM_PROFILE_PARAMETER_HEADER *CommBuffer = malloc(sizeof(SMRAM_PROFILE_PARAMETER_HEADER)); // Allocate memory
  klee_make_symbolic(CommBuffer, sizeof(SMRAM_PROFILE_PARAMETER_HEADER), "CommBuffer");  // Make the allocated memory symbolic.


  UINTN *CommBufferSize = malloc(sizeof(UINTN)); // Allocate memory.
  klee_make_symbolic(CommBufferSize, sizeof(UINTN), "CommBufferSize"); // Make the allocated memory symbolic.
 
  SmramProfileHandler ( DispatchHandle, RegisterContext, CommBuffer, CommBufferSize);
}