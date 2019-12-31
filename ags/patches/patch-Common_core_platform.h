$NetBSD$

Use the LINUX definitions for {Free,Net,Open}BSD.

--- Common/core/platform.h.orig	2019-12-29 17:06:00.000000000 +0000
+++ Common/core/platform.h
@@ -55,7 +55,7 @@
     #else
         #error "Unknown Apple platform"
     #endif
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     #define AGS_PLATFORM_OS_WINDOWS (0)
     #define AGS_PLATFORM_OS_LINUX   (1)
     #define AGS_PLATFORM_OS_MACOS   (0)
@@ -102,4 +102,4 @@
     #define AGS_PLATFORM_DEBUG  (0)
 #endif
 
-#endif // __AC_PLATFORM_H
\ No newline at end of file
+#endif // __AC_PLATFORM_H
