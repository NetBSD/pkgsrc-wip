$NetBSD$

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/run/run.pri.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/run/run.pri
@@ -27,21 +27,12 @@ SOURCES += $$PWD/main.cpp
 TEMPLATE = app
 OTHER_FILES += $$PWD/run.dox
 
-win32 {
-    TARGET = $${RLIBNAME}
-}
-
-macx {
-    TARGET = QCAD
-} 
-else {
-    unix {
-        TARGET = $${RLIBNAME}-bin
-    }
-}
+TARGET = $${RLIBNAME}
+INSTALLS += target
+target.path = $${PREFIX}/bin
 
 # copy Qt plugins to QCAD plugin folder:
-!build_pass {
+DISABLE_THIS {
     macx {
         FILES = \
             imageformats/libqgif.dylib \
