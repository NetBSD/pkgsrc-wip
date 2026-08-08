$NetBSD$

Forward declare struct so its scope isn't limited to the func declaration.

--- src/vde_router/vder_packet.h.orig	2026-08-03 10:48:09.000000000 +0000
+++ src/vde_router/vder_packet.h
@@ -6,6 +6,8 @@
 #ifndef _VDER_PACKET
 #define _VDER_PACKET
 
+struct iphdr;
+
 #define DEFAULT_TTL 64
 uint16_t vder_ip_checksum(struct iphdr *iph);
 void vder_packet_recv(struct vder_iface *vif, int timeout);
