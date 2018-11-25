$NetBSD$

Include the correct endian.h on NetBSD.

--- include/byteorder.h.orig	2018-11-22 06:17:27.000000000 +0000
+++ include/byteorder.h
@@ -115,11 +115,11 @@
 #define _BSD_SOURCE
 #include <endian.h>
 
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
 
 #include <sys/endian.h>
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 
 #include <sys/endian.h>
 
