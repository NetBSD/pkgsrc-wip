$NetBSD: patch-libfsemu_src_ml_ml.c,v 1.2 2014/04/06 13:33:55 rhialto Exp $

Add support for NetBSD.

--- libfsemu/src/ml/ml.c.orig	2014-03-25 19:40:58.000000000 +0000
+++ libfsemu/src/ml/ml.c
@@ -243,6 +243,8 @@ void fs_ml_init() {
     fs_log("LINUX\n");
 #elif defined(FREEBSD)
     fs_log("FREEBSD\n");
+#elif defined(NETBSD)
+    fs_log("NETBSD\n");
 #elif defined(OPENBSD)
     fs_log("OPENBSD\n");
 #else
