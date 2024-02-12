/** @file
  The header files of Http Utilities functions for HttpUtilities driver.

  Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>
  (C) Copyright 2016 Hewlett Packard Enterprise Development LP<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __EFI_HTTP_UTILITIES_DXE_H__
#define __EFI_HTTP_UTILITIES_DXE_H__

#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Uefi.h"

//
// Libraries
//
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiBootServicesTableLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/MemoryAllocationLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseMemoryLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/BaseLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/UefiLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Library/DebugLib.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/NetworkPkg/Include/Library/HttpLib.h"

//
// Consumed Protocols
//
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/HttpUtilities.h"
#include "/home/mdshafiuzzaman/Research/ISSTA24/Experiments/edk2_klee/edk2-master/MdePkg/Include/Protocol/Http.h"

//
// Protocol instances
//
extern EFI_HTTP_UTILITIES_PROTOCOL  mHttpUtilitiesProtocol;

/**
  Create HTTP header based on a combination of seed header, fields
  to delete, and fields to append.

  The Build() function is used to manage the headers portion of an
  HTTP message by providing the ability to add, remove, or replace
  HTTP headers.

  @param[in]  This                Pointer to EFI_HTTP_UTILITIES_PROTOCOL instance.
  @param[in]  SeedMessageSize     Size of the initial HTTP header. This can be zero.
  @param[in]  SeedMessage         Initial HTTP header to be used as a base for
                                  building a new HTTP header. If NULL,
                                  SeedMessageSize is ignored.
  @param[in]  DeleteCount         Number of null-terminated HTTP header field names
                                  in DeleteList.
  @param[in]  DeleteList          List of null-terminated HTTP header field names to
                                  remove from SeedMessage. Only the field names are
                                  in this list because the field values are irrelevant
                                  to this operation.
  @param[in]  AppendCount         Number of header fields in AppendList.
  @param[in]  AppendList          List of HTTP headers to populate NewMessage with.
                                  If SeedMessage is not NULL, AppendList will be
                                  appended to the existing list from SeedMessage in
                                  NewMessage.
  @param[out] NewMessageSize      Pointer to number of header fields in NewMessage.
  @param[out] NewMessage          Pointer to a new list of HTTP headers based on.

  @retval EFI_SUCCESS             Add, remove, and replace operations succeeded.
  @retval EFI_OUT_OF_RESOURCES    Could not allocate memory for NewMessage.
  @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:
                                  This is NULL.
**/
EFI_STATUS
EFIAPI
HttpUtilitiesBuild (
  IN     EFI_HTTP_UTILITIES_PROTOCOL  *This,
  IN     UINTN                        SeedMessageSize,
  IN     VOID                         *SeedMessage  OPTIONAL,
  IN     UINTN                        DeleteCount,
  IN     CHAR8                        *DeleteList[]  OPTIONAL,
  IN     UINTN                        AppendCount,
  IN     EFI_HTTP_HEADER              *AppendList[]  OPTIONAL,
  OUT UINTN                           *NewMessageSize,
  OUT VOID                            **NewMessage
  );

/**
  Parses HTTP header and produces an array of key/value pairs.

  The Parse() function is used to transform data stored in HttpHeader
  into a list of fields paired with their corresponding values.

  @param[in]  This                Pointer to EFI_HTTP_UTILITIES_PROTOCOL instance.
  @param[in]  HttpMessage         Contains raw unformatted HTTP header string.
  @param[in]  HttpMessageSize     Size of HTTP header.
  @param[out] HeaderFields        Array of key/value header pairs.
  @param[out] FieldCount          Number of headers in HeaderFields.

  @retval EFI_SUCCESS             Allocation succeeded.
  @retval EFI_NOT_STARTED         This EFI HTTP Protocol instance has not been
                                  initialized.
  @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:
                                  This is NULL.
                                  HttpMessage is NULL.
                                  HeaderFields is NULL.
                                  FieldCount is NULL.
**/
EFI_STATUS
EFIAPI
HttpUtilitiesParse (
  IN  EFI_HTTP_UTILITIES_PROTOCOL  *This,
  IN  CHAR8                        *HttpMessage,
  IN  UINTN                        HttpMessageSize,
  OUT EFI_HTTP_HEADER              **HeaderFields,
  OUT UINTN                        *FieldCount
  );

#endif