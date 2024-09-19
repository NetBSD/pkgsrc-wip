$NetBSD$

--- src/VBox/NetworkServices/NAT/pxudp.c.orig	2016-03-04 19:29:43.000000000 +0000
+++ src/VBox/NetworkServices/NAT/pxudp.c
@@ -603,7 +603,7 @@ pxudp_pcb_forward_outbound(struct pxudp 
         const char * const dfoptname = #_Optname;
 #if   defined(IP_MTU_DISCOVER)  /* Linux */
         USE_DF_OPTION(IP_MTU_DISCOVER);
-#elif defined(IP_DONTFRAG)      /* Solaris 11+, FreeBSD */
+#elif defined(IP_DONTFRAG)      /* Solaris 11+, FreeBSD, NetBSD */
         USE_DF_OPTION(IP_DONTFRAG);
 #elif defined(IP_DONTFRAGMENT)  /* Windows */
         USE_DF_OPTION(IP_DONTFRAGMENT);
