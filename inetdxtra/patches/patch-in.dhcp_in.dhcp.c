$NetBSD$

Add missing header #includes
Respect PKG_SYSCONFDIR
Socket functions generally expect sockaddr, not sockaddr_in 

--- in.dhcp/in.dhcp.c.orig	2013-04-26 20:00:10.000000000 +0000
+++ in.dhcp/in.dhcp.c
@@ -29,10 +29,17 @@
 #include <stdio.h>
 #include <stdint.h>
 #include <stdlib.h>
+#include <unistd.h>
+#include <ctype.h>
 #include <string.h>
 #include <netdb.h>
 #include <netinet/in.h>
+#include <net/if.h>
+#include <netinet/if_ether.h>
+#include <arpa/inet.h>
+#if defined(__LINUX__)
 #include <netinet/ether.h>
+#endif
 
 #ifdef LOGGING
 #include <syslog.h>
@@ -42,7 +49,7 @@
 #include <syslog.h>
 #endif
 
-#define CONFIG "/etc/in.dhcp.conf.%s"
+#define CONFIG SYSCONFDIR "/in.dhcp.conf.%s"
 #define LEASES "/tmp/in.dhcp.leases.%s"
 #define INBOUND_PACKET "/tmp/in.dhcp.in"
 #define OUTBOUND_PACKET "/tmp/in.dhcp.out"
@@ -190,7 +197,7 @@ uint8_t dhcp_message_type;
 char clientmacstr[30];
 
 // Socket gubbins
-struct sockaddr_in from;
+struct sockaddr from;
 socklen_t fromlen;
 
 // Options we've already set, so we know to ignore
@@ -230,7 +237,6 @@ int recv_data() {
 // Converts an IP address to a 4 byte array and adds
 // it to our packet. Returns the length.
 int addip(unsigned char* p, char* ip) {
-    int i;
     uint32_t add = ntohl(inet_addr(ip));
     #ifdef LOGGING
         syslog(LOG_MAKEPRI(LOG_DAEMON, LOG_DEBUG), "Converting ASCII IP '%s' to 32-bit int %08X", ip, add);
@@ -370,7 +376,7 @@ uint32_t get_pool_address() {
         syslog(LOG_MAKEPRI(LOG_DAEMON, LOG_DEBUG), "Assign pool IP %s for MAC %s (%08X)", inet_ntoa(htonl(i)), clientmacstr, i);
     #endif
     f = fopen(leasesfile, "a");
-    fprintf(f, "%s %s\n", inet_ntoa(htonl(i)), clientmacstr);
+    fprintf(f, "%s %s\n", inet_ntoa(inet_makeaddr(htonl(i), 0L)), clientmacstr);
     fclose(f);
 
     return i;
@@ -807,7 +813,7 @@ int main(int argc, char** argv) {
     #endif
 
     #ifdef ONELOG
-        syslog(LOG_MAKEPRI(LOG_DAEMON, LOG_NOTICE), "%s chaddr=%s yiaddr=%s via=%s", (dhcp_message_type == DHCPDISCOVER ? "DHCPOFFER" : "DHCPACK"), clientmacstr, inet_ntoa(htonl(yiaddr)), (*bindaddress == '\0' ? "255.255.255.255" : bindaddress));
+        syslog(LOG_MAKEPRI(LOG_DAEMON, LOG_NOTICE), "%s chaddr=%s yiaddr=%s via=%s", (dhcp_message_type == DHCPDISCOVER ? "DHCPOFFER" : "DHCPACK"), clientmacstr, inet_ntoa(inet_makeaddr(htonl(yiaddr), 0L)), (*bindaddress == '\0' ? "255.255.255.255" : bindaddress));
     #endif
 
     #ifdef LOGGING
