$NetBSD$

--- lib/asan/asan_interceptors.cc.orig	2017-10-23 14:29:58.177998728 +0000
+++ lib/asan/asan_interceptors.cc
@@ -118,9 +118,15 @@ DECLARE_REAL_AND_INTERCEPTOR(void, free,
 // But asan does not remember UserId's for threads (pthread_t);
 // and remembers all ever existed threads, so the linear search by UserId
 // can be slow.
+#if !SANITIZER_NETBSD
 #define COMMON_INTERCEPTOR_SET_PTHREAD_NAME(ctx, thread, name) \
   do {                                                         \
   } while (false)
+#else
+#define COMMON_INTERCEPTOR_SET_PTHREAD_NAME(ctx, thread, name, arg) \
+  do {                                                              \
+  } while (false)
+#endif
 #define COMMON_INTERCEPTOR_BLOCK_REAL(name) REAL(name)
 // Strict init-order checking is dlopen-hostile:
 // https://github.com/google/sanitizers/issues/178
