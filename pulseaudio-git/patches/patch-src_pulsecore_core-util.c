$NetBSD: patch-src_pulsecore_core-util.c,v 1.1 2015/09/25 14:37:27 ryoon Exp $

--- src/pulsecore/core-util.c.orig	2015-11-28 09:05:41.000000000 +0000
+++ src/pulsecore/core-util.c
@@ -52,8 +52,11 @@
 #include <pcreposix.h>
 #endif
 
-#ifdef HAVE_STRTOD_L
+#ifdef HAVE_LOCALE_H
 #include <locale.h>
+#endif
+
+#ifdef HAVE_XLOCALE_H
 #include <xlocale.h>
 #endif
 
@@ -106,7 +109,6 @@
 #endif
 
 #ifdef __APPLE__
-#include <xlocale.h>
 #include <mach/mach_init.h>
 #include <mach/thread_act.h>
 #include <mach/thread_policy.h>
