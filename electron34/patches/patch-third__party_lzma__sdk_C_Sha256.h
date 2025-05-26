$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Sha256.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Sha256.h
@@ -1,8 +1,8 @@
 /* Sha256.h -- SHA-256 Hash
-2021-01-01 : Igor Pavlov : Public domain */
+: Igor Pavlov : Public domain */
 
-#ifndef __7Z_SHA256_H
-#define __7Z_SHA256_H
+#ifndef ZIP7_INC_SHA256_H
+#define ZIP7_INC_SHA256_H
 
 #include "7zTypes.h"
 
@@ -14,7 +14,10 @@ EXTERN_C_BEGIN
 #define SHA256_BLOCK_SIZE   (SHA256_NUM_BLOCK_WORDS * 4)
 #define SHA256_DIGEST_SIZE  (SHA256_NUM_DIGEST_WORDS * 4)
 
-typedef void (MY_FAST_CALL *SHA256_FUNC_UPDATE_BLOCKS)(UInt32 state[8], const Byte *data, size_t numBlocks);
+
+
+
+typedef void (Z7_FASTCALL *SHA256_FUNC_UPDATE_BLOCKS)(UInt32 state[8], const Byte *data, size_t numBlocks);
 
 /*
   if (the system supports different SHA256 code implementations)
@@ -32,9 +35,16 @@ typedef void (MY_FAST_CALL *SHA256_FUNC_
 
 typedef struct
 {
-  SHA256_FUNC_UPDATE_BLOCKS func_UpdateBlocks;
-  UInt64 count;
-  UInt64 __pad_2[2];
+  union
+  {
+    struct
+    {
+      SHA256_FUNC_UPDATE_BLOCKS func_UpdateBlocks;
+      UInt64 count;
+    } vars;
+    UInt64 _pad_64bit[4];
+    void *_pad_align_ptr[2];
+  } v;
   UInt32 state[SHA256_NUM_DIGEST_WORDS];
 
   Byte buffer[SHA256_BLOCK_SIZE];
@@ -62,7 +72,7 @@ void Sha256_Final(CSha256 *p, Byte *dige
 
 
 
-// void MY_FAST_CALL Sha256_UpdateBlocks(UInt32 state[8], const Byte *data, size_t numBlocks);
+// void Z7_FASTCALL Sha256_UpdateBlocks(UInt32 state[8], const Byte *data, size_t numBlocks);
 
 /*
 call Sha256Prepare() once at program start.
