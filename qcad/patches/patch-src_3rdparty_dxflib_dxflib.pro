$NetBSD$

--- src/3rdparty/dxflib/dxflib.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/3rdparty/dxflib/dxflib.pro
@@ -25,5 +25,5 @@ SOURCES = \

 TARGET = dxflib
 TEMPLATE = lib
-CONFIG += staticlib
+CONFIG += plugin
 DEFINES += DXFLIB_LIBRARY
