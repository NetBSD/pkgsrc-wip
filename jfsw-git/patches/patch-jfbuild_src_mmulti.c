$NetBSD$

AI_V4MAPPED is not defined on some platforms.

--- jfbuild/src/mmulti.c.orig	2018-12-18 11:09:10.000000000 +0000
+++ jfbuild/src/mmulti.c
@@ -900,7 +900,9 @@ static int lookuphost(const char *name, 
 	hints.ai_flags = AI_ADDRCONFIG;
 	hints.ai_family = domain;
 	if (domain == PF_INET6) {
+#ifdef AI_V4MAPPED
 		hints.ai_flags |= AI_V4MAPPED;
+#endif
 	}
 	hints.ai_socktype = SOCK_DGRAM;
 	hints.ai_protocol = IPPROTO_UDP;
