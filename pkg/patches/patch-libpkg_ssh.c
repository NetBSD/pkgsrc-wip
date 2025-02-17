$NetBSD$

--- libpkg/ssh.c.orig	2025-02-17 16:40:08.471070566 +0000
+++ libpkg/ssh.c
@@ -36,6 +36,9 @@
 #include <sys/stat.h>
 
 #include <ctype.h>
+#ifdef __NetBSD__
+# define _OPENBSD_SOURCE
+#endif
 #include <stdlib.h>
 #include <inttypes.h>
 #include <stdio.h>
