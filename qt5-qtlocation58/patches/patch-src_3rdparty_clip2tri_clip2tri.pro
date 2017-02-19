$NetBSD$

shared libraries

--- src/3rdparty/clip2tri/clip2tri.pro.orig	2016-12-07 05:51:36.000000000 +0000
+++ src/3rdparty/clip2tri/clip2tri.pro
@@ -1,6 +1,8 @@
 TARGET = clip2tri
 
-CONFIG += staticlib exceptions
+CONFIG += shared exceptions
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 load(qt_helper_lib)
 
