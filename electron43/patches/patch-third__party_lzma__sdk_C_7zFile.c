$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/7zFile.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/7zFile.c
@@ -1,5 +1,5 @@
 /* 7zFile.c -- File IO
-2021-04-29 : Igor Pavlov : Public domain */
+2023-04-02 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
@@ -268,7 +268,7 @@ WRes File_Write(CSzFile *p, const void *
       return errno;
     if (processed == 0)
       break;
-    data = (void *)((Byte *)data + (size_t)processed);
+    data = (const void *)((const Byte *)data + (size_t)processed);
     originalSize -= (size_t)processed;
     *size += (size_t)processed;
   }
@@ -287,7 +287,8 @@ WRes File_Seek(CSzFile *p, Int64 *pos, E
   DWORD moveMethod;
   UInt32 low = (UInt32)*pos;
   LONG high = (LONG)((UInt64)*pos >> 16 >> 16); /* for case when UInt64 is 32-bit only */
-  switch (origin)
+  // (int) to eliminate clang warning
+  switch ((int)origin)
   {
     case SZ_SEEK_SET: moveMethod = FILE_BEGIN; break;
     case SZ_SEEK_CUR: moveMethod = FILE_CURRENT; break;
@@ -308,7 +309,7 @@ WRes File_Seek(CSzFile *p, Int64 *pos, E
   
   int moveMethod; // = origin;
 
-  switch (origin)
+  switch ((int)origin)
   {
     case SZ_SEEK_SET: moveMethod = SEEK_SET; break;
     case SZ_SEEK_CUR: moveMethod = SEEK_CUR; break;
@@ -387,10 +388,10 @@ WRes File_GetLength(CSzFile *p, UInt64 *
 
 /* ---------- FileSeqInStream ---------- */
 
-static SRes FileSeqInStream_Read(const ISeqInStream *pp, void *buf, size_t *size)
+static SRes FileSeqInStream_Read(ISeqInStreamPtr pp, void *buf, size_t *size)
 {
-  CFileSeqInStream *p = CONTAINER_FROM_VTBL(pp, CFileSeqInStream, vt);
-  WRes wres = File_Read(&p->file, buf, size);
+  Z7_CONTAINER_FROM_VTBL_TO_DECL_VAR_pp_vt_p(CFileSeqInStream)
+  const WRes wres = File_Read(&p->file, buf, size);
   p->wres = wres;
   return (wres == 0) ? SZ_OK : SZ_ERROR_READ;
 }
@@ -403,18 +404,18 @@ void FileSeqInStream_CreateVTable(CFileS
 
 /* ---------- FileInStream ---------- */
 
-static SRes FileInStream_Read(const ISeekInStream *pp, void *buf, size_t *size)
+static SRes FileInStream_Read(ISeekInStreamPtr pp, void *buf, size_t *size)
 {
-  CFileInStream *p = CONTAINER_FROM_VTBL(pp, CFileInStream, vt);
-  WRes wres = File_Read(&p->file, buf, size);
+  Z7_CONTAINER_FROM_VTBL_TO_DECL_VAR_pp_vt_p(CFileInStream)
+  const WRes wres = File_Read(&p->file, buf, size);
   p->wres = wres;
   return (wres == 0) ? SZ_OK : SZ_ERROR_READ;
 }
 
-static SRes FileInStream_Seek(const ISeekInStream *pp, Int64 *pos, ESzSeek origin)
+static SRes FileInStream_Seek(ISeekInStreamPtr pp, Int64 *pos, ESzSeek origin)
 {
-  CFileInStream *p = CONTAINER_FROM_VTBL(pp, CFileInStream, vt);
-  WRes wres = File_Seek(&p->file, pos, origin);
+  Z7_CONTAINER_FROM_VTBL_TO_DECL_VAR_pp_vt_p(CFileInStream)
+  const WRes wres = File_Seek(&p->file, pos, origin);
   p->wres = wres;
   return (wres == 0) ? SZ_OK : SZ_ERROR_READ;
 }
@@ -428,10 +429,10 @@ void FileInStream_CreateVTable(CFileInSt
 
 /* ---------- FileOutStream ---------- */
 
-static size_t FileOutStream_Write(const ISeqOutStream *pp, const void *data, size_t size)
+static size_t FileOutStream_Write(ISeqOutStreamPtr pp, const void *data, size_t size)
 {
-  CFileOutStream *p = CONTAINER_FROM_VTBL(pp, CFileOutStream, vt);
-  WRes wres = File_Write(&p->file, data, &size);
+  Z7_CONTAINER_FROM_VTBL_TO_DECL_VAR_pp_vt_p(CFileOutStream)
+  const WRes wres = File_Write(&p->file, data, &size);
   p->wres = wres;
   return size;
 }
