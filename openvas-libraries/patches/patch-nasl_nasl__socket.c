$NetBSD$

--- nasl/nasl_socket.c.orig	2016-07-22 06:15:35.000000000 +0000
+++ nasl/nasl_socket.c
@@ -266,7 +266,11 @@ tryagain:
   if (IN6_IS_ADDR_V4MAPPED (p))
     {
       bzero (&daddr, sizeof (daddr));
+#if defined(__NetBSD__)
+      memcpy(&daddr.sin_addr.s_addr, &p->s6_addr[12], 4);
+#else
       daddr.sin_addr.s_addr = p->s6_addr32[3];
+#endif
       daddr.sin_family = AF_INET;
       daddr.sin_port = htons (dport);
       unblock_socket (sock);
@@ -504,7 +508,11 @@ nasl_open_sock_udp (lex_ctxt * lexic)
   if (IN6_IS_ADDR_V4MAPPED (ia))
     {
       bzero (&soca, sizeof (soca));
+#if defined(__NetBSD__)
+      memcpy(&soca.sin_addr.s_addr, &ia->s6_addr[12], 4);
+#else
       soca.sin_addr.s_addr = ia->s6_addr32[3];
+#endif
       soca.sin_port = htons (port);
       soca.sin_family = AF_INET;
 
