$NetBSD: patch-src_plugins_file_browse_fstatat.c,v 1.1 2012/11/04 23:51:33 othyro Exp $

Defines fstatat for those that don't have it.

--- src/plugins/file/browse/fstatat.c.orig	2011-10-20 19:26:08.000000000 +0000
+++ src/plugins/file/browse/fstatat.c
@@ -23,6 +23,10 @@
 #include <errno.h>
 #include <dirent.h>
 
+#ifndef fstatat
+#define fstatat(int, const char *, struct stat *, int);
+#endif
+
 #include "browse.h"
 
 gboolean
