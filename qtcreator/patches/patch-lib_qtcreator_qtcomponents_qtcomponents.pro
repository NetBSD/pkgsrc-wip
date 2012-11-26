$NetBSD: patch-lib_qtcreator_qtcomponents_qtcomponents.pro,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Fix phony target for Makefile dependencies.
Add a separate $PREFIX to the install paths, as qmake only supports
a single $INSTALL_ROOT prefix. By setting $INSTALL_ROOT to $DESTDIR
this enables DESTDIR support and fixes the library paths.

--- lib/qtcreator/qtcomponents/qtcomponents.pro.orig	2012-08-08 13:47:06.000000000 +0000
+++ lib/qtcreator/qtcomponents/qtcomponents.pro
@@ -7,7 +7,7 @@ QT =
 LIBS =
 macx:CONFIG -= app_bundle
 
-isEmpty(vcproj) {
+!isEmpty(vcproj) {
     QMAKE_LINK = @: IGNORE THIS LINE
     OBJECTS_DIR =
     win32:CONFIG -= embed_manifest_exe
@@ -17,7 +17,7 @@ isEmpty(vcproj) {
     phony_src.input = PHONY_DEPS
     phony_src.output = phony.c
     phony_src.variable_out = GENERATED_SOURCES
-    phony_src.commands = echo int main() { return 0; } > phony.c
+    phony_src.commands = echo \"int main() { return 0; }\" > phony.c
     phony_src.name = CREATE phony.c
     phony_src.CONFIG += combine
     QMAKE_EXTRA_COMPILERS += phony_src
@@ -52,6 +52,6 @@ DATA_FILE_PATTERNS = \
 
 !macx {
     qmlfiles.files = $$PWD/*.qml $$PWD/qmldir $$PWD/images $$PWD/custom
-    qmlfiles.path = /$${IDE_LIBRARY_BASENAME}/qtcreator/qtcomponents
+    qmlfiles.path = $$(PREFIX)/lib/qtcreator/qtcomponents
     INSTALLS += qmlfiles
 }
