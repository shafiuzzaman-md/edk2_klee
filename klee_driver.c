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


int main()
{

}