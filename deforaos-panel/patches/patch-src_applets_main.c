$NetBSD: patch-src_applets_main.c,v 1.1 2014/10/25 00:00:42 khorben Exp $

Need sys/fcntl.h for O_RDONLY on SunOS.

--- src/applets/main.c.orig	2014-10-23 17:34:42.000000000 +0000
+++ src/applets/main.c
@@ -16,6 +16,9 @@
 
 
 #include <sys/stat.h>
+#if defined(__sun)
+# include <fcntl.h>
+#endif
 #include <dirent.h>
 #include <unistd.h>
 #include <stdlib.h>
