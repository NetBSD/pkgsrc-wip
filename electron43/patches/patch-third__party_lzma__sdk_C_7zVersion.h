$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/7zVersion.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/7zVersion.h
@@ -1,27 +0,0 @@
-#define MY_VER_MAJOR 22
-#define MY_VER_MINOR 01
-#define MY_VER_BUILD 0
-#define MY_VERSION_NUMBERS "22.01"
-#define MY_VERSION MY_VERSION_NUMBERS
-
-#ifdef MY_CPU_NAME
-  #define MY_VERSION_CPU MY_VERSION " (" MY_CPU_NAME ")"
-#else
-  #define MY_VERSION_CPU MY_VERSION
-#endif
-
-#define MY_DATE "2022-07-15"
-#undef MY_COPYRIGHT
-#undef MY_VERSION_COPYRIGHT_DATE
-#define MY_AUTHOR_NAME "Igor Pavlov"
-#define MY_COPYRIGHT_PD "Igor Pavlov : Public domain"
-#define MY_COPYRIGHT_CR "Copyright (c) 1999-2022 Igor Pavlov"
-
-#ifdef USE_COPYRIGHT_CR
-  #define MY_COPYRIGHT MY_COPYRIGHT_CR
-#else
-  #define MY_COPYRIGHT MY_COPYRIGHT_PD
-#endif
-
-#define MY_COPYRIGHT_DATE MY_COPYRIGHT " : " MY_DATE
-#define MY_VERSION_COPYRIGHT_DATE MY_VERSION_CPU " : " MY_COPYRIGHT " : " MY_DATE
