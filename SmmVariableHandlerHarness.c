#include "edk2-master/MdeModulePkg/Universal/Variable/RuntimeDxe/VariableSmm.c"
#include "edk2-master/MdeModulePkg/Universal/Variable/RuntimeDxe/VariableTraditionalMm.c"

/*Configuration settings are added as enum in edk2*/
VAR_CHECK_REQUEST_SOURCE  mRequestSource = VarCheckFromUntrusted; //categorizing variable check requests as coming from either trusted or untrusted sources
//
// SMM IPL global variables
//
BOOLEAN                    mEndOfDxe  = FALSE;
VARIABLE_MODULE_GLOBAL  *mVariableModuleGlobal;
VARIABLE_STORE_HEADER  *mNvVariableCache = NULL;
EFI_FIRMWARE_VOLUME_HEADER  *mNvFvHeaderCache = NULL;
///
/// The memory entry used for variable statistics data.
///
VARIABLE_INFO_ENTRY  *gVariableInfo = NULL;

DSE_to_SmmVariableHandler()
{
  EFI_HANDLE  DispatchHandle;
  CONST VOID  *RegisterContext;
  UINTN   sym_Function;
  SMM_VARIABLE_COMMUNICATE_HEADER        *CommBuffer = malloc(sizeof(SMM_VARIABLE_COMMUNICATE_HEADER));
  klee_make_symbolic(&sym_Function, sizeof(sym_Function), "CommBuffer->Function");
  CommBuffer->Function = sym_Function;
  
  UINTN *CommBufferSize = malloc(sizeof(UINTN)); // Allocate memory for one UINTN.
  klee_make_symbolic(CommBufferSize, sizeof(UINTN), "CommBufferSize"); // Make the allocated memory symbolic.
  SmmVariableHandler ( DispatchHandle, RegisterContext, CommBuffer, CommBufferSize);
}