$NetBSD$

--- simgear/canvas/ShivaVG/src/shConfig.h.orig	2015-02-18 20:10:39.000000000 +0000
+++ simgear/canvas/ShivaVG/src/shConfig.h
@@ -26,7 +26,7 @@
     // MacOS
     #define VG_API_MACOSX
 
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 
     // FreeBSD
     #define VG_API_FREEBSD
