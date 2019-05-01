$NetBSD$

--- sftp-common.c.orig	2019-04-17 22:52:57.000000000 +0000
+++ sftp-common.c
@@ -36,7 +36,9 @@
 #include <string.h>
 #include <time.h>
 #include <stdarg.h>
+#ifdef HAVE_UNISTD_H
 #include <unistd.h>
+#endif
 #ifdef HAVE_UTIL_H
 #include <util.h>
 #endif
