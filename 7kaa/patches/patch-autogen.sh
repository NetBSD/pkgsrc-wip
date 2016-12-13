$NetBSD$

Fix unportable test(1) operator.

--- autogen.sh.orig	2016-12-13 23:13:24.865070763 +0000
+++ autogen.sh
@@ -12,7 +12,7 @@ rm -f ABOUT-NLS config.rpath m4/codeset.
       m4/wint_t.m4 m4/xsize.m4 po/Makefile.in.in po/Makevars.template \
       po/Rules-quot po/boldquot.sed po/en@boldquot.header po/en@quot.header \
       po/insert-header.sin po/quot.sed po/remove-potcdate.sin
-test "$1" == clean && exit 0
+test "$1" = clean && exit 0
 
 autopoint -f
 
