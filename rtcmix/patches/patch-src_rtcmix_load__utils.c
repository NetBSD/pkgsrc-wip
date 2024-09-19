$NetBSD$

--- src/rtcmix/load_utils.c.orig	2015-10-03 21:09:58.000000000 +0000
+++ src/rtcmix/load_utils.c
@@ -9,7 +9,7 @@
 
 #include "load_utils.h"
 
-#if (defined(MACOSX) && !defined(JAGUAR)) || defined(LINUX)
+#if (defined(MACOSX) && !defined(JAGUAR)) || defined(LINUX) || defined(NETBSD)
 
 #include <dlfcn.h>
 
