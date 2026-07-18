$NetBSD$

Under NetBSD setsocopt for IP_MULTICAST_IF wants in_addr

--- src/udpsocket.c.orig	2026-07-16 13:19:57.954770500 +0000
+++ src/udpsocket.c
@@ -361,7 +361,11 @@ int udpsocket_set_mcast_iface(int sd, co
 	if (family == AF_INET6) {
 		return setsockopt(sd, SOL_IPV6, IPV6_MULTICAST_IF, &scope, sizeof(scope));
 	} else {
+#ifdef __NetBSD__
+		struct in_addr req = { .s_addr = scope };
+#else
 		struct ip_mreqn req = { .imr_ifindex = scope };
+#endif
 		return setsockopt(sd, SOL_IP, IP_MULTICAST_IF, &req, sizeof(req));
 	}
 	return -1;
