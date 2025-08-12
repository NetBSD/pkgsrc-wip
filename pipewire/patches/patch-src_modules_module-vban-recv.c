$NetBSD$

--- src/modules/module-vban-recv.c.orig	2025-07-29 20:14:02.633438730 +0000
+++ src/modules/module-vban-recv.c
@@ -33,6 +33,10 @@
 #include <module-vban/vban.h>
 #include "network-utils.h"
 
+#if defined(__NetBSD__)
+#define ip_mreqn ip_mreq
+#endif
+
 /** \page page_module_vban_recv VBAN receiver
  *
  * The `vban-recv` module creates a PipeWire source that receives audio
@@ -244,7 +248,9 @@ static int make_socket(const struct sock
 			struct ip_mreqn mr4;
 			memset(&mr4, 0, sizeof(mr4));
 			mr4.imr_multiaddr = sa4->sin_addr;
+#if !defined(__NetBSD__)
 			mr4.imr_ifindex = req.ifr_ifindex;
+#endif
 			res = setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mr4, sizeof(mr4));
 		} else {
 			sa4->sin_addr.s_addr = INADDR_ANY;
