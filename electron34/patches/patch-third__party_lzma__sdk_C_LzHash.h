$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/LzHash.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/LzHash.h
@@ -1,8 +1,8 @@
-/* LzHash.h -- HASH functions for LZ algorithms
-2019-10-30 : Igor Pavlov : Public domain */
+/* LzHash.h -- HASH constants for LZ algorithms
+2023-03-05 : Igor Pavlov : Public domain */
 
-#ifndef __LZ_HASH_H
-#define __LZ_HASH_H
+#ifndef ZIP7_INC_LZ_HASH_H
+#define ZIP7_INC_LZ_HASH_H
 
 /*
   (kHash2Size >= (1 <<  8)) : Required
