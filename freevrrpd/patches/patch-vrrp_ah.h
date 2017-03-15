$NetBSD$

Conditionally #include FreeBSD-only headers

--- vrrp_ah.h.orig	2015-02-04 00:39:49.000000000 +0000
+++ vrrp_ah.h
@@ -18,8 +18,10 @@
 #ifdef KAME_BASED
 #include <netinet6/ipsec.h>
 #include <net/pfkeyv2.h>
+#ifdef __FreeBSD__
 #include <netkey/keydb.h>
 #include <netkey/key_debug.h>
+#endif /* __FreeBSD__ */
 #endif /* end of KAME BASED */
 /* #include "md5.h" */
 
