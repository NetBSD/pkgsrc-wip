$NetBSD$

* Add NetBSD support

--- node_modules/.pnpm/cpu-features@0.0.10/node_modules/cpu-features/deps/cpu_features/src/impl_x86_linux_or_android.c.orig	2026-11-24 11:16:04.732825744 +0000
+++ node_modules/.pnpm/cpu-features@0.0.10/node_modules/cpu-features/deps/cpu_features/src/impl_x86_linux_or_android.c
@@ -15,7 +15,7 @@
 #include "cpu_features_macros.h"
 
 #ifdef CPU_FEATURES_ARCH_X86
-#if defined(CPU_FEATURES_OS_LINUX) || defined(CPU_FEATURES_OS_ANDROID)
+#if defined(CPU_FEATURES_OS_LINUX) || defined(CPU_FEATURES_OS_ANDROID) || defined(CPU_FEATURES_OS_NETBSD)
 
 #include "impl_x86__base_implementation.inl"
 
