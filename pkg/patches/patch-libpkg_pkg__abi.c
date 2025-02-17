$NetBSD$

--- libpkg/pkg_abi.c.orig	2025-02-17 16:43:06.627503382 +0000
+++ libpkg/pkg_abi.c
@@ -16,6 +16,10 @@
 #include <paths.h>
 #include <string.h>
 #include <unistd.h>
+#ifdef __NetBSD__
+# define _OPENBSD_SOURCE
+# include <stdlib.h>
+#endif
 
 #include "pkg.h"
 #include "private/pkg_abi.h"
