$NetBSD: patch-lib_remopen.c,v 1.1 2011/09/21 20:10:17 hfath Exp $

Add missing header for inet_addr()

--- lib/remopen.c.orig	1997-12-08 23:48:50.000000000 +0000
+++ lib/remopen.c
@@ -11,6 +11,7 @@
 #include <sys/un.h>
 #endif	/* defined(DO_HAVE_UNIX_DOMAIN) */
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <netdb.h>
 #include "nntp.h"
 #include "paths.h"
