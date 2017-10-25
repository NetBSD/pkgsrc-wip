$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2017-10-25 19:03:28.000000000 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors.inc
@@ -3795,7 +3795,7 @@ INTERCEPTOR(void, _exit, int status) {
 #define INIT__EXIT
 #endif
 
-#if SANITIZER_INTERCEPT_PHTREAD_MUTEX
+#if SANITIZER_INTERCEPT_PHTREAD_MUTEX && 0
 INTERCEPTOR(int, pthread_mutex_lock, void *m) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, pthread_mutex_lock, m);
