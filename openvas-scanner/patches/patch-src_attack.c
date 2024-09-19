$NetBSD$

Add NetBSD support.

--- src/attack.c.orig	2016-08-25 12:07:28.000000000 +0000
+++ src/attack.c
@@ -647,7 +647,11 @@ attack_start (struct attack_start_args *
     {
       char *txt_ip;
       struct in_addr inaddr;
+#if defined(__NetBSD__)
+      memcpy(&inaddr.s_addr, &hostip->s6_addr[12], 4);
+#else
       inaddr.s_addr = hostip->s6_addr32[3];
+#endif
 
       if (IN6_IS_ADDR_V4MAPPED (hostip))
         txt_ip = g_strdup (inet_ntoa (inaddr));
