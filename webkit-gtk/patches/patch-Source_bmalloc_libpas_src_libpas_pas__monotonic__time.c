$NetBSD$

--- Source/bmalloc/libpas/src/libpas/pas_monotonic_time.c.orig	2025-08-08 09:17:56.292456200 +0000
+++ Source/bmalloc/libpas/src/libpas/pas_monotonic_time.c
@@ -36,7 +36,7 @@
 #include <windows.h>
 #endif
 
-#if PAS_OS(LINUX) || PAS_PLATFORM(PLAYSTATION)
+#if PAS_OS(LINUX) || PAS_PLATFORM(PLAYSTATION) || PAS_OS(OPENBSD) || PAS_OS(NETBSD)
 #include <time.h>
 #endif
 
@@ -85,6 +85,15 @@ uint64_t pas_get_current_monotonic_time_nanoseconds(vo
 {
     struct timespec ts;
     clock_gettime(CLOCK_MONOTONIC_COARSE, &ts);
+    return ts.tv_sec * 1.0e9 + ts.tv_nsec;
+}
+
+#elif PAS_OS(OPENBSD) || PAS_OS(NETBSD)
+
+uint64_t pas_get_current_monotonic_time_nanoseconds(void)
+{
+    struct timespec ts;
+    clock_gettime(CLOCK_MONOTONIC, &ts);
     return ts.tv_sec * 1.0e9 + ts.tv_nsec;
 }
 
