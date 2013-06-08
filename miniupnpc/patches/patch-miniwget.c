$NetBSD: patch-miniwget.c,v 1.1 2013/06/08 15:01:16 othyro Exp $

Add NetBSD support.

--- miniwget.c.orig	2012-08-21 17:11:41.000000000 +0000
+++ miniwget.c
@@ -9,6 +9,12 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#if defined (__NetBSD__)
+#include <strings.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netdb.h>
+#endif
 #include <ctype.h>
 #ifdef _WIN32
 #include <winsock2.h>
