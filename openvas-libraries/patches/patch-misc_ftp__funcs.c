$NetBSD$

--- misc/ftp_funcs.c.orig	2015-08-03 10:14:29.000000000 +0000
+++ misc/ftp_funcs.c
@@ -30,6 +30,7 @@
 /* this works for libc6 systems, unclear
  * wether it will not work on other systems */
 #include <netinet/in.h>
+#include <sys/socket.h>
 
 #include "network.h"
 
