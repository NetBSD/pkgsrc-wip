$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-10-17 18:35:44.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -43,8 +43,16 @@ using namespace __tsan;  // NOLINT
 #if SANITIZER_NETBSD
 #define dirfd(dirp) (*(int *)(dirp))
 #define fileno_unlocked fileno
-#define stdout __sF[1]
-#define stderr __sF[2]
+
+#if _LP64
+#define __sF_size 152
+#else
+#define __sF_size 88
+#endif
+
+#define stdout ((char*)&__sF + (__sF_size * 1))
+#define stderr ((char*)&__sF + (__sF_size * 2))
+
 #endif
 
 #if SANITIZER_ANDROID
@@ -99,7 +107,7 @@ extern "C" int dirfd(void *dirp);
 extern "C" int mallopt(int param, int value);
 #endif
 #if SANITIZER_NETBSD
-extern __sanitizer_FILE **__sF;
+extern __sanitizer_FILE __sF[];
 #else
 extern __sanitizer_FILE *stdout, *stderr;
 #endif
@@ -388,8 +396,8 @@ static void at_exit_wrapper(void *arg) {
   uptr pc = 0;
   Acquire(thr, pc, (uptr)arg);
   AtExitCtx *ctx = (AtExitCtx*)arg;
-  ((void(*)(void *arg))ctx->f)(ctx->arg);
-  InternalFree(ctx);
+//  ((void(*)(void *arg))ctx->f)(ctx->arg);
+//  InternalFree(ctx);
 }
 
 static int setup_at_exit_wrapper(ThreadState *thr, uptr pc, void(*f)(),
@@ -912,6 +920,38 @@ extern "C" void *__tsan_thread_start_fun
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
@@ -1667,13 +1707,6 @@ TSAN_INTERCEPTOR(void*, tmpfile64, int f
 #define TSAN_MAYBE_INTERCEPT_TMPFILE64
 #endif
 
-static void FlushStreams() {
-  // Flushing all the streams here may freeze the process if a child thread is
-  // performing file stream operations at the same time.
-  REAL(fflush)(stdout);
-  REAL(fflush)(stderr);
-}
-
 TSAN_INTERCEPTOR(void, abort, int fake) {
   SCOPED_TSAN_INTERCEPTOR(abort, fake);
   FlushStreams();
@@ -2439,15 +2472,6 @@ TSAN_INTERCEPTOR(void *, __tls_get_addr,
 
 namespace __tsan {
 
-static void finalize(void *arg) {
-  ThreadState *thr = cur_thread();
-  int status = Finalize(thr);
-  // Make sure the output is not lost.
-  FlushStreams();
-  if (status)
-    Die();
-}
-
 #if !SANITIZER_MAC && !SANITIZER_ANDROID
 static void unreachable() {
   Report("FATAL: ThreadSanitizer: unreachable called\n");
@@ -2611,6 +2635,7 @@ void InitializeInterceptors() {
   REAL(atexit) = (int(*)(void(*)()))unreachable;
 #endif
 
+#if 0
   if (REAL(__cxa_atexit)(&finalize, 0, 0)) {
     Printf("ThreadSanitizer: failed to setup atexit callback\n");
     Die();
@@ -2622,6 +2647,7 @@ void InitializeInterceptors() {
     Die();
   }
 #endif
+#endif
 
   FdInit();
 }
