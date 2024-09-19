$NetBSD$

Add missing include.

--- src/ssl.c.orig	2017-09-11 12:26:20.000000000 +0000
+++ src/ssl.c
@@ -26,6 +26,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/socket.h>		/* basic socket definitions */
 #include <netdb.h>
 #include <netinet/in.h>
