$NetBSD: patch-share_qtcreator_static.pro,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Fix phony target for Makefile dependencies.
Add a separate $PREFIX to the install paths, as qmake only supports
a single $INSTALL_ROOT prefix. By setting $INSTALL_ROOT to $DESTDIR
this enables DESTDIR support and fixes the library paths.

--- share/qtcreator/static.pro.orig	2012-08-08 13:47:06.000000000 +0000
+++ share/qtcreator/static.pro
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
@@ -64,7 +64,7 @@ macx: DATA_DIRS += scripts
 !macx {
     for(data_dir, DATA_DIRS) {
         eval($${data_dir}.files = $$quote($$PWD/$$data_dir))
-        eval($${data_dir}.path = /share/qtcreator)
+        eval($${data_dir}.path = $$(PREFIX)/share/qtcreator)
         INSTALLS += $$data_dir
     }
 } else {
@@ -117,7 +117,7 @@ QMAKE_EXTRA_COMPILERS += unconditionalCo
 !macx {
     for(data_dir, DATA_DIRS) {
         eval($${data_dir}.files = $$IDE_DATA_PATH/$$data_dir)
-        eval($${data_dir}.path = /share/qtcreator)
+        eval($${data_dir}.path = $$(PREFIX)/share/qtcreator)
         eval($${data_dir}.CONFIG += no_check_exist)
         INSTALLS += $$data_dir
     }
