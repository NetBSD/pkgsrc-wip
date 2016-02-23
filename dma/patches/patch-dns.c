$NetBSD$

Include sysmacros.h for roundup is required on SunOS.

--- dns.c.orig	2016-02-07 12:41:49.000000000 +0000
+++ dns.c
@@ -41,8 +41,13 @@
 #include <netdb.h>
 #include <resolv.h>
 #include <string.h>
+#include <strings.h>
 #include <stdlib.h>
 
+#if defined(__sun)
+#include <sys/sysmacros.h>
+#endif
+
 #include "dma.h"
 
 static int
