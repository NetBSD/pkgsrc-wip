$NetBSD$

Include netinet/in.h for IPPROTO_TCP

--- src/updater.c.orig	2017-01-24 20:49:40.564174586 +0000
+++ src/updater.c
@@ -20,6 +20,7 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #endif
 
 
