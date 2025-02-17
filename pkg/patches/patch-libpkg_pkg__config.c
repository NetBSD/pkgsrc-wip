$NetBSD$

--- libpkg/pkg_config.c.orig	2025-02-17 16:34:16.769671839 +0000
+++ libpkg/pkg_config.c
@@ -35,6 +35,10 @@
 #include <ctype.h>
 #include <dirent.h>
 #include <dlfcn.h>
+#ifdef __NetBSD__
+# define _OPENBSD_SOURCE
+#include <stdlib.h>
+#endif
 #include <errno.h>
 #include <fcntl.h>
 #ifdef HAVE_OSRELDATE_H
