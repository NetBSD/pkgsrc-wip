$NetBSD: patch-libpkg_pkg__jobs__universe.c,v 1.1 2015/02/20 12:13:20 khorben Exp $

--- libpkg/pkg_jobs_universe.c.orig	2015-02-13 19:35:03.000000000 +0000
+++ libpkg/pkg_jobs_universe.c
@@ -26,7 +26,9 @@
 
 #include <assert.h>
 #include <errno.h>
+#ifdef HAVE_LIBUTIL_H
 #include <libutil.h>
+#endif
 #include <stdbool.h>
 #include <stdlib.h>
 #include <string.h>
