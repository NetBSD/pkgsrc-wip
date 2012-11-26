$NetBSD: patch-src_libs_utils_process__stub.pro,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Add a separate $PREFIX to the install paths, as qmake only supports
a single $INSTALL_ROOT prefix. By setting $INSTALL_ROOT to $DESTDIR
this enables DESTDIR support and fixes the library paths.

--- src/libs/utils/process_stub.pro.orig	2012-08-08 13:47:06.000000000 +0000
+++ src/libs/utils/process_stub.pro
@@ -5,7 +5,7 @@ include(../../../qtcreator.pri)
 
 TEMPLATE        = app
 TARGET          = qtcreator_process_stub
-DESTDIR         = $$IDE_LIBEXEC_PATH
+#DESTDIR         = $$IDE_LIBEXEC_PATH
 
 build_all:!build_pass {
     CONFIG -= build_all
@@ -20,5 +20,5 @@ unix {
     LIBS += -lshell32
 }
 
-target.path  = /bin # FIXME: libexec, more or less
+target.path  = $$(PREFIX)/bin # FIXME: libexec, more or less
 INSTALLS    += target
