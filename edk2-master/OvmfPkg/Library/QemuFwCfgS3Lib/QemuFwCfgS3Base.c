/** @file
  Base Null library instance of the QemuFwCfgS3Lib class.

  This library instance returns constant FALSE from QemuFwCfgS3Enabled(), and
  all other library functions trigger assertion failures. It is suitable for
  QEMU targets and machine types that never enable S3.

  Copyright (C) 2017, Red Hat, Inc.

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/OvmfPkg/Include/Library/QemuFwCfgS3Lib.h"

/**
  Determine if S3 support is explicitly enabled.

  @retval  TRUE   If S3 support is explicitly enabled. Other functions in this
                  library may be called (subject to their individual
                  restrictions).

           FALSE  Otherwise. This includes unavailability of the firmware
                  configuration interface. No other function in this library
                  must be called.
**/
BOOLEAN
EFIAPI
QemuFwCfgS3Enabled (
  VOID
  )
{
  return FALSE;
}

/**
  Install the client module's FW_CFG_BOOT_SCRIPT_CALLBACK_FUNCTION callback for
  when the production of ACPI S3 Boot Script opcodes becomes possible.

  Take ownership of the client-provided Context, and pass it to the callback
  function, when the latter is invoked.

  Allocate scratch space for those ACPI S3 Boot Script opcodes to work upon
  that the client will produce in the callback function.

  @param[in] Callback           FW_CFG_BOOT_SCRIPT_CALLBACK_FUNCTION to invoke
                                when the production of ACPI S3 Boot Script
                                opcodes becomes possible. Callback() may be
                                called immediately from
                                QemuFwCfgS3CallWhenBootScriptReady().

  @param[in,out] Context        Client-provided data structure for the
                                Callback() callback function to consume.

                                If Context points to dynamically allocated
                                memory, then Callback() must release it.

                                If Context points to dynamically allocated
                                memory, and
                                QemuFwCfgS3CallWhenBootScriptReady() returns
                                successfully, then the caller of
                                QemuFwCfgS3CallWhenBootScriptReady() must
                                neither dereference nor even evaluate Context
                                any longer, as ownership of the referenced area
                                has been transferred to Callback().

  @param[in] ScratchBufferSize  The size of the scratch buffer that will hold,
                                in reserved memory, all client data read,
                                written, and checked by the ACPI S3 Boot Script
                                opcodes produced by Callback().

  @retval RETURN_UNSUPPORTED       The library instance does not support this
                                   function.

  @retval RETURN_NOT_FOUND         The fw_cfg DMA interface to QEMU is
                                   unavailable.

  @retval RETURN_BAD_BUFFER_SIZE   ScratchBufferSize is too large.

  @retval RETURN_OUT_OF_RESOURCES  Memory allocation failed.

  @retval RETURN_SUCCESS           Callback() has been installed, and the
                                   ownership of Context has been transferred.
                                   Reserved memory has been allocated for the
                                   scratch buffer.

                                   A successful invocation of
                                   QemuFwCfgS3CallWhenBootScriptReady() cannot
                                   be rolled back.

  @return                          Error codes from underlying functions.
**/
RETURN_STATUS
EFIAPI
QemuFwCfgS3CallWhenBootScriptReady (
  IN     FW_CFG_BOOT_SCRIPT_CALLBACK_FUNCTION  *Callback,
  IN OUT VOID                                  *Context           OPTIONAL,
  IN     UINTN                                 ScratchBufferSize
  )
{
  ASSERT (FALSE);
  return RETURN_UNSUPPORTED;
}
