$NetBSD$

--- src/modules/module-rtp-source.c.orig	2025-07-29 20:02:44.942300562 +0000
+++ src/modules/module-rtp-source.c
@@ -32,6 +32,10 @@
 #include <module-rtp/stream.h>
 #include "network-utils.h"
 
+#if defined(__NetBSD__)
+#define ip_mreqn ip_mreq
+#endif
+
 /** \page page_module_rtp_source RTP source
  *
  * The `rtp-source` module creates a PipeWire source that receives audio
@@ -270,7 +274,9 @@ static int make_socket(const struct sock
 			struct ip_mreqn mr4;
 			memset(&mr4, 0, sizeof(mr4));
 			mr4.imr_multiaddr = sa4->sin_addr;
+#if !defined(__NetBSD__)
 			mr4.imr_ifindex = req.ifr_ifindex;
+#endif
 			pw_net_get_ip((struct sockaddr_storage*)sa, addr, sizeof(addr), NULL, NULL);
 			pw_log_info("join IPv4 group: %s", addr);
 			res = setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mr4, sizeof(mr4));
