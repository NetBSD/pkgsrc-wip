$NetBSD: patch-heimdall_source_Heimdall.h,v 1.1 2013/01/08 22:07:07 othyro Exp $

Add NetBSD support.

--- heimdall/source/Heimdall.h.orig	2012-03-31 01:22:17.000000000 +0000
+++ heimdall/source/Heimdall.h
@@ -27,7 +27,7 @@
 
 #include "../config.h"
 
-#if defined(OS_DARWIN) || defined(OS_LINUX)
+#if defined(OS_DARWIN) || defined(OS_LINUX) || defined(OS_NETBSD)
 #include <unistd.h>
 #define Sleep(t) usleep(1000*t)
 #else
