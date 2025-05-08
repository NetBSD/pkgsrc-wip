$NetBSD$

--- third_party/externals/dng_sdk/source/RawEnvironment.h.orig	2025-05-08 10:54:57.565238139 +0000
+++ third_party/externals/dng_sdk/source/RawEnvironment.h
@@ -5,7 +5,7 @@
 // compilation. The constants qMacOS and qWinOS must be defined on all
 // platforms. Other constants, such as qLinux, only need to be defined if we're
 // actually compiling for that platform.
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
 #define qMacOS 0
 #define qWinOS 0
 #define qLinux 1
