$NetBSD: patch-src_tools_qtpromaker_qtpromaker.pro,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Add a separate $PREFIX to the install paths, as qmake only supports
a single $INSTALL_ROOT prefix. By setting $INSTALL_ROOT to $DESTDIR
this enables DESTDIR support and fixes the library paths.

--- src/tools/qtpromaker/qtpromaker.pro.orig	2012-08-08 13:47:06.000000000 +0000
+++ src/tools/qtpromaker/qtpromaker.pro
@@ -4,12 +4,12 @@ include(../../../qtcreator.pri)
 
 TEMPLATE  = app
 TARGET    = qtpromaker
-DESTDIR   = $$IDE_LIBEXEC_PATH
+#DESTDIR   = $$IDE_LIBEXEC_PATH
 
 CONFIG    += console warn_on
 CONFIG    -= app_bundle
 
 SOURCES   += main.cpp
 
-target.path  = /bin # FIXME: libexec, more or less
+target.path  = $$(PREFIX)/bin # FIXME: libexec, more or less
 INSTALLS    += target
