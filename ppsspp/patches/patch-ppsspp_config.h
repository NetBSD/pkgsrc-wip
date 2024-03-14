$NetBSD$

NetBSD can benefit from the functionality provided for OpenBSD.

--- ppsspp_config.h.orig	2024-03-13 21:19:45.715917776 -0700
+++ ppsspp_config.h	2024-03-13 21:19:58.391397099 -0700
@@ -115,7 +115,7 @@
     #define PPSSPP_PLATFORM_LINUX 1
 #elif defined(__linux__)
     #define PPSSPP_PLATFORM_LINUX 1
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
     #define PPSSPP_PLATFORM_OPENBSD 1
 #endif
 
