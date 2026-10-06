$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/7zFile.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/7zFile.h
@@ -1,8 +1,8 @@
 /* 7zFile.h -- File IO
-2021-02-15 : Igor Pavlov : Public domain */
+2023-03-05 : Igor Pavlov : Public domain */
 
-#ifndef __7Z_FILE_H
-#define __7Z_FILE_H
+#ifndef ZIP7_INC_FILE_H
+#define ZIP7_INC_FILE_H
 
 #ifdef _WIN32
 #define USE_WINDOWS_FILE
@@ -10,7 +10,8 @@
 #endif
 
 #ifdef USE_WINDOWS_FILE
-#include <windows.h>
+#include "7zWindows.h"
+
 #else
 // note: USE_FOPEN mode is limited to 32-bit file size
 // #define USE_FOPEN
