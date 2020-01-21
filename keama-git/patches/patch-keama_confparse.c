$NetBSD$

* use posix errno.h instead of bsd sys/errno.h (fixes build on illumos)

--- keama/confparse.c.orig	2020-01-18 19:49:58.000000000 +0000
+++ keama/confparse.c
@@ -25,7 +25,7 @@
 
 #include "keama.h"
 
-#include <sys/errno.h>
+#include <errno.h>
 #include <arpa/inet.h>
 #include <assert.h>
 #include <ctype.h>
