$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/DllSecur.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/DllSecur.h
@@ -1,8 +1,8 @@
 /* DllSecur.h -- DLL loading for security
-2018-02-19 : Igor Pavlov : Public domain */
+2023-03-03 : Igor Pavlov : Public domain */
 
-#ifndef __DLL_SECUR_H
-#define __DLL_SECUR_H
+#ifndef ZIP7_INC_DLL_SECUR_H
+#define ZIP7_INC_DLL_SECUR_H
 
 #include "7zTypes.h"
 
