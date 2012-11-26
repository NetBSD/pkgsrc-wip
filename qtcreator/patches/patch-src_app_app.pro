$NetBSD: patch-src_app_app.pro,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Add a separate $PREFIX to the install paths, as qmake only supports
a single $INSTALL_ROOT prefix. By setting $INSTALL_ROOT to $DESTDIR
this enables DESTDIR support and fixes the library paths.

--- src/app/app.pro.orig	2012-08-08 13:47:06.000000000 +0000
+++ src/app/app.pro
@@ -3,7 +3,7 @@ include(../shared/qtsingleapplication/qt
 
 TEMPLATE = app
 TARGET = $$IDE_APP_TARGET
-DESTDIR = $$IDE_APP_PATH
+#DESTDIR = $$IDE_APP_PATH
 
 SOURCES += main.cpp
 
@@ -29,7 +29,7 @@ win32 {
     info.output = $$IDE_BIN_PATH/../Info.plist
     QMAKE_SUBSTITUTES = info
 } else {
-    target.path  = /bin
+    target.path  = $$(PREFIX)/bin
     INSTALLS    += target
 }
 
