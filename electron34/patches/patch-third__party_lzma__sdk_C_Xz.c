$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Xz.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Xz.c
@@ -1,5 +1,5 @@
 /* Xz.c - Xz
-2021-02-09 : Igor Pavlov : Public domain */
+2024-03-01 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
@@ -52,6 +52,7 @@ void XzCheck_Init(CXzCheck *p, unsigned 
     case XZ_CHECK_CRC32: p->crc = CRC_INIT_VAL; break;
     case XZ_CHECK_CRC64: p->crc64 = CRC64_INIT_VAL; break;
     case XZ_CHECK_SHA256: Sha256_Init(&p->sha); break;
+    default: break;
   }
 }
 
@@ -62,6 +63,7 @@ void XzCheck_Update(CXzCheck *p, const v
     case XZ_CHECK_CRC32: p->crc = CrcUpdate(p->crc, data, size); break;
     case XZ_CHECK_CRC64: p->crc64 = Crc64Update(p->crc64, data, size); break;
     case XZ_CHECK_SHA256: Sha256_Update(&p->sha, (const Byte *)data, size); break;
+    default: break;
   }
 }
 
@@ -70,7 +72,7 @@ int XzCheck_Final(CXzCheck *p, Byte *dig
   switch (p->mode)
   {
     case XZ_CHECK_CRC32:
-      SetUi32(digest, CRC_GET_DIGEST(p->crc));
+      SetUi32(digest, CRC_GET_DIGEST(p->crc))
       break;
     case XZ_CHECK_CRC64:
     {
