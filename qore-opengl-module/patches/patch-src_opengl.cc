$NetBSD: patch-src_opengl.cc,v 1.2 2014/10/27 14:06:36 nros Exp $

* alloca is in stdlib.h on bsd systems 
http://sourceforge.net/p/qore/code/6300/
--- src/opengl.cc.orig	2009-09-21 11:55:18.000000000 +0000
+++ src/opengl.cc
@@ -22,7 +22,9 @@
 
 #include "qore-opengl.h"
 
+#ifdef HAVE_ALLOCA_H
 #include <alloca.h>
+#endif
 
 static QoreStringNode *opengl_module_init();
 static void opengl_module_ns_init(QoreNamespace *rns, QoreNamespace *qns);
