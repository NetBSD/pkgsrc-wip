$NetBSD$

libtool won't install libraries depending on this when it is a plugin

--- src/3rdparty/spatialindexnavel/spatialindexnavel.pro.orig	2016-06-30 12:42:57.000000000 +0000
+++ src/3rdparty/spatialindexnavel/spatialindexnavel.pro
@@ -2,12 +2,7 @@ include( ../../../shared.pri )

 TARGET = spatialindexnavel
 TEMPLATE = lib
-r_static_libs {
-    CONFIG += staticlib
-}
-else {
-    CONFIG += plugin
-}
+CONFIG += staticlib

 # this is required to compile the spatial index library from navel ltd:
 #DEFINES += PACKAGE_BUGREPORT=\\\"mhadji@gmail.com\\\"
