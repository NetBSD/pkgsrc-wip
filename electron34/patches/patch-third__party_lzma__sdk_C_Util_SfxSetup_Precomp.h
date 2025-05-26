$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Util/SfxSetup/Precomp.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Util/SfxSetup/Precomp.h
@@ -1,10 +0,0 @@
-/* Precomp.h -- StdAfx
-2013-06-16 : Igor Pavlov : Public domain */
-
-#ifndef __7Z_PRECOMP_H
-#define __7Z_PRECOMP_H
-
-#include "Compiler.h"
-#include "7zTypes.h"
-
-#endif
