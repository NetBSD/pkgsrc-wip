$NetBSD: patch-src_opengl.cc,v 1.1 2014/02/14 21:03:04 nros Exp $

* alloca is in stdlib.h on most systems 

--- src/opengl.cc.orig	2009-09-21 11:55:18.000000000 +0000
+++ src/opengl.cc
@@ -22,7 +22,11 @@
 
 #include "qore-opengl.h"
 
+#if defined(__linux__) || defined(__sgi) || defined(__QNX__)
 #include <alloca.h>
+#else
+#include <stdlib.h>
+#endif
 
 static QoreStringNode *opengl_module_init();
 static void opengl_module_ns_init(QoreNamespace *rns, QoreNamespace *qns);
