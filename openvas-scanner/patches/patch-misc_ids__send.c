$NetBSD$

--- misc/ids_send.c.orig	2015-08-03 10:14:29.000000000 +0000
+++ misc/ids_send.c
@@ -36,6 +36,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
 
 #include "arglists.h"
 #include "bpf_share.h"
@@ -713,7 +714,11 @@ ids_open_sock_tcp (args, port, method, t
   if (IN6_IS_ADDR_V4MAPPED (dst6))
     {
       family = AF_INET;
+#if defined(__NetBSD__)
+      memcpy(&dst.s_addr, &dst6->s6_addr[12], 4);
+#else
       dst.s_addr = dst6->s6_addr32[3];
+#endif
       src.s_addr = 0;
       iface = routethrough (&dst, &src);
       src_host = g_strdup (inet_ntoa (src));
