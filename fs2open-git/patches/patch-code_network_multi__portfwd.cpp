$NetBSD$

AI_V4MAPPED is not defined on all platforms, define to 0 if necessary.

--- code/network/multi_portfwd.cpp.orig	2019-12-15 06:53:29.495797393 +0000
+++ code/network/multi_portfwd.cpp
@@ -187,6 +187,9 @@ static bool PF_get_addr(const char *host
 
 	hints.ai_family = AF_UNSPEC;
 	hints.ai_socktype = SOCK_DGRAM;
+#ifndef AI_V4MAPPED
+# define AI_V4MAPPED 0
+#endif
 	hints.ai_flags = AI_V4MAPPED;
 
 	if (host == nullptr) {
