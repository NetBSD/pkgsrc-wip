$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-10-25 19:03:27.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -395,9 +395,9 @@ static void at_exit_wrapper(void *arg) {
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
@@ -920,6 +920,39 @@ extern "C" void *__tsan_thread_start_fun
   return res;
 }
 
+static void FlushStreams() {
+  // Flushing all the streams here may freeze the process if a child thread is
+  // performing file stream operations at the same time.
+
+  REAL(fflush)(stdout);
+  REAL(fflush)(stderr);
+}
+
+static void finalize(void *arg) {
+  using namespace __tsan;
+  ThreadState *thr = cur_thread();
+  int status = Finalize(thr);
+  // Make sure the output is not lost.
+  FlushStreams();
+  if (status)
+    Die();
+}
+
+__attribute__((constructor))
+//__attribute__((section(".init_array")))
+static void
+yikes1(void) {
+  if (REAL(__cxa_atexit)(&finalize, 0, 0)) {
+    Printf("ThreadSanitizer: failed to setup atexit callback\n");
+    Die();
+  }
+
+  if (pthread_key_create(&g_thread_finalize_key, &thread_finalize)) {
+    Printf("ThreadSanitizer: failed to create thread key\n");
+    Die();
+  }
+}
+
 TSAN_INTERCEPTOR(int, pthread_create,
     void *th, void *attr, void *(*callback)(void*), void * param) {
   SCOPED_INTERCEPTOR_RAW(pthread_create, th, attr, callback, param);
@@ -1675,12 +1708,12 @@ TSAN_INTERCEPTOR(void*, tmpfile64, int f
 #define TSAN_MAYBE_INTERCEPT_TMPFILE64
 #endif
 
-static void FlushStreams() {
-  // Flushing all the streams here may freeze the process if a child thread is
-  // performing file stream operations at the same time.
-  REAL(fflush)(stdout);
-  REAL(fflush)(stderr);
-}
+//static void FlushStreams() {
+//  // Flushing all the streams here may freeze the process if a child thread is
+//  // performing file stream operations at the same time.
+//  REAL(fflush)(stdout);
+//  REAL(fflush)(stderr);
+//}
 
 TSAN_INTERCEPTOR(void, abort, int fake) {
   SCOPED_TSAN_INTERCEPTOR(abort, fake);
@@ -2619,16 +2652,16 @@ void InitializeInterceptors() {
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
