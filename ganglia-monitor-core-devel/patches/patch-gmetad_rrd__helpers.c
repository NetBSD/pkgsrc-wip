$NetBSD$

# Portability

--- gmetad/rrd_helpers.c.orig	2015-07-01 19:49:35.000000000 +0000
+++ gmetad/rrd_helpers.c
@@ -2,6 +2,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#ifdef __NetBSD__
+#include <sys/filio.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
