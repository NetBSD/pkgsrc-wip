$NetBSD$

Add NetBSD support.

--- nasl/nasl_packet_forgery.c.orig	2015-08-03 10:14:31.000000000 +0000
+++ nasl/nasl_packet_forgery.c
@@ -146,7 +146,11 @@ forge_ip_packet (lex_ctxt * lexic)
   if (s != NULL)
     inet_aton (s, &pkt->ip_dst);
   else
+#if defined(__NetBSD__)
+    memcpy(&pkt->ip_dst.s_addr, &dst_addr->s6_addr[12], 4);
+#else
     pkt->ip_dst.s_addr = dst_addr->s6_addr32[3];
+#endif
 
   if (data != NULL)
     {
@@ -1400,7 +1404,11 @@ nasl_tcp_ping (lex_ctxt * lexic)
 
   if (dst == NULL || (IN6_IS_ADDR_V4MAPPED (dst) != 1))
     return NULL;
+#if defined(__NetBSD__)
+  memcpy(&inaddr.s_addr, &dst->s6_addr[12], 4);
+#else
   inaddr.s_addr = dst->s6_addr32[3];
+#endif
   for (i = 0; i < sizeof (sports) / sizeof (int); i++)
     {
       if (sports[i] == 0)
@@ -1422,7 +1430,11 @@ nasl_tcp_ping (lex_ctxt * lexic)
     port = plug_get_host_open_port (script_infos);
 
   if (islocalhost (&inaddr) > 0)
+#if defined(__NetBSD__)
+    memcpy(&src.s_addr, &dst->s6_addr[12], 4);
+#else
     src.s_addr = dst->s6_addr32[3];
+#endif
   else
     {
       bzero (&src, sizeof (src));
@@ -1536,7 +1548,11 @@ nasl_send_packet (lex_ctxt * lexic)
 
   if (dstip == NULL || (IN6_IS_ADDR_V4MAPPED (dstip) != 1))
     return NULL;
+#if defined(__NetBSD__)
+  memcpy(&inaddr.s_addr, &dstip->s6_addr[12], 4);
+#else
   inaddr.s_addr = dstip->s6_addr32[3];
+#endif
   soc = socket (AF_INET, SOCK_RAW, IPPROTO_RAW);
   if (soc < 0)
     return NULL;
@@ -1656,7 +1672,11 @@ nasl_pcap_next (lex_ctxt * lexic)
         {
           struct in_addr src;
           bzero (&src, sizeof (src));
+#if defined(__NetBSD__)
+          memcpy(&inaddr.s_addr, &dst->s6_addr[12], 4);
+#else
           inaddr.s_addr = dst->s6_addr32[3];
+#endif
           interface = routethrough (&inaddr, &src);
         }
       else
@@ -1791,7 +1811,11 @@ nasl_send_capture (lex_ctxt * lexic)
         {
           struct in_addr src;
           bzero (&src, sizeof (src));
+#if defined(__NetBSD__)
+          memcpy(&inaddr.s_addr, &dst->s6_addr[12], 4);
+#else
           inaddr.s_addr = dst->s6_addr32[3];
+#endif
           interface = routethrough (&inaddr, &src);
         }
       else
