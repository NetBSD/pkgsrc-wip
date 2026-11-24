$NetBSD$

* Add NetBSD support

--- node_modules/.pnpm/cpu-features@0.0.10/node_modules/cpu-features/deps/cpu_features/include/cpu_features_macros.h.orig	2026-11-24 11:16:04.709448726 +0000
+++ node_modules/.pnpm/cpu-features@0.0.10/node_modules/cpu-features/deps/cpu_features/include/cpu_features_macros.h
@@ -91,6 +91,10 @@
 #define CPU_FEATURES_OS_FREEBSD
 #endif
 
+#if defined(__NetBSD__)
+#define CPU_FEATURES_OS_NETBSD
+#endif
+
 #if defined(__ANDROID__)
 #define CPU_FEATURES_OS_ANDROID
 #endif
