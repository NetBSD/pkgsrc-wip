$NetBSD$

--- src/VBox/Devices/Network/slirp/udp.c.orig	2016-03-04 19:28:00.000000000 +0000
+++ src/VBox/Devices/Network/slirp/udp.c
@@ -327,7 +327,7 @@ udp_input(PNATState pData, register stru
         const char * const dfoptname = #_Optname;
 #if   defined(IP_MTU_DISCOVER)
         USE_DF_OPTION(IP_MTU_DISCOVER);
-#elif defined(IP_DONTFRAG)      /* Solaris 11+, FreeBSD */
+#elif defined(IP_DONTFRAG)      /* Solaris 11+, FreeBSD, NetBSD */
         USE_DF_OPTION(IP_DONTFRAG);
 #elif defined(IP_DONTFRAGMENT)  /* Windows */
         USE_DF_OPTION(IP_DONTFRAGMENT);
