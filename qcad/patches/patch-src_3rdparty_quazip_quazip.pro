$NetBSD$

libtool won't install libraries depending on this when it is a plugin

--- src/3rdparty/quazip/quazip.pro.orig	2016-06-30 12:42:57.000000000 +0000
+++ src/3rdparty/quazip/quazip.pro
@@ -2,12 +2,7 @@ include( ../../../shared.pri )

 TARGET = quazip
 TEMPLATE = lib
-r_static_libs {
-    CONFIG += staticlib
-}
-else {
-    CONFIG += plugin
-}
+CONFIG += staticlib

 CONFIG -= warn_on
 CONFIG += warn_off
