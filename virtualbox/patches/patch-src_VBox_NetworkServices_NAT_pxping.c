$NetBSD$

--- src/VBox/NetworkServices/NAT/pxping.c.orig	2016-03-04 19:29:43.000000000 +0000
+++ src/VBox/NetworkServices/NAT/pxping.c
@@ -560,7 +560,7 @@ pxping_recv4(void *arg, struct pbuf *p)
 #if   defined(RT_OS_LINUX)
         USE_DF_OPTION(IP_MTU_DISCOVER);
         df = df ? IP_PMTUDISC_DO : IP_PMTUDISC_DONT;
-#elif defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
         USE_DF_OPTION(IP_DONTFRAG);
 #elif defined(RT_OS_WINDOWS)
         USE_DF_OPTION(IP_DONTFRAGMENT);
