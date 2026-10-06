$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/7z.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/7z.h
@@ -1,8 +1,8 @@
 /* 7z.h -- 7z interface
-2018-07-02 : Igor Pavlov : Public domain */
+2023-04-02 : Igor Pavlov : Public domain */
 
-#ifndef __7Z_H
-#define __7Z_H
+#ifndef ZIP7_INC_7Z_H
+#define ZIP7_INC_7Z_H
 
 #include "7zTypes.h"
 
@@ -98,7 +98,7 @@ typedef struct
 UInt64 SzAr_GetFolderUnpackSize(const CSzAr *p, UInt32 folderIndex);
 
 SRes SzAr_DecodeFolder(const CSzAr *p, UInt32 folderIndex,
-    ILookInStream *stream, UInt64 startPos,
+    ILookInStreamPtr stream, UInt64 startPos,
     Byte *outBuffer, size_t outSize,
     ISzAllocPtr allocMain);
 
@@ -174,7 +174,7 @@ UInt16 *SzArEx_GetFullNameUtf16_Back(con
 
 SRes SzArEx_Extract(
     const CSzArEx *db,
-    ILookInStream *inStream,
+    ILookInStreamPtr inStream,
     UInt32 fileIndex,         /* index of file */
     UInt32 *blockIndex,       /* index of solid block */
     Byte **outBuffer,         /* pointer to pointer to output buffer (allocated with allocMain) */
@@ -196,7 +196,7 @@ SZ_ERROR_INPUT_EOF
 SZ_ERROR_FAIL
 */
 
-SRes SzArEx_Open(CSzArEx *p, ILookInStream *inStream,
+SRes SzArEx_Open(CSzArEx *p, ILookInStreamPtr inStream,
     ISzAllocPtr allocMain, ISzAllocPtr allocTemp);
 
 EXTERN_C_END
