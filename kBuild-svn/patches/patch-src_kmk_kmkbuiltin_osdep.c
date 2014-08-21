$NetBSD: patch-src_kmk_kmkbuiltin_osdep.c,v 1.1 2014/08/21 10:18:19 thomasklausner Exp $

Add NetBSD case.

--- src/kmk/kmkbuiltin/osdep.c.orig	2014-08-21 09:57:50.000000000 +0000
+++ src/kmk/kmkbuiltin/osdep.c
@@ -44,5 +44,8 @@
 #elif defined(__HAIKU__)
 # include "haikufakes.c"
 
+#elif defined(__NetBSD__)
+# include "strtofflags.c"
+
 #endif
 
