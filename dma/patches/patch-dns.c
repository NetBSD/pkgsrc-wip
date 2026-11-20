$NetBSD$

Include sysmacros.h for roundup is required on SunOS.

Use NS_MAXDNAME for macOS compatibility.

--- dns.c.orig	2016-02-07 12:41:49.000000000 +0000
+++ dns.c
@@ -42,7 +42,12 @@
 #include <netdb.h>
 #include <resolv.h>
 #include <string.h>
+#include <strings.h>
 #include <stdlib.h>
+
+#if defined(__sun)
+#include <sys/sysmacros.h>
+#endif
 
 #include "dma.h"
 
@@ -131,7 +136,7 @@
 int
 dns_get_mx_list(const char *host, int port, struct mx_hostentry **he, int no_mx)
 {
-	char outname[MAXDNAME];
+	char outname[NS_MAXDNAME];
 	ns_msg msg;
 	ns_rr rr;
 	const char *searchhost;
