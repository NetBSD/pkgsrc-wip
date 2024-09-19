$NetBSD$

--- src/tun.c.orig	2016-04-07 21:29:50.000000000 +0000
+++ src/tun.c
@@ -50,9 +50,11 @@
 
 #if defined(__FreeBSD__) || defined(__OpenBSD__)
 # include <net/if_var.h>
+#endif
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 # include <netinet/in_var.h>
 #endif
-#if defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 # include <netinet6/in6_var.h>
 #endif
 
@@ -242,7 +244,11 @@ int set_ipv6_addr(main_server_st * s, st
 	ifr6.ifra_dstaddr.sin6_family = AF_INET6;
 
 	ret = ipv6_prefix_to_mask(&ifr6.ifra_prefixmask.sin6_addr, proc->config->ipv6_prefix);
-	if (ret == 0) {
+#if defined(__NetBSD__)
+#else
+	if (ret == 0)
+#endif
+	{
 		memset(&ifr6.ifra_prefixmask.sin6_addr, 0xff, sizeof(struct in6_addr));
 	}
 	ifr6.ifra_prefixmask.sin6_len = sizeof(struct sockaddr_in6);
