$NetBSD: patch-libfsemu_src_ml_ml.c,v 1.1 2013/10/25 22:02:17 rhialto Exp $

Add support for NetBSD.

--- libfsemu/src/ml/ml.c.orig	2013-06-25 19:21:16.000000000 +0000
+++ libfsemu/src/ml/ml.c
@@ -287,6 +287,8 @@ void fs_ml_init() {
     fs_log("LINUX\n");
 #elif defined(FREEBSD)
     fs_log("FREEBSD\n");
+#elif defined(NETBSD)
+    fs_log("NETBSD\n");
 #elif defined(OPENBSD)
     fs_log("OPENBSD\n");
 #else
