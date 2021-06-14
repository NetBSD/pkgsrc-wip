$NetBSD$

We don't have AI_V4MAPPED or AI_ALL


--- src/jdk.jdwp.agent/share/native/libdt_socket/socketTransport.c.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/jdk.jdwp.agent/share/native/libdt_socket/socketTransport.c	2021-06-11 13:43:34.646986516 -0400
@@ -392,7 +392,7 @@
          * pass hostname == NULL to getaddrinfo.
          */
         hints.ai_family = allowOnlyIPv4 ? AF_INET : AF_INET6;
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
         hints.ai_flags |= AI_PASSIVE;
 #else
         hints.ai_flags |= AI_PASSIVE | (allowOnlyIPv4 ? 0 : AI_V4MAPPED | AI_ALL);
