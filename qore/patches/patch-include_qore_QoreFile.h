$NetBSD: patch-include_qore_QoreFile.h,v 1.3 2014/10/30 16:16:53 nros Exp $
* Fixes build on NetBSD 6
http://sourceforge.net/p/qore/code/6803/
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
 
