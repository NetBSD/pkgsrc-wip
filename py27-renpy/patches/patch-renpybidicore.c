$NetBSD$

* NetBSD has no alloca.h.

--- renpybidicore.c.orig	2026-06-19 02:24:46.614314265 +0000
+++ renpybidicore.c
@@ -2,8 +2,10 @@
 #include <fribidi/fribidi.h>
 #include <stdlib.h>
 
+#if !defined(__NetBSD__)
 #ifndef alloca
 #include <alloca.h>
+#endif
 #endif
 
 /* This is easier than trying to figure out the header that alloca is */
