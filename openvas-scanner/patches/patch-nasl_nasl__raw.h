$NetBSD$

--- nasl/nasl_raw.h.orig	2015-08-03 10:14:31.000000000 +0000
+++ nasl/nasl_raw.h
@@ -43,6 +43,11 @@
 
 #include <netinet/tcp.h>
 #include <netinet/udp.h>
+#if defined(__NetBSD__)
+#include <netinet/in_systm.h>
+#include <netinet/in.h>
+#include <netinet/ip.h>
+#endif
 #include <netinet/ip_icmp.h>
 
 #endif
