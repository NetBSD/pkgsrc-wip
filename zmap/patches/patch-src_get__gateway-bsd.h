$NetBSD$

No RTF_LLINFO on NetBSD

--- src/get_gateway-bsd.h.orig	2026-07-05 07:29:45.985076874 +0000
+++ src/get_gateway-bsd.h
@@ -38,7 +38,11 @@ int get_hw_addr(struct in_addr *gw_ip, U
 	mib[2] = 0;
 	mib[3] = AF_INET;
 	mib[4] = NET_RT_FLAGS;
+#ifdef RTF_LLINFO
 	mib[5] = RTF_LLINFO;
+#else
+	mib[5] = 0;
+#endif
 	size_t bufsz = 0;
 	if (sysctl(mib, 6, NULL, &bufsz, NULL, 0) == -1) {
 		log_debug("get_hw_addr", "sysctl getting buffer size: %d %s", errno, strerror(errno));
