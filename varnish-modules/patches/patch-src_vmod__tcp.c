$NetBSD$

Fix build on NetBSD

--- src/vmod_tcp.c.orig	2021-03-16 10:53:49.000000000 +0000
+++ src/vmod_tcp.c
@@ -46,6 +46,17 @@
 
 #define TCP_CA_NAME_MAX 16
 
+#ifdef __NetBSD__
+#define tcpi_lost __tcpi_lost
+#define tcpi_retrans __tcpi_retrans
+#define tcpi_pmtu __tcpi_pmtu
+#define tcpi_advmss __tcpi_advmss
+#define tcpi_reordering __tcpi_reordering
+#ifndef SOL_TCP
+#define SOL_TCP IPPROTO_TCP
+#endif
+#endif
+
 /*
  * Based on the information found here:
  *   http://linuxgazette.net/136/pfeiffer.html
