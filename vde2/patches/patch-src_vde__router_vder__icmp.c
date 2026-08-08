$NetBSD$

Use proper name of icmp message.

--- src/vde_router/vder_icmp.c.orig	2026-08-03 10:48:09.000000000 +0000
+++ src/vde_router/vder_icmp.c
@@ -59,6 +59,10 @@ int vder_icmp_ttl_expired(uint32_t dst, 
 	return vder_icmp_send(dst, ICMP_TIME_EXCEEDED, ICMP_TIMXCEED_INTRANS, foot);
 }
 
+#ifndef ICMP_UNREACH_FILTER_PROHIB
+#define ICMP_UNREACH_FILTER_PROHIB ICMP_UNREACH_ADMIN_PROHIBIT
+#endif
+
 int vder_icmp_filter(uint32_t dst, uint8_t *foot)
 {
 	return vder_icmp_send(dst, ICMP_UNREACH, ICMP_UNREACH_FILTER_PROHIB, foot);
