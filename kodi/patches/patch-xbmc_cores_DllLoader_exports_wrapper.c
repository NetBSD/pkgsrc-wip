$NetBSD: patch-xbmc_cores_DllLoader_exports_wrapper.c,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/cores/DllLoader/exports/wrapper.c.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/cores/DllLoader/exports/wrapper.c
@@ -39,7 +39,7 @@
 #endif
 #include <dlfcn.h>
 
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_ANDROID)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD) || defined(TARGET_ANDROID)
 typedef off_t     __off_t;
 typedef int64_t   off64_t;
 typedef off64_t   __off64_t;
