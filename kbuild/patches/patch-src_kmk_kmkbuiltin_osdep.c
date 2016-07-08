$NetBSD$

Add NetBSD support.

--- src/kmk/kmkbuiltin/osdep.c.orig	2015-06-21 21:21:29.000000000 +0000
+++ src/kmk/kmkbuiltin/osdep.c
@@ -41,8 +41,10 @@
 #elif defined(__OpenBSD__)
 # include "openbsd.c"
 
+#elif defined(__NetBSD__)
+# include "strtofflags.c"
+
 #elif defined(__HAIKU__)
 # include "haikufakes.c"
 
 #endif
-
