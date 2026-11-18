$NetBSD$

AI_V4MAPPED is not defined on all platforms, define to 0 if necessary.

--- lib/libpcpnatpmp/src/net/sock_ntop.c.orig	2026-11-02 21:26:49.118820793 +0000
+++ lib/libpcpnatpmp/src/net/sock_ntop.c
@@ -54,6 +54,10 @@
 #include <net/if_dl.h>
 #endif
 
+#ifndef AI_V4MAPPED
+#define AI_V4MAPPED 0
+#endif
+
 /* include sock_ntop */
 char *sock_ntop(const struct sockaddr *sa, socklen_t salen) {
     char portstr[8];
