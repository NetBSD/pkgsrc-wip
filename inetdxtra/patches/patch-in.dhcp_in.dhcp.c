$NetBSD: patch-in.dhcp_in.dhcp.c,v 1.1 2014/05/16 15:19:19 hfath Exp $

--- in.dhcp/in.dhcp.c.orig	2011-01-13 15:53:56.000000000 +0000
+++ in.dhcp/in.dhcp.c
@@ -32,7 +32,11 @@
 #include <string.h>
 #include <netdb.h>
 #include <netinet/in.h>
+#include <net/if.h>
+#include <netinet/if_ether.h>
+#if defined(__LINUX__)
 #include <netinet/ether.h>
+#endif
 
 #ifdef LOGGING
 #include <syslog.h>
@@ -42,7 +46,7 @@
 #include <syslog.h>
 #endif
 
-#define CONFIG "/etc/in.dhcp.conf.%s"
+#define CONFIG SYSCONFDIR "/in.dhcp.conf.%s"
 #define LEASES "/tmp/in.dhcp.leases.%s"
 #define INBOUND_PACKET "/tmp/in.dhcp.in"
 #define OUTBOUND_PACKET "/tmp/in.dhcp.out"
@@ -190,7 +194,7 @@ uint8_t dhcp_message_type;
 char clientmacstr[30];
 
 // Socket gubbins
-struct sockaddr_in from;
+struct sockaddr from;
 socklen_t fromlen;
 
 // Options we've already set, so we know to ignore
