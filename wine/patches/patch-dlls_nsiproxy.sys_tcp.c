$NetBSD$

struct ip is not yet defined.

--- dlls/nsiproxy.sys/tcp.c.orig	2022-01-18 20:52:35.000000000 +0000
+++ dlls/nsiproxy.sys/tcp.c
@@ -43,6 +43,9 @@
 #endif
 
 #ifdef HAVE_NETINET_IN_PCB_H
+#if defined(__NetBSD__)
+#include <netinet/ip.h>
+#endif
 #include <netinet/in_pcb.h>
 #endif
 
