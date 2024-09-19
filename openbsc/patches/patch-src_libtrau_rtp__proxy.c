$NetBSD: patch-src_libtrau_rtp__proxy.c,v 1.1 2011/08/02 23:05:26 khorben Exp $

--- src/libtrau/rtp_proxy.c.orig	2011-03-05 14:16:19.000000000 +0000
+++ src/libtrau/rtp_proxy.c
@@ -39,6 +39,12 @@
 #include <sys/types.h>
 #include <sys/param.h>
 #include <limits.h>
+#ifdef __NetBSD__
+# include <sys/endian.h>
+# define __BYTE_ORDER _BYTE_ORDER
+# define __BIG_ENDIAN _BIG_ENDIAN
+# define __LITTLE_ENDIAN _LITTLE_ENDIAN
+#endif
 
 #ifndef __BYTE_ORDER
 #error "__BYTE_ORDER should be defined by someone"
