$NetBSD$

Disable IPX for NetBSD.

--- src/i_tcp.c.orig	2018-07-16 09:17:06.000000000 +0000
+++ src/i_tcp.c
@@ -135,6 +135,7 @@
 # ifdef USE_IPX
 # include <wsipx.h>
 # endif // USE_IPX
+
 #else
   // Not Windows
 
@@ -169,6 +170,13 @@
 # endif
 #endif
 
+#ifdef NETBSD
+// NetBSD does not have IPX.
+# ifdef USE_IPX
+#   undef USE_IPX
+# endif
+#endif
+
 // Reported to be __OpenBSD__ , but it should be all caps and I am paranoid.
 #if defined( __OpenBSD__ ) || defined( __OPENBSD__ )
 // OpenBSD does not have IPX.
@@ -413,15 +421,15 @@ char *SOCK_AddrToStr(mysockaddr_t *sk)
 boolean IPX_cmpaddr(mysockaddr_t *a, mysockaddr_t *b)
 {
 #ifdef LINUX
-#ifdef FREEBSD
+# ifdef FREEBSD
     // FreeBSD: IPX address compare
     return ipx_neteq( a->ipx.sipx_addr, b->ipx.sipx_addr) &&
            ipx_hosteq( a->ipx.sipx_addr, b->ipx.sipx_addr );
-#else
+# else
     // Linux (except FreeBSD): IPX address compare
     return ((memcmp(&(a->ipx.sipx_network) ,&(b->ipx.sipx_network) ,4)==0) &&
             (memcmp(&(a->ipx.sipx_node),&(b->ipx.sipx_node),6)==0));
-#endif
+# endif
 #else
     // Windows, OS2, DJGPP: IPX address compare
     return ((memcmp(&(a->ipx.sa_netnum) ,&(b->ipx.sa_netnum) ,4)==0) &&
