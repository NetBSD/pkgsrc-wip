$NetBSD: patch-include_qore_QoreFile.h,v 1.2 2014/02/22 18:51:30 nros Exp $
* Fixes build on NetBSD 6
--- include/qore/QoreFile.h.orig	2013-02-22 16:11:01.000000000 +0000
+++ include/qore/QoreFile.h
@@ -34,6 +34,10 @@
 
 #include <string>
 
+#ifdef getchar
+#undef getchar
+#endif
+
 class QoreTermIOS;
 class Queue;
 
