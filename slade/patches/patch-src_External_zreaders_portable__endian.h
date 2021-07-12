$NetBSD$

NetBSD already has defined beXXtoh() and leXXtoh(x) in "sys/endian.h".

--- src/External/zreaders/portable_endian.h.orig	2020-05-27 23:08:34.000000000 +0000
+++ src/External/zreaders/portable_endian.h
@@ -48,11 +48,11 @@
 #	define __LITTLE_ENDIAN LITTLE_ENDIAN
 #	define __PDP_ENDIAN    PDP_ENDIAN
 
-#elif defined(__OpenBSD__)
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
 
 #	include <sys/endian.h>
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 
 #	include <sys/endian.h>
 
