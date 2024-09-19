$NetBSD$

NetBSD does not need any macro (re)adjustments.

Shared upstream via:

 <https://github.com/nmap/ncrack/pull/71>

--- portable_endian.h.orig	2019-08-24 22:25:32.000000000 +0000
+++ portable_endian.h
@@ -81,11 +81,11 @@
 #	define __LITTLE_ENDIAN LITTLE_ENDIAN
 #	define __PDP_ENDIAN    PDP_ENDIAN
 
-#elif defined(__OpenBSD__)
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
 
 #	include <sys/endian.h>
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 
 #	include <sys/endian.h>
 
