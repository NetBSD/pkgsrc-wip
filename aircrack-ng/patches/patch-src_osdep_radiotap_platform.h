$NetBSD: patch-src_osdep_radiotap_platform.h,v 1.1 2015/02/07 01:35:39 tnn2 Exp $

--- src/osdep/radiotap/platform.h.orig	2014-03-22 20:26:59.000000000 +0000
+++ src/osdep/radiotap/platform.h
@@ -3,7 +3,7 @@
 #ifndef _BSD_SOURCE
 #define _BSD_SOURCE
 #endif
-#include <endian.h>
+#include <sys/endian.h>
 
 #define le16_to_cpu		le16toh
 #define le32_to_cpu		le32toh
