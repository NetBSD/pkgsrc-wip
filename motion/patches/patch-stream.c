$NetBSD$

portability: bind expects length to match appropriate sockaddr structure  

--- stream.c.orig	2017-06-10 16:56:20.000000000 +0100
+++ stream.c	2017-06-10 16:56:47.000000000 +0100
@@ -752,7 +752,7 @@
         }
     }
 
-    if (bind(sd, (struct sockaddr*)&sin, sizeof(sin)) != 0) {
+    if (bind(sd, (struct sockaddr*)&sin, (ipv6_enabled?sizeof(struct sockaddr_in6):sizeof(struct sockaddr_in))) != 0) {
         MOTION_LOG(NTC, TYPE_STREAM, NO_ERRNO, "%s: error binding on %s port %d", addr_str, port);
         close(sd);
         return -1;
