$NetBSD: patch-src_lib_lib.pro,v 1.1 2014/01/08 14:08:46 nros Exp $

* QT4 uses webkit 2.2 so define USE_WEBKIT_2_2 to not break build

--- src/lib/lib.pro.orig	2014-01-01 19:55:33.000000000 +0000
+++ src/lib/lib.pro
@@ -2,6 +2,7 @@ isEqual(QT_MAJOR_VERSION, 5) {
     QT += webkitwidgets network widgets printsupport sql script gui-private
 } else {
     QT += core gui webkit sql network script
+    DEFINES += USE_QTWEBKIT_2_2
 }
 
 TARGET = QupZilla
