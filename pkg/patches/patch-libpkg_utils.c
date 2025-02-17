$NetBSD$

--- libpkg/utils.c.orig	2025-02-17 16:41:03.857250598 +0000
+++ libpkg/utils.c
@@ -38,6 +38,9 @@
 #include <assert.h>
 #include <errno.h>
 #include <fcntl.h>
+#ifdef __NetBSD__
+# define _OPENBSD_SOURCE
+#endif
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
