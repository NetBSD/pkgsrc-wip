$NetBSD$

QCad tries to copy Qt plugins to its own folder but I think this is
not necessary in pkgsrc framework since the binary seems to find them

XXX check this again once the package is working

--- src/run/run.pri.orig	2016-06-30 12:42:57.000000000 +0000
+++ src/run/run.pri
@@ -41,7 +41,7 @@ else {
 }

 # copy Qt plugins to QCAD plugin folder:
-!build_pass {
+DISABLE_THIS {
     macx {
         FILES = \
             imageformats/libqgif.dylib \
