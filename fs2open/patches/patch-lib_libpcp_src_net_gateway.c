$NetBSD$

Also support NetBSD and OpenBSD.

--- lib/libpcp/src/net/gateway.c.orig	2021-01-27 17:07:03.000000000 +0000
+++ lib/libpcp/src/net/gateway.c
@@ -50,7 +50,7 @@
 #define USE_NETLINK
 #elif defined(WIN32)
 #define USE_WIN32_CODE
-#elif defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #define USE_SYSCTL_NET_ROUTE
 #elif defined(BSD) || defined(__FreeBSD_kernel__)
 #define USE_SYSCTL_NET_ROUTE
