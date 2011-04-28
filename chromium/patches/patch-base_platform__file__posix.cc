$NetBSD: patch-base_platform__file__posix.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/platform_file_posix.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/platform_file_posix.cc
@@ -15,7 +15,7 @@
 
 namespace base {
 
-#if defined(OS_OPENBSD) || defined(OS_FREEBSD) || \
+#if defined(OS_BSD) || \
     (defined(OS_MACOSX) && \
      MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_5)
 typedef struct stat stat_wrapper_t;
