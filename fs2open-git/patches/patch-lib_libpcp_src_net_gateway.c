$NetBSD$

Also support NetbSD and OpenBSD.

--- lib/libpcp/src/net/gateway.c.orig	2019-12-15 06:53:29.677263118 +0000
+++ lib/libpcp/src/net/gateway.c
@@ -62,7 +62,7 @@
 #include "pcp_win_defines.h"
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/sysctl.h>
 #include <net/if_dl.h>          //struct sockaddr_dl
 #define USE_SOCKET_ROUTE
