$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/7zBuf.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/7zBuf.h
@@ -1,8 +1,8 @@
 /* 7zBuf.h -- Byte Buffer
-2017-04-03 : Igor Pavlov : Public domain */
+2023-03-04 : Igor Pavlov : Public domain */
 
-#ifndef __7Z_BUF_H
-#define __7Z_BUF_H
+#ifndef ZIP7_INC_7Z_BUF_H
+#define ZIP7_INC_7Z_BUF_H
 
 #include "7zTypes.h"
 
