$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Delta.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Delta.h
@@ -1,8 +1,8 @@
 /* Delta.h -- Delta converter
-2013-01-18 : Igor Pavlov : Public domain */
+2023-03-03 : Igor Pavlov : Public domain */
 
-#ifndef __DELTA_H
-#define __DELTA_H
+#ifndef ZIP7_INC_DELTA_H
+#define ZIP7_INC_DELTA_H
 
 #include "7zTypes.h"
 
