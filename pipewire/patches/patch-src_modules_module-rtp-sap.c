$NetBSD$

--- src/modules/module-rtp-sap.c.orig	2025-07-23 15:42:58.000000000 +0000
+++ src/modules/module-rtp-sap.c
@@ -32,6 +32,10 @@
 #define SO_PASSCRED LOCAL_CREDS_PERSISTENT
 #endif
 
+#if defined(__NetBSD__)
+#define ip_mreqn ip_mreq
+#endif
+
 /** \page page_module_rtp_sap SAP Announce and create RTP streams
  *
  * The `rtp-sap` module announces RTP streams that match the rules with the
@@ -391,10 +395,12 @@ static int make_unix_socket(const char *
 	}
 
 	int val = 1;
+#if !defined(__NetBSD__)
 	if (setsockopt(fd, SOL_SOCKET, SO_PASSCRED, &val, sizeof(val)) < 0) {
 		pw_log_warn("Failed to bind PTP management socket");
 		return -1;
 	}
+#endif
 
 	spa_zero(addr);
 	addr.sun_family = AF_UNIX;
@@ -490,7 +496,9 @@ static int make_recv_socket(struct socka
 			struct ip_mreqn mr4;
 			memset(&mr4, 0, sizeof(mr4));
 			mr4.imr_multiaddr = sa4->sin_addr;
+#if !defined(__NetBSD__)
 			mr4.imr_ifindex = req.ifr_ifindex;
+#endif
 			pw_net_get_ip(sa, addr, sizeof(addr), NULL, NULL);
 			pw_log_info("join IPv4 group: %s iface:%d", addr, req.ifr_ifindex);
 			res = setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mr4, sizeof(mr4));
