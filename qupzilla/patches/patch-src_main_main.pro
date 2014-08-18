$NetBSD: patch-src_main_main.pro,v 1.2 2014/08/18 17:44:43 nros Exp $
* pkgsrc QT4 uses libtool so link against .la file instead of .so
* patch accepted upstream
  https://github.com/QupZilla/qupzilla/pull/1441
--- src/main/main.pro.orig	2014-08-18 17:02:48.000000000 +0000
+++ src/main/main.pro
@@ -9,8 +9,12 @@ mac: TARGET = QupZilla
 
 TEMPLATE = app
 
+compile_libtool {
+LIBS += ../../bin/libQupZilla.la
+} else {
 !unix|mac: LIBS += -L../../bin -lQupZilla
 !mac:unix: LIBS += ../../bin/libQupZilla.so
+}
 
 include(../defines.pri)
 include(../install.pri)
