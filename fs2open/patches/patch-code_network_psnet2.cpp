$NetBSD$

AI_V4MAPPED is not defined on all platforms, define to 0 if necessary.

--- code/network/psnet2.cpp.orig	2021-01-27 17:07:03.000000000 +0000
+++ code/network/psnet2.cpp
@@ -1113,6 +1113,9 @@ bool psnet_get_addr(const char *host, co
 
 	hints.ai_family = AF_UNSPEC;
 	hints.ai_socktype = 0;
+#ifndef AI_V4MAPPED
+#define AI_V4MAPPED 0
+#endif
 	hints.ai_flags = AI_V4MAPPED;
 
 	if (flags & ADDR_FLAG_NUMERIC_SERVICE) {
