/** @file
  Header file for NV data structure definition.

Copyright (c) 2011 - 2018, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __TCG_CONFIG_NV_DATA_H__
#define __TCG_CONFIG_NV_DATA_H__

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Guid/HiiPlatformSetupFormset.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/SecurityPkg/Include/Guid/PhysicalPresenceData.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/SecurityPkg/Include/Guid/TcgConfigHii.h"

#define TCG_CONFIGURATION_VARSTORE_ID  0x0001
#define TCG_CONFIGURATION_FORM_ID      0x0001

#define KEY_TPM_ACTION  0x3000

#define LABEL_TCG_CONFIGURATION_TPM_OPERATION  0x0001
#define LABEL_END                              0xffff

//
// Nv Data structure referenced by IFR
//
typedef struct {
  UINT8      TpmOperation;
  BOOLEAN    TpmEnable;
  BOOLEAN    TpmActivate;
} TCG_CONFIGURATION;

#endif
