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
#include "edk2-master/MdePkg/Library/SmmMemLib/SmmMemLib.c"

#define SMRAM_BASE 0x1F000000 // Hypothetical SMRAM base address
#define SMRAM_SIZE 0x00100000 // Hypothetical SMRAM size (1MB)

//
//Constant value assigned for variables depend on PCD (Platform Configuration Database)
//
#define _PCD_GET_MODE_BOOL_PcdReclaimVariableSpaceAtEndOfDxe TRUE
#define _PCD_GET_MODE_BOOL_PcdEmuVariableNvModeEnable TRUE
#define _PCD_GET_MODE_64_PcdMemoryProfileMemoryType TRUE
#define _PCD_GET_MODE_PTR_PcdMemoryProfileDriverPath TRUE
#define _PCD_GET_MODE_SIZE_PcdMemoryProfileDriverPath TRUE
#define _PCD_GET_MODE_8_PcdMemoryProfilePropertyMask TRUE
#define _PCD_GET_MODE_32_PcdLoadFixAddressSmmCodePageNumber TRUE
#define _PCD_GET_MODE_64_PcdLoadModuleAtFixAddressEnable TRUE
#define _PCD_GET_MODE_64_PcdLoadModuleAtFixAddressEnable TRUE
#define _PCD_GET_MODE_64_PcdLoadModuleAtFixAddressEnable TRUE
#define _PCD_GET_MODE_32_PcdLoadFixAddressSmmCodePageNumber TRUE
#define  PCD_GET_MODE_8_PcdHeapGuardPropertyMask TRUE
#define _PCD_GET_MODE_8_PcdHeapGuardPropertyMask TRUE
#define IS_SMRAM_PROFILE_ENABLED        FALSE
#define IS_UEFI_MEMORY_PROFILE_ENABLED  FALSE
#define gEfiSmmConfigurationProtocolGuid TRUE;

/*NULL assigned in system table pointers*/
EFI_MM_SYSTEM_TABLE  *gMmst = NULL; //MM System Table 
EFI_SMM_SYSTEM_TABLE2  *gSmst = NULL; //System Management System Table
EFI_BOOT_SERVICES  *gBS         = NULL; //EFI Boot Services Table
EFI_DXE_SERVICES  *gDS = NULL; //DXE Services Table

//
//Default value assigned for protocol GUID
//

/*This protocol provides boot-time service to do fault tolerant write capability for block devices in SMM environment. This default value is copied from MdeModulePkg.dec*/
EFI_GUID  gEfiSmmFaultTolerantWriteProtocolGuid = { 0x3868fc3b, 0x7e45, 0x43a7, { 0x90, 0x6c, 0x4b, 0xa4, 0x7d, 0xe1, 0x75, 0x4d }};
/*This protocol is similar with DXE FVB protocol and used in the UEFI SMM evvironment. This default value is copied from MdeModulePkg.dec*/
EFI_GUID  gEfiSmmFirmwareVolumeBlockProtocolGuid = { 0xd326d041, 0xbd31, 0x4c01, { 0xb5, 0xa8, 0x62, 0x8b, 0xe8, 0x7f, 0x6, 0x53 }};
//This protocol is intended for use as a means to store data in the EFI SMM environment.
EFI_GUID  gEfiSmmVariableProtocolGuid = { 0xed32d533, 0x99e6, 0x4209, { 0x9c, 0xc0, 0x2d, 0x72, 0xcd, 0xd9, 0x98, 0xa7 }};
EFI_GUID gEdkiiSmmVarCheckProtocolGuid  = { 0xb0d8f3c1, 0xb7de, 0x4c11, { 0xbc, 0x89, 0x2f, 0xb5, 0x62, 0xc8, 0xc4, 0x11 } };
EFI_GUID  gEfiMmEndOfDxeProtocolGuid;
// ## Include/Guid/SmmLockBox.h
EFI_GUID  gEfiSmmLockBoxCommunicationGuid    = { 0x2a3cfebd, 0x27e8, 0x4d0a, { 0x8b, 0x79, 0xd6, 0x88, 0xc2, 0xa3, 0xe1, 0xc0 }};
//## Include/Protocol/SmmReadyToLock.h
EFI_GUID  gEfiSmmReadyToLockProtocolGuid  = { 0x47b7fa8c, 0xf4bd, 0x4af6, { 0x82, 0x00, 0x33, 0x30, 0x86, 0xf0, 0xd2, 0xc8 }};
// ## Include/Protocol/LockBox.h
EFI_GUID  gEfiLockBoxProtocolGuid        = { 0xbd445d79, 0xb7ad, 0x4f04, { 0x9a, 0xd8, 0x29, 0xbd, 0x20, 0x40, 0xeb, 0x3c }};
//## Include/Guid/MemoryAttributesTable.h
EFI_GUID  gEfiMemoryAttributesTableGuid        = { 0xdcfa911d, 0x26eb, 0x469f, {0xa2, 0x20, 0x38, 0xb7, 0xdc, 0x46, 0x12, 0x20}};
// ## Include/Protocol/SmmAccess2.h
EFI_GUID  gEfiSmmAccess2ProtocolGuid      = { 0xc2702b74, 0x800c, 0x4131, { 0x87, 0x46, 0x8f, 0xb5, 0xb8, 0x9c, 0xe4, 0xac }};
// ## Include/Protocol/SmmEndOfDxe.h
EFI_GUID  gEfiSmmEndOfDxeProtocolGuid = { 0x24e70042, 0xd5c5, 0x4260, { 0x8c, 0x39, 0xa, 0xd3, 0xaa, 0x32, 0xe9, 0x3d }};
//## This protocol is used to abstract the swap operation of boot block and backup block of boot FV in SMM environment.
//  #  Include/Protocol/SmmSwapAddressRange.h
EFI_GUID  gEfiSmmSwapAddressRangeProtocolGuid = { 0x67c4f112, 0x3385, 0x4e55, { 0x9c, 0x5b, 0xc0, 0x5b, 0x71, 0x7c, 0x42, 0x28 }};


//
//Global variables
//
LIST_ENTRY  mSmmMemoryMap;
LIST_ENTRY  mSmmPoolLists[SmmPoolTypeMax][MAX_POOL_INDEX];
UINTN                 mFullSmramRangeCount;
//Global pointer used to access mSmmCorePrivateData from outside and inside SMM
SMM_CORE_PRIVATE_DATA  *gSmmCorePrivate;
EFI_SMRAM_DESCRIPTOR  *mFullSmramRanges;


//
//Stubs for nonrelevant functions detected by static analysis
//
BOOLEAN
EFIAPI
DebugPrintEnabled (
  VOID
  )
{
  return 0;
}

//#include "vul1_harness.c"
//#include "SMRAM_exposure_harness.c"
//#include "Harness_SmmFaultTolerantWriteHandler.c"
#include "SmramProfileHandlerHarness.c"

int main()
{
  // DSE_to_SmmVariableHandler();
  // DSE_to_SmmLockBoxHandler();
  // DSE_to_SmmFaultTolerantWriteHandler();
  DSE_to_SmramProfileHandler();
}