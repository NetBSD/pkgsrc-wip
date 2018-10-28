$NetBSD$

Treats NetBSD like {Free,Open}BSD

--- src/rawsock-getroute.c.orig	2017-06-06 03:59:39.000000000 +0000
+++ src/rawsock-getroute.c
@@ -10,7 +10,7 @@
 #include "ranges.h" /*for parsing IPv4 addresses */
 
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <unistd.h>
 #include <sys/socket.h>
 #include <net/route.h>
