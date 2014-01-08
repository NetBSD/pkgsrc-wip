$NetBSD: patch-src_main_main.pro,v 1.1 2014/01/08 14:08:46 nros Exp $

* pkgsrc QT4 uses libtool so link against .la file instead of .so

--- src/main/main.pro.orig	2014-01-01 19:55:33.000000000 +0000
+++ src/main/main.pro
@@ -10,7 +10,7 @@ mac: TARGET = QupZilla
 TEMPLATE = app
 
 !unix|mac: LIBS += -L../../bin -lQupZilla
-!mac:unix: LIBS += ../../bin/libQupZilla.so
+!mac:unix: LIBS += ../../bin/libQupZilla.la
 
 include(../defines.pri)
 include(../install.pri)
