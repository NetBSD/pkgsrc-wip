$NetBSD: patch-src_rtpproxy.h,v 1.1 2013/12/28 14:42:29 imilh Exp $

Missing sys/time.h for struct timeval

--- src/rtpproxy.h.orig	2011-05-28 15:47:15.000000000 +0000
+++ src/rtpproxy.h
@@ -22,2 +22,4 @@
 
+#include <sys/time.h>
+
 #define CALLIDNUM_SIZE	256
