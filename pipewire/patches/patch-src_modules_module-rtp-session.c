$NetBSD$

--- src/modules/module-rtp-session.c.orig	2025-07-29 20:27:37.922024927 +0000
+++ src/modules/module-rtp-session.c
@@ -39,6 +39,10 @@
 #include <module-rtp/stream.h>
 #include "network-utils.h"
 
+#if defined(__NetBSD__)
+#define ip_mreqn ip_mreq
+#endif
+
 /** \page page_module_rtp_session RTP session
  *
  * The `rtp-session` module creates a media session that is announced
@@ -1103,7 +1107,9 @@ static int make_socket(const struct sock
 			struct ip_mreqn mr4;
 			memset(&mr4, 0, sizeof(mr4));
 			mr4.imr_multiaddr = sa4->sin_addr;
+#if !defined(__NetBSD__)
 			mr4.imr_ifindex = req.ifr_ifindex;
+#endif
 			res = setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mr4, sizeof(mr4));
 			is_multicast = true;
 		} else {
