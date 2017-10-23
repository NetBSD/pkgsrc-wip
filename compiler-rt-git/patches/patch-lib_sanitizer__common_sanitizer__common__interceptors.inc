$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2017-10-20 11:21:05.000000000 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors.inc
@@ -4405,7 +4405,7 @@ INTERCEPTOR(char *, tempnam, char *dir, 
 #define INIT_TEMPNAM
 #endif
 
-#if SANITIZER_INTERCEPT_PTHREAD_SETNAME_NP
+#if SANITIZER_INTERCEPT_PTHREAD_SETNAME_NP && !SANITIZER_NETBSD
 INTERCEPTOR(int, pthread_setname_np, uptr thread, const char *name) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, pthread_setname_np, thread, name);
@@ -4414,6 +4414,15 @@ INTERCEPTOR(int, pthread_setname_np, upt
   return REAL(pthread_setname_np)(thread, name);
 }
 #define INIT_PTHREAD_SETNAME_NP COMMON_INTERCEPT_FUNCTION(pthread_setname_np);
+#elif SANITIZER_INTERCEPT_PTHREAD_SETNAME_NP && SANITIZER_NETBSD
+INTERCEPTOR(int, pthread_setname_np, uptr thread, const char *name, void *arg) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, pthread_setname_np, thread, name, arg);
+  COMMON_INTERCEPTOR_READ_STRING(ctx, name, 0);
+  COMMON_INTERCEPTOR_SET_PTHREAD_NAME(ctx, thread, name, arg);
+  return REAL(pthread_setname_np)(thread, name, arg);
+}
+#define INIT_PTHREAD_SETNAME_NP COMMON_INTERCEPT_FUNCTION(pthread_setname_np);
 #else
 #define INIT_PTHREAD_SETNAME_NP
 #endif
