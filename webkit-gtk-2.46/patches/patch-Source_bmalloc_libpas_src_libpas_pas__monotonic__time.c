$NetBSD$

--- Source/bmalloc/libpas/src/libpas/pas_monotonic_time.c.orig	2025-10-29 10:25:27.891099365 +0000
+++ Source/bmalloc/libpas/src/libpas/pas_monotonic_time.c
@@ -36,7 +36,7 @@
 #include <windows.h>
 #endif
 
-#if PAS_OS(LINUX) || PAS_PLATFORM(PLAYSTATION)
+#if PAS_OS(LINUX) || PAS_PLATFORM(PLAYSTATION) || PAS_OS(OPENBSD) || PAS_OS(NETBSD)
 #include <time.h>
 #endif
 
@@ -88,6 +88,15 @@ uint64_t pas_get_current_monotonic_time_
     return ts.tv_sec * 1.0e9 + ts.tv_nsec;
 }
 
+#elif PAS_OS(OPENBSD) || PAS_OS(NETBSD)
+
+uint64_t pas_get_current_monotonic_time_nanoseconds(void)
+{
+    struct timespec ts;
+    clock_gettime(CLOCK_MONOTONIC, &ts);
+    return ts.tv_sec * 1.0e9 + ts.tv_nsec;
+}
+
 #elif PAS_PLATFORM(PLAYSTATION)
 
 uint64_t pas_get_current_monotonic_time_nanoseconds(void)
