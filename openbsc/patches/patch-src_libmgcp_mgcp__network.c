$NetBSD: patch-src_libmgcp_mgcp__network.c,v 1.1 2011/08/02 23:05:26 khorben Exp $

--- src/libmgcp/mgcp_network.c.orig	2011-03-05 14:16:19.000000000 +0000
+++ src/libmgcp/mgcp_network.c
@@ -42,6 +42,12 @@
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
