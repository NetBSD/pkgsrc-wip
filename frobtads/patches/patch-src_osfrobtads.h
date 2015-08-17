$NetBSD: patch-src_osfrobtads.h,v 1.1 2015/08/17 21:11:24 yhardy Exp $

stdarg.h is required for va_list.

--- ./src/osfrobtads.h.orig	2013-05-17 19:46:51.000000000 +0000
+++ ./src/osfrobtads.h
@@ -24,6 +24,7 @@ extern "C++" {
 #include <sys/stat.h>
 #include <unistd.h>
 #include <dirent.h>
+#include <stdarg.h>
 #ifdef __cplusplus
 }
 #endif
