#include "klee/klee.h"

#include "edk2-master/MdePkg/Include/X64/ProcessorBind.h"
#include "edk2-master/MdePkg/Include/Uefi/UefiBaseType.h"
#include "edk2-master/MdePkg/Include/Uefi/UefiMultiPhase.h"
#include "edk2-master/BaseTools/Source/C/Include/Common/PiFirmwareVolume.h"
#include "edk2-master/MdeModulePkg/Include/Protocol/FaultTolerantWrite.h"
#include "edk2-master/MdePkg/Include/Uefi/UefiSpec.h"
#include "edk2-master/MdePkg/Include/Protocol/DriverBinding.h"
#include "edk2-master/MdePkg/Include/Protocol/ComponentName.h"
#include "edk2-master/MdePkg/Include/Protocol/ComponentName2.h"
#include "edk2-master/MdePkg/Include/IndustryStandard/Pci22.h"
#include "edk2-master/BaseTools/Source/C/Include/Protocol/GraphicsOutput.h"
#include "edk2-master/MdeModulePkg/Bus/Pci/PciBusDxe/PciBus.h"

#define _PCD_GET_MODE_BOOL_PcdReclaimVariableSpaceAtEndOfDxe TRUE
#define _PCD_GET_MODE_BOOL_PcdEmuVariableNvModeEnable TRUE
#define PcdGetBool(TokenName) _PCD_GET_MODE_BOOL_ ## TokenName

#include "edk2-master/MdeModulePkg/Universal/Variable/RuntimeDxe/VariableSmm.c"

//STUBS for configuration settings

/*Configuration settings are added as enum in edk2*/
VAR_CHECK_REQUEST_SOURCE  mRequestSource = VarCheckFromUntrusted; //categorizing variable check requests as coming from either trusted or untrusted sources
/*gMmst is a global variable that points to the SMM System Table (EFI_SMM_SYSTEM_TABLE2 or Smst).*/
EFI_MM_SYSTEM_TABLE  *gMmst = NULL;

/*This protocol provides boot-time service to do fault tolerant write capability for block devices in SMM environment. This default value is copied from MdeModulePkg.dec*/
EFI_GUID  gEfiSmmFaultTolerantWriteProtocolGuid = { 0x3868fc3b, 0x7e45, 0x43a7, { 0x90, 0x6c, 0x4b, 0xa4, 0x7d, 0xe1, 0x75, 0x4d }};
/*This protocol is similar with DXE FVB protocol and used in the UEFI SMM evvironment. This default value is copied from MdeModulePkg.dec*/

EFI_GUID  gEfiSmmFirmwareVolumeBlockProtocolGuid = { 0xd326d041, 0xbd31, 0x4c01, { 0xb5, 0xa8, 0x62, 0x8b, 0xe8, 0x7f, 0x6, 0x53 }};

//This protocol is intended for use as a means to store data in the EFI SMM environment.
EFI_GUID  gEfiSmmVariableProtocolGuid = { 0xed32d533, 0x99e6, 0x4209, { 0x9c, 0xc0, 0x2d, 0x72, 0xcd, 0xd9, 0x98, 0xa7 }};

EFI_GUID gEdkiiSmmVarCheckProtocolGuid  = { 0xb0d8f3c1, 0xb7de, 0x4c11, { 0xbc, 0x89, 0x2f, 0xb5, 0x62, 0xc8, 0xc4, 0x11 } };
EFI_GUID  gEfiMmEndOfDxeProtocolGuid;

///
/// The memory entry used for variable statistics data.
///
VARIABLE_INFO_ENTRY  *gVariableInfo = NULL;

//
// SMM IPL global variables
//
BOOLEAN                    mEndOfDxe  = FALSE;
VARIABLE_MODULE_GLOBAL  *mVariableModuleGlobal;
VARIABLE_STORE_HEADER  *mNvVariableCache = NULL;
EFI_FIRMWARE_VOLUME_HEADER  *mNvFvHeaderCache = NULL;


DSE_to_SmmVariableHandler()
{
  EFI_HANDLE  DispatchHandle;
  CONST VOID  *RegisterContext;
  VOID        *CommBuffer;
  UINTN *CommBufferSize = malloc(sizeof(UINTN)); // Allocate memory for one UINTN.
  if (CommBufferSize == NULL) {
      // Handle memory allocation failure if needed
  }
  klee_make_symbolic(CommBufferSize, sizeof(UINTN), "CommBufferSize"); // Make the allocated memory symbolic.

  SmmVariableHandler ( DispatchHandle, RegisterContext, CommBuffer, CommBufferSize);
}

int main()
{
  DSE_to_SmmVariableHandler();
}