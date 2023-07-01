$NetBSD$

NetBSD can benefit from the macros which allow PPSSPP to build on OpenBSD.

--- ppsspp_config.h.orig	2023-06-28 20:56:35.580340514 -0700
+++ ppsspp_config.h	2023-06-28 20:56:48.149019856 -0700
@@ -104,7 +104,7 @@
     #define PPSSPP_PLATFORM_LINUX 1
 #elif defined(__linux__)
     #define PPSSPP_PLATFORM_LINUX 1
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
     #define PPSSPP_PLATFORM_OPENBSD 1
 #endif
 
