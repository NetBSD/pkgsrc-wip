$NetBSD: patch-src_qtcreatorplugin.pri,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Add a separate $PREFIX to the install paths, as qmake only supports
a single $INSTALL_ROOT prefix. By setting $INSTALL_ROOT to $DESTDIR
this enables DESTDIR support and fixes the library paths.

--- src/qtcreatorplugin.pri.orig	2012-08-08 13:47:06.000000000 +0000
+++ src/qtcreatorplugin.pri
@@ -81,9 +81,9 @@ CONFIG += plugin plugin_with_soname
 linux*:QMAKE_LFLAGS += $$QMAKE_LFLAGS_NOUNDEF
 
 !macx {
-    target.path = /$$IDE_LIBRARY_BASENAME/qtcreator/plugins/$$PROVIDER
+    target.path = $$(PREFIX)/lib/qtcreator/plugins/$$PROVIDER
     pluginspec.files += $${TARGET}.pluginspec
-    pluginspec.path = /$$IDE_LIBRARY_BASENAME/qtcreator/plugins/$$PROVIDER
+    pluginspec.path = $$(PREFIX)/lib/qtcreator/plugins/$$PROVIDER
     INSTALLS += target pluginspec
 }
 
