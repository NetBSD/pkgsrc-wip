$NetBSD$

shared libraries

--- src/3rdparty/poly2tri/poly2tri.pro.orig	2016-12-07 05:51:36.000000000 +0000
+++ src/3rdparty/poly2tri/poly2tri.pro
@@ -1,6 +1,8 @@
 TARGET = poly2tri
 
-CONFIG += staticlib
+CONFIG += shared
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 load(qt_helper_lib)
 
