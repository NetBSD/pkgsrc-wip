$NetBSD$

Portability

--- lib/socket_srt.cpp.orig	2026-07-15 08:18:23.213246931 +0000
+++ lib/socket_srt.cpp
@@ -67,7 +67,10 @@ namespace Socket{
     memset(&hints, 0, sizeof(struct addrinfo));
     hints.ai_family = AF_INET6;
     hints.ai_socktype = SOCK_DGRAM;
-    hints.ai_flags = AI_ADDRCONFIG | AI_ALL;
+    hints.ai_flags = AI_ADDRCONFIG;
+#ifdef AI_ALL
+    hints.ai_flags |= AI_ALL;
+#endif
     hints.ai_protocol = IPPROTO_UDP;
     hints.ai_canonname = NULL;
     hints.ai_addr = NULL;
