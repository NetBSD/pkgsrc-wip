$NetBSD$

* use posix errno.h instead of bsd sys/errno.h (fixes build on illumos)

--- keama/print.c.orig	2020-01-18 19:49:58.000000000 +0000
+++ keama/print.c
@@ -23,7 +23,7 @@
 
 #include "keama.h"
 
-#include <sys/errno.h>
+#include <errno.h>
 #include <sys/types.h>
 #include <arpa/inet.h>
 #include <ctype.h>
