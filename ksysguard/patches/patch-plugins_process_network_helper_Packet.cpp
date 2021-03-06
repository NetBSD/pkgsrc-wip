$NetBSD$

BSD's use if_ether.h

--- plugins/process/network/helper/Packet.cpp.orig	2020-05-05 14:44:00.000000000 +0000
+++ plugins/process/network/helper/Packet.cpp
@@ -23,7 +23,11 @@
 
 #include <sys/types.h>
 #include <arpa/inet.h>
+#ifdef __linux__
 #include <net/ethernet.h>
+#else
+#include <net/if_ether.h>
+#endif
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/ip6.h>
