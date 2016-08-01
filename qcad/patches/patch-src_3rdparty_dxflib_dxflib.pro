$NetBSD$

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/3rdparty/dxflib/dxflib.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/3rdparty/dxflib/dxflib.pro
@@ -25,5 +25,6 @@ SOURCES = \

 TARGET = dxflib
 TEMPLATE = lib
-CONFIG += staticlib
+CONFIG += plugin
+INSTALLS += target
 DEFINES += DXFLIB_LIBRARY
