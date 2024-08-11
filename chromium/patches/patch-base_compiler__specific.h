$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/compiler_specific.h.orig	2024-07-24 02:44:22.539415800 +0000
+++ base/compiler_specific.h
@@ -316,7 +316,8 @@
 //
 // In some cases it's desirable to remove this, e.g. on hot functions, or if
 // we have purposely changed the reference canary.
-#if defined(COMPILER_GCC) || defined(__clang__)
+#if (defined(COMPILER_GCC) || defined(__clang__)) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && \
+      !defined(__NetBSD__)
 #if HAS_ATTRIBUTE(__no_stack_protector__)
 #define NO_STACK_PROTECTOR __attribute__((__no_stack_protector__))
 #else
