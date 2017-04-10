$NetBSD$

Include netinet/in.h for IPPROTO_TCP

--- src/updater.c.orig	2017-04-10 16:23:09.000000000 +0000
+++ src/updater.c
@@ -25,6 +25,7 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #endif
 
 #include "native/main.h" // Include after winsock2
