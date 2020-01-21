$NetBSD$

* use posix errno.h instead of bsd sys/errno.h (fixes build on illumos)

--- keama/keama.c.orig	2020-01-18 19:49:58.000000000 +0000
+++ keama/keama.c
@@ -21,7 +21,7 @@
  *
  */
 
-#include <sys/errno.h>
+#include <errno.h>
 #include <arpa/inet.h>
 #include <assert.h>
 #include <fcntl.h>
