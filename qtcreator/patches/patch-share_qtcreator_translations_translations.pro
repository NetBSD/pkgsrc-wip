$NetBSD: patch-share_qtcreator_translations_translations.pro,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Fix phony target for Makefile dependencies.
Add a separate $PREFIX to the install paths, as qmake only supports
a single $INSTALL_ROOT prefix. By setting $INSTALL_ROOT to $DESTDIR
this enables DESTDIR support and fixes the library paths.

--- share/qtcreator/translations/translations.pro.orig	2012-08-08 13:47:06.000000000 +0000
+++ share/qtcreator/translations/translations.pro
@@ -103,7 +103,7 @@ updateqm.name = LRELEASE ${QMAKE_FILE_IN
 updateqm.CONFIG += no_link
 QMAKE_EXTRA_COMPILERS += updateqm
 
-isEmpty(vcproj) {
+!isEmpty(vcproj) {
     QMAKE_LINK = @: IGNORE THIS LINE
     OBJECTS_DIR =
     win32:CONFIG -= embed_manifest_exe
@@ -113,13 +113,13 @@ isEmpty(vcproj) {
     phony_src.input = PHONY_DEPS
     phony_src.output = phony.c
     phony_src.variable_out = GENERATED_SOURCES
-    phony_src.commands = echo int main() { return 0; } > phony.c
+    phony_src.commands = echo \"int main() { return 0; }\" > phony.c
     phony_src.name = CREATE phony.c
     phony_src.CONFIG += combine
     QMAKE_EXTRA_COMPILERS += phony_src
 }
 
 qmfiles.files = $$prependAll(LANGUAGES, $$OUT_PWD/qtcreator_,.qm)
-qmfiles.path = /share/qtcreator/translations
+qmfiles.path = $$(PREFIX)/share/qtcreator/translations
 qmfiles.CONFIG += no_check_exist
 INSTALLS += qmfiles
