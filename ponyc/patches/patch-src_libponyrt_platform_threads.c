$NetBSD$

pthread_np.h is freebsd+openbsd+dragonfly, no netbsd.
provide fallback for PTHREAD_STACK_MIN (XXX is the value reasonable)

--- src/libponyrt/platform/threads.c.orig	2019-07-27 10:37:45.000000000 +0000
+++ src/libponyrt/platform/threads.c
@@ -10,7 +10,7 @@
 #include <sys/mman.h>
 #endif
 
-#if defined(PLATFORM_IS_BSD)
+#if defined(PLATFORM_IS_FREEBSD) || defined(PLATFORM_IS_DRAGONFLY) || defined(PLATFORM_IS_OPENBSD)
 #include <pthread_np.h>
 #endif
 #if defined(PLATFORM_IS_FREEBSD)
@@ -176,6 +176,10 @@ bool ponyint_thread_create(pony_thread_i
   pthread_attr_t* attr_p = &attr;
   pthread_attr_init(attr_p);
 
+#ifndef PTHREAD_STACK_MIN
+#define PTHREAD_STACK_MIN 0x1000
+#endif
+
   // Some systems, e.g., macOS, hav a different default default
   // stack size than the typical system's RLIMIT_STACK.
   // Let's use RLIMIT_STACK's current limit if it is sane.
