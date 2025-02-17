$NetBSD$

--- libpkg/fetch_ssh.c.orig	2025-02-17 16:42:03.451233170 +0000
+++ libpkg/fetch_ssh.c
@@ -34,6 +34,10 @@
 #include <ctype.h>
 #include <fcntl.h>
 #include <errno.h>
+#ifdef __NetBSD__
+# define _OPENBSD_SOURCE
+# include <stdlib.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <paths.h>
