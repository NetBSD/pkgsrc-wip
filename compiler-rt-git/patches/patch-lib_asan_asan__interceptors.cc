$NetBSD$

--- lib/asan/asan_interceptors.cc.orig	2017-07-03 15:33:06.000000000 +0000
+++ lib/asan/asan_interceptors.cc
@@ -424,6 +424,11 @@ INTERCEPTOR(int, swapcontext, struct uco
 }
 #endif  // ASAN_INTERCEPT_SWAPCONTEXT
 
+#if SANITIZER_NETBSD
+#define longjmp __longjmp14
+#define siglongjmp __siglongjmp14
+#endif
+
 INTERCEPTOR(void, longjmp, void *env, int val) {
   __asan_handle_no_return();
   REAL(longjmp)(env, val);
