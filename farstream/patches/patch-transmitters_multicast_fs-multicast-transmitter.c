$NetBSD: patch-transmitters_multicast_fs-multicast-transmitter.c,v 1.1 2014/04/18 21:35:52 thomasklausner Exp $

Fixes
In file included from fs-multicast-transmitter.c:57:0:
/usr/include/netinet/ip.h:68:19: error: field 'ip_src' has incomplete type
/usr/include/netinet/ip.h:68:27: error: field 'ip_dst' has incomplete type
/usr/include/netinet/ip.h:204:19: error: field 'ipt_addr' has incomplete type
/usr/include/netinet/ip.h:240:17: error: field 'ippseudo_src' has incomplete type
/usr/include/netinet/ip.h:241:17: error: field 'ippseudo_dst' has incomplete type

Accepted upstream via
https://bugs.freedesktop.org/show_bug.cgi?id=23377

--- transmitters/multicast/fs-multicast-transmitter.c.orig	2013-04-04 18:28:45.000000000 +0000
+++ transmitters/multicast/fs-multicast-transmitter.c
@@ -54,7 +54,6 @@
 # define close closesocket
 #else /*G_OS_WIN32*/
 # include <sys/socket.h>
-# include <netinet/ip.h>
 # include <arpa/inet.h>
 #endif /*G_OS_WIN32*/
 
