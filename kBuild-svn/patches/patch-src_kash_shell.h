$NetBSD: patch-src_kash_shell.h,v 1.1 2014/08/22 09:24:56 thomasklausner Exp $

--- src/kash/shell.h.orig	2014-08-22 09:15:47.000000000 +0000
+++ src/kash/shell.h
@@ -61,11 +61,14 @@
 # define BSD 1
 #endif
 
+#if 0
+/* bad interaction with libpthread */
 #ifndef DO_SHAREDVFORK
 # if __NetBSD_Version__ >= 104000000
 #  define DO_SHAREDVFORK
 # endif
 #endif
+#endif
 
 typedef void *pointer;
 #ifndef NULL
