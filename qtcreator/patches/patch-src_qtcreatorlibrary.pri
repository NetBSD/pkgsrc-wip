$NetBSD: patch-src_qtcreatorlibrary.pri,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Add a separate $PREFIX to the install paths, as qmake only supports
a single $INSTALL_ROOT prefix. By setting $INSTALL_ROOT to $DESTDIR
this enables DESTDIR support and fixes the library paths.

--- src/qtcreatorlibrary.pri.orig	2012-08-08 13:47:06.000000000 +0000
+++ src/qtcreatorlibrary.pri
@@ -21,7 +21,7 @@ contains(QT_CONFIG, reduce_exports):CONF
     win32 {
         target.path = /bin
     } else {
-        target.path = /$$IDE_LIBRARY_BASENAME/qtcreator
+        target.path = $$(PREFIX)/lib/qtcreator
     }
     INSTALLS += target
 }
