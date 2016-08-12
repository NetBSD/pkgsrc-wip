$NetBSD$

--- src/VBox/NetworkServices/NAT/pxping.c.orig	2016-08-05 17:05:42.000000000 +0000
+++ src/VBox/NetworkServices/NAT/pxping.c
@@ -562,6 +562,8 @@ pxping_recv4(void *arg, struct pbuf *p)
         df = df ? IP_PMTUDISC_DO : IP_PMTUDISC_DONT;
 #elif defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
         USE_DF_OPTION(IP_DONTFRAG);
+#elif defined(RT_OS_NETBSD)
+        USE_DF_OPTION(IP_DF);
 #elif defined(RT_OS_WINDOWS)
         USE_DF_OPTION(IP_DONTFRAGMENT);
 #endif
