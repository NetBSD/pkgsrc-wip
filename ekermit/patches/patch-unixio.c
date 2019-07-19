$NetBSD$

Avoid implicit declarations.

unistd.h for write
stdlib.h for rand

--- unixio.c.orig	2011-03-30 16:42:24.000000000 +0000
+++ unixio.c
@@ -42,6 +42,8 @@
 #include <sys/stat.h>
 #include <time.h>
 #include <errno.h>
+#include <unistd.h>
+#include <stdlib.h>
 #ifndef O_WRONLY
 #include <sys/file.h>
 #ifdef X_OK
