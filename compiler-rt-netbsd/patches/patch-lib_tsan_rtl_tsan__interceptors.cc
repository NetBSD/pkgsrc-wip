$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-10-17 18:35:44.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -257,7 +257,7 @@ static ThreadSignalContext *SigCtx(Threa
   return ctx;
 }
 
-#if !SANITIZER_MAC
+#if !SANITIZER_MAC && !SANITIZER_NETBSD
 static unsigned g_thread_finalize_key;
 #endif
 
@@ -387,9 +387,9 @@ static void at_exit_wrapper(void *arg) {
   ThreadState *thr = cur_thread();
   uptr pc = 0;
   Acquire(thr, pc, (uptr)arg);
-  AtExitCtx *ctx = (AtExitCtx*)arg;
-  ((void(*)(void *arg))ctx->f)(ctx->arg);
-  InternalFree(ctx);
+//  AtExitCtx *ctx = (AtExitCtx*)arg;
+//  ((void(*)(void *arg))ctx->f)(ctx->arg);
+//  InternalFree(ctx);
 }
 
 static int setup_at_exit_wrapper(ThreadState *thr, uptr pc, void(*f)(),
@@ -858,7 +858,7 @@ void DestroyThreadState() {
 }
 }  // namespace __tsan
 
-#if !SANITIZER_MAC
+#if !SANITIZER_MAC && !SANITIZER_NETBSD
 static void thread_finalize(void *v) {
   uptr iter = (uptr)v;
   if (iter > 1) {
@@ -888,7 +888,7 @@ extern "C" void *__tsan_thread_start_fun
     ThreadState *thr = cur_thread();
     // Thread-local state is not initialized yet.
     ScopedIgnoreInterceptors ignore;
-#if !SANITIZER_MAC
+#if !SANITIZER_MAC && !SANITIZER_NETBSD
     ThreadIgnoreBegin(thr, 0);
     if (pthread_setspecific(g_thread_finalize_key,
                             (void *)GetPthreadDestructorIterations())) {
@@ -1670,8 +1670,8 @@ TSAN_INTERCEPTOR(void*, tmpfile64, int f
 static void FlushStreams() {
   // Flushing all the streams here may freeze the process if a child thread is
   // performing file stream operations at the same time.
-  REAL(fflush)(stdout);
-  REAL(fflush)(stderr);
+//  REAL(fflush)(stdout);
+//  REAL(fflush)(stderr);
 }
 
 TSAN_INTERCEPTOR(void, abort, int fake) {
@@ -2439,6 +2439,7 @@ TSAN_INTERCEPTOR(void *, __tls_get_addr,
 
 namespace __tsan {
 
+#if 0
 static void finalize(void *arg) {
   ThreadState *thr = cur_thread();
   int status = Finalize(thr);
@@ -2447,6 +2448,7 @@ static void finalize(void *arg) {
   if (status)
     Die();
 }
+#endif
 
 #if !SANITIZER_MAC && !SANITIZER_ANDROID
 static void unreachable() {
@@ -2611,16 +2613,16 @@ void InitializeInterceptors() {
   REAL(atexit) = (int(*)(void(*)()))unreachable;
 #endif
 
-  if (REAL(__cxa_atexit)(&finalize, 0, 0)) {
-    Printf("ThreadSanitizer: failed to setup atexit callback\n");
-    Die();
-  }
+//  if (REAL(__cxa_atexit)(&finalize, 0, 0)) {
+//    Printf("ThreadSanitizer: failed to setup atexit callback\n");
+//    Die();
+//  }
 
 #if !SANITIZER_MAC
-  if (pthread_key_create(&g_thread_finalize_key, &thread_finalize)) {
-    Printf("ThreadSanitizer: failed to create thread key\n");
-    Die();
-  }
+//  if (pthread_key_create(&g_thread_finalize_key, &thread_finalize)) {
+//    Printf("ThreadSanitizer: failed to create thread key\n");
+//    Die();
+//  }
 #endif
 
   FdInit();
