$NetBSD: patch-include_qore_QoreFile.h,v 1.4 2014/11/01 15:59:35 nros Exp $
* Fixes build on NetBSD 6
http://sourceforge.net/p/qore/code/6803/
--- include/qore/QoreFile.h.orig	2013-03-05 09:44:51.000000000 +0000
+++ include/qore/QoreFile.h
@@ -34,6 +34,10 @@
 
 #include <string>
 
+#ifdef getchar
+#undef getchar
+#endif
+
 class QoreTermIOS;
 class Queue;
 
