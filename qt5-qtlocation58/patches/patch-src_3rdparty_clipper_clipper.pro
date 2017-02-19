$NetBSD$

shared libraries

--- src/3rdparty/clipper/clipper.pro.orig	2016-12-07 05:51:36.000000000 +0000
+++ src/3rdparty/clipper/clipper.pro
@@ -1,6 +1,8 @@
 TARGET = clipper
 
-CONFIG += staticlib
+CONFIG += shared
 CONFIG += exceptions
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 
