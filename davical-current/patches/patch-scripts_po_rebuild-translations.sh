$NetBSD$

--- scripts/po/rebuild-translations.sh.orig	2015-11-12 14:35:57.000000000 +0000
+++ scripts/po/rebuild-translations.sh
@@ -11,7 +11,8 @@ PODIR="po"
 LOCALEDIR="locale"
 APPLICATION="davical"
 
-awldirs="../awl
+awldirs="@LIBAWLPATH@
+../awl
 `find .. -type d -name 'awl-*.*'`
 /usr/share/awl
 /usr/share/php/awl
