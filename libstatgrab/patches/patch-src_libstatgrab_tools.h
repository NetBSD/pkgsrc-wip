$NetBSD$

Add include for LOCK_SH
--- src/libstatgrab/tools.h.orig	2014-06-19 11:41:10.000000000 +0000
+++ src/libstatgrab/tools.h
@@ -36,6 +36,10 @@
 # include <sys/stat.h>
 #endif
 
+#if defined(__sun)
+#include <sys/file.h>
+#endif
+
 #include <stdio.h>
 #ifdef STDC_HEADERS
 # include <assert.h>
