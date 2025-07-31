$NetBSD$

Add NetBSD support.

--- src/socket.c.orig	2025-07-31 18:18:24.287306854 +0000
+++ src/socket.c
@@ -56,7 +56,7 @@
 #ifdef AF_INET6
 #include <net/if.h>
 #include <ifaddrs.h>
-#if defined (__APPLE__) || defined (__FreeBSD__) || defined (__HAIKU__)
+#if defined (__APPLE__) || defined (__FreeBSD__) || defined (__HAIKU__) || defined (__NetBSD__)
 #include <net/if_dl.h>
 #endif
 #ifdef __linux__
@@ -907,13 +907,13 @@ int get_primary_mac_address(unsigned cha
 			if (ifa->ifa_flags & IFF_LOOPBACK) {
 				continue;
 			}
-#if defined(__APPLE__) || defined (__FreeBSD__) || defined (__HAIKU__)
+#if defined(__APPLE__) || defined (__FreeBSD__) || defined (__HAIKU__) || defined (__NetBSD__)
 			if (ifa->ifa_addr->sa_family != AF_LINK) {
 				continue;
 			}
 #if defined (__APPLE__)
 			if (!strcmp(ifa->ifa_name, "en0")) {
-#elif defined (__FreeBSD__) || defined (__HAIKU__)
+#elif defined (__FreeBSD__) || defined (__HAIKU__) || defined (__NetBSD__)
 			{
 #endif
 				memcpy(mac_addr_buf, (unsigned char *)LLADDR((struct sockaddr_dl *)(ifa)->ifa_addr), 6);
