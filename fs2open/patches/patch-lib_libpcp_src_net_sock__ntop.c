$NetBSD$

AI_V4MAPPED is not defined on all platforms, define to 0 if necessary.

--- lib/libpcp/src/net/sock_ntop.c.orig	2019-12-15 06:53:29.678798451 +0000
+++ lib/libpcp/src/net/sock_ntop.c
@@ -175,6 +175,9 @@ sock_pton(const char* cp, struct sockadd
         memset(&hints, 0, sizeof hints);
         hints.ai_family = AF_UNSPEC;
         hints.ai_socktype = SOCK_DGRAM;
+#ifndef AI_V4MAPPED
+# define AI_V4MAPPED 0
+#endif
         hints.ai_flags = AI_V4MAPPED;
 
         if ((rv = getaddrinfo(host_name, port, &hints, &servinfo)) != 0) {
