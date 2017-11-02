$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-10-25 19:03:27.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -265,7 +265,7 @@ static ThreadSignalContext *SigCtx(Threa
   return ctx;
 }
 
-#if !SANITIZER_MAC
+#if !SANITIZER_MAC && !SANITIZER_NETBSD
 static unsigned g_thread_finalize_key;
 #endif
 
@@ -866,7 +866,7 @@ void DestroyThreadState() {
 }
 }  // namespace __tsan
 
-#if !SANITIZER_MAC
+#if !SANITIZER_MAC && !SANITIZER_NETBSD
 static void thread_finalize(void *v) {
   uptr iter = (uptr)v;
   if (iter > 1) {
@@ -896,7 +896,7 @@ extern "C" void *__tsan_thread_start_fun
     ThreadState *thr = cur_thread();
     // Thread-local state is not initialized yet.
     ScopedIgnoreInterceptors ignore;
-#if !SANITIZER_MAC
+#if !SANITIZER_MAC && !SANITIZER_NETBSD
     ThreadIgnoreBegin(thr, 0);
     if (pthread_setspecific(g_thread_finalize_key,
                             (void *)GetPthreadDestructorIterations())) {
@@ -2445,6 +2445,17 @@ TSAN_INTERCEPTOR(void *, __tls_get_addr,
 }
 #endif
 
+#if SANITIZER_NETBSD
+TSAN_INTERCEPTOR(void, _lwp_exit) {
+  SCOPED_TSAN_INTERCEPTOR(_lwp_exit);
+  DestroyThreadState();
+  REAL(_lwp_exit)();
+}
+#define TSAN_MAYBE_INTERCEPT__LWP_EXIT TSAN_INTERCEPT(_lwp_exit)
+#else
+#define TSAN_MAYBE_INTERCEPT__LWP_EXIT
+#endif
+
 namespace __tsan {
 
 static void finalize(void *arg) {
@@ -2613,6 +2624,8 @@ void InitializeInterceptors() {
   TSAN_INTERCEPT(__tls_get_addr);
 #endif
 
+  TSAN_MAYBE_INTERCEPT__LWP_EXIT;
+
 #if !SANITIZER_MAC && !SANITIZER_ANDROID
   // Need to setup it, because interceptors check that the function is resolved.
   // But atexit is emitted directly into the module, so can't be resolved.
@@ -2624,7 +2637,7 @@ void InitializeInterceptors() {
     Die();
   }
 
-#if !SANITIZER_MAC
+#if !SANITIZER_MAC && !SANITIZER_NETBSD
   if (pthread_key_create(&g_thread_finalize_key, &thread_finalize)) {
     Printf("ThreadSanitizer: failed to create thread key\n");
     Die();
