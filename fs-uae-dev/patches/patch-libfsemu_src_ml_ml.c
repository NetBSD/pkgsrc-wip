$NetBSD: patch-libfsemu_src_ml_ml.c,v 1.1 2013/11/15 12:26:23 rhialto Exp $

Add support for NetBSD.

--- libfsemu/src/ml/ml.c.orig	2013-10-23 17:57:59.000000000 +0000
+++ libfsemu/src/ml/ml.c
@@ -239,6 +239,8 @@ void fs_ml_init() {
     fs_log("LINUX\n");
 #elif defined(FREEBSD)
     fs_log("FREEBSD\n");
+#elif defined(NETBSD)
+    fs_log("NETBSD\n");
 #elif defined(OPENBSD)
     fs_log("OPENBSD\n");
 #else
