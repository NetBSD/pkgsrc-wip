$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-11-20 18:08:35.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -1354,10 +1354,15 @@ TSAN_INTERCEPTOR(int, pthread_once, void
   if (o == 0 || f == 0)
     return errno_EINVAL;
   atomic_uint32_t *a;
-  if (!SANITIZER_MAC)
-    a = static_cast<atomic_uint32_t*>(o);
-  else  // On OS X, pthread_once_t has a header with a long-sized signature.
+
+  if (SANITIZER_MAC)
     a = static_cast<atomic_uint32_t*>((void *)((char *)o + sizeof(long_t)));
+  else if (SANITIZER_NETBSD)
+    a = static_cast<atomic_uint32_t*>
+          ((void *)((char *)o + __sanitizer::pthread_mutex_t_sz));
+  else
+    a = static_cast<atomic_uint32_t*>(o);
+
   u32 v = atomic_load(a, memory_order_acquire);
   if (v == 0 && atomic_compare_exchange_strong(a, &v, 1,
                                                memory_order_relaxed)) {
