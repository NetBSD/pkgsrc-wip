$NetBSD$

--- routines.c.orig	2019-03-25 18:42:04.941126183 +0000
+++ routines.c
@@ -526,7 +526,7 @@ static boolean isPathSeparator (const in
 
 #if ! defined (HAVE_STAT_ST_INO)
 
-static void canonicalizePath (char *const path __unused__)
+static void canonicalizePath (char *const path CTAGS_UNUSED)
 {
 #if defined (MSDOS_STYLE_PATH)
 	char *p;
