$NetBSD$

Add support for NetBSD and OpenBSD.

--- lib/libpcpnatpmp/src/net/gateway.c.orig	2026-11-02 22:33:35.357871972 +0000
+++ lib/libpcpnatpmp/src/net/gateway.c
@@ -65,7 +65,7 @@
 #include "pcp_win_defines.h"
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <net/if_dl.h> //struct sockaddr_dl
 
 #include <sys/sysctl.h>
