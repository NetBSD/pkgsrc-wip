$NetBSD$

--- src/modules/module-netjack2-manager.c.orig	2025-07-29 19:59:44.038954088 +0000
+++ src/modules/module-netjack2-manager.c
@@ -44,6 +44,10 @@
 #define IPTOS_DSCP(x) ((x) & IPTOS_DSCP_MASK)
 #endif
 
+#if defined(__NetBSD__)
+#define ip_mreqn ip_mreq
+#endif
+
 /** \page page_module_netjack2_manager Netjack2 manager
  *
  * The netjack2 manager module listens for new netjack2 driver messages and will
@@ -895,7 +899,9 @@ static int make_announce_socket(struct s
 			struct ip_mreqn mr4;
 			memset(&mr4, 0, sizeof(mr4));
 			mr4.imr_multiaddr = sa4->sin_addr;
+#if !defined(__NetBSD__)
 			mr4.imr_ifindex = req.ifr_ifindex;
+#endif
 			res = setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mr4, sizeof(mr4));
 		} else {
 			sa4->sin_addr.s_addr = INADDR_ANY;
