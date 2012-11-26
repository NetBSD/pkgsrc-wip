$NetBSD: patch-src_tools_qmlprofilertool_qmlprofilertool.pro,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Add a separate $PREFIX to the install paths, as qmake only supports
a single $INSTALL_ROOT prefix. By setting $INSTALL_ROOT to $DESTDIR
this enables DESTDIR support and fixes the library paths.

--- src/tools/qmlprofilertool/qmlprofilertool.pro.orig	2012-08-08 13:47:06.000000000 +0000
+++ src/tools/qmlprofilertool/qmlprofilertool.pro
@@ -4,7 +4,7 @@ include(../../rpath.pri)
 
 TEMPLATE = app
 TARGET   = qmlprofiler
-DESTDIR = $$IDE_BIN_PATH
+#DESTDIR = $$IDE_BIN_PATH
 
 CONFIG   += console
 CONFIG   -= app_bundle
@@ -23,6 +23,6 @@ HEADERS += \
     commandlistener.h \
     constants.h
 
-target.path=/bin
+target.path=$$(PREFIX)/bin
 INSTALLS+=target
 
