/** @file

  Copyright (c) 2013-2014, ARM Ltd. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __ANDROID_FASTBOOT_APP_H__
#define __ANDROID_FASTBOOT_APP_H__

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/EmbeddedPkg/Include/Library/AndroidBootImgLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"

#define BOOTIMG_KERNEL_ARGS_SIZE  512

#define ANDROID_FASTBOOT_VERSION  "0.4"

EFI_STATUS
BootAndroidBootImg (
  IN  UINTN  BufferSize,
  IN  VOID   *Buffer
  );

EFI_STATUS
ParseAndroidBootImg (
  IN  VOID   *BootImg,
  OUT VOID   **Kernel,
  OUT UINTN  *KernelSize,
  OUT VOID   **Ramdisk,
  OUT UINTN  *RamdiskSize,
  OUT CHAR8  *KernelArgs
  );

#endif //ifdef __ANDROID_FASTBOOT_APP_H__