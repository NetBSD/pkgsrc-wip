$NetBSD$

Respect PKG_SYSCONFDIR
Socket functions generally expect sockaddr, not sockaddr_in 

--- in.dns/in.dns.c.orig	2013-05-16 08:26:34.000000000 +0000
+++ in.dns/in.dns.c
@@ -26,15 +26,15 @@
 #include <syslog.h>
 #endif
 
-#define CONFIG "/etc/in.dns.conf"
+#define CONFIG SYSCONFDIR "/in.dns.conf"
 #define STDIN 0
 #define STDOUT 1
 
 char packet[1024];
 int endmarker = 0;
 char response[1024];
-struct sockaddr_in from;
-size_t fromlen;
+struct sockaddr from;
+socklen_t fromlen;
 
 int gotanswer = 0;
 int ip_lookup = 1;
