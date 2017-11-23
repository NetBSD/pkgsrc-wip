$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-11-21 09:38:56.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -502,15 +502,17 @@ static void SetJmp(ThreadState *thr, upt
 static void LongJmp(ThreadState *thr, uptr *env) {
 #ifdef __powerpc__
   uptr mangled_sp = env[0];
-#elif SANITIZER_FREEBSD || SANITIZER_NETBSD
+#elif SANITIZER_FREEBSD
   uptr mangled_sp = env[2];
+#elif SANITIZER_NETBSD
+  uptr mangled_sp = env[6];
 #elif SANITIZER_MAC
 # ifdef __aarch64__
     uptr mangled_sp = env[13];
 # else
     uptr mangled_sp = env[2];
 # endif
-#elif defined(SANITIZER_LINUX)
+#elif SANITIZER_LINUX
 # ifdef __aarch64__
   uptr mangled_sp = env[13];
 # elif defined(__mips64)
@@ -548,7 +550,37 @@ extern "C" void __tsan_setjmp(uptr sp, u
   SetJmp(cur_thread(), sp, mangled_sp);
 }
 
-#if SANITIZER_MAC
+#if SANITIZER_NETBSD
+// Not called.  Merely to satisfy TSAN_INTERCEPT().
+extern "C" SANITIZER_INTERFACE_ATTRIBUTE
+int __interceptor___setjmp14(void *env);
+extern "C" int __interceptor___setjmp14(void *env) {
+  CHECK(0);
+  return 0;
+}
+
+// FIXME: any reason to have a separate declaration?
+extern "C" SANITIZER_INTERFACE_ATTRIBUTE
+int __interceptor___sigsetjmp14(void *env, int val);
+extern "C" int __interceptor___sigsetjmp14(void *env, int val) {
+  CHECK(0);
+  return 0;
+}
+
+extern "C" SANITIZER_INTERFACE_ATTRIBUTE
+int __interceptor_setjmp(void *env);
+extern "C" int __interceptor_setjmp(void *env) {
+  CHECK(0);
+  return 0;
+}
+
+extern "C" int __setjmp14(void *env);
+extern "C" int __sigsetjmp14(void *env, int val);
+extern "C" int _setjmp(void *env);
+DEFINE_REAL(int, __setjmp14, void *env)
+DEFINE_REAL(int, __sigsetjmp14, void *env, int val)
+DEFINE_REAL(int, _setjmp, void *env)
+#elif SANITIZER_MAC
 TSAN_INTERCEPTOR(int, setjmp, void *env);
 TSAN_INTERCEPTOR(int, _setjmp, void *env);
 TSAN_INTERCEPTOR(int, sigsetjmp, void *env);
@@ -593,6 +625,38 @@ DEFINE_REAL(int, sigsetjmp, void *env)
 DEFINE_REAL(int, __sigsetjmp, void *env)
 #endif  // SANITIZER_MAC
 
+#if SANITIZER_NETBSD
+TSAN_INTERCEPTOR(void, __longjmp14, uptr *env, int val) {
+  // Note: if we call REAL(longjmp) in the context of ScopedInterceptor,
+  // bad things will happen. We will jump over ScopedInterceptor dtor and can
+  // leave thr->in_ignored_lib set.
+  {
+    SCOPED_INTERCEPTOR_RAW(__longjmp14, env, val);
+  }
+  LongJmp(cur_thread(), env);
+  REAL(__longjmp14)(env, val);
+}
+
+TSAN_INTERCEPTOR(void, __siglongjmp14, uptr *env, int val) {
+  {
+    SCOPED_INTERCEPTOR_RAW(__siglongjmp14, env, val);
+  }
+  LongJmp(cur_thread(), env);
+  REAL(__siglongjmp14)(env, val);
+}
+
+TSAN_INTERCEPTOR(void, _longjmp, uptr *env, int val) {
+  // Note: if we call REAL(longjmp) in the context of ScopedInterceptor,
+  // bad things will happen. We will jump over ScopedInterceptor dtor and can
+  // leave thr->in_ignored_lib set.
+  {
+    SCOPED_INTERCEPTOR_RAW(_longjmp, env, val);
+  }
+  LongJmp(cur_thread(), env);
+  REAL(_longjmp)(env, val);
+}
+#else
+
 TSAN_INTERCEPTOR(void, longjmp, uptr *env, int val) {
   // Note: if we call REAL(longjmp) in the context of ScopedInterceptor,
   // bad things will happen. We will jump over ScopedInterceptor dtor and can
@@ -611,6 +675,7 @@ TSAN_INTERCEPTOR(void, siglongjmp, uptr 
   LongJmp(cur_thread(), env);
   REAL(siglongjmp)(env, val);
 }
+#endif
 
 #if !SANITIZER_MAC
 TSAN_INTERCEPTOR(void*, malloc, uptr size) {
@@ -868,6 +933,7 @@ void DestroyThreadState() {
   }
   DTLS_Destroy();
   cur_thread_finalize();
+  thr->tctx->SetDestroyed();
 }
 }  // namespace __tsan
 
@@ -982,12 +1048,14 @@ TSAN_INTERCEPTOR(int, pthread_create,
 
 TSAN_INTERCEPTOR(int, pthread_join, void *th, void **ret) {
   SCOPED_INTERCEPTOR_RAW(pthread_join, th, ret);
-  int tid = ThreadTid(thr, pc, (uptr)th);
+  ThreadContextBase *tctx = ThreadTctx(thr, pc, (uptr)th);
   ThreadIgnoreBegin(thr, pc);
   int res = BLOCK_REAL(pthread_join)(th, ret);
   ThreadIgnoreEnd(thr, pc);
   if (res == 0) {
-    ThreadJoin(thr, pc, tid);
+    while (!tctx->GetDestroyed())
+       internal_sched_yield();
+    ThreadJoin(thr, pc, tctx->tid);
   }
   return res;
 }
@@ -996,10 +1064,10 @@ DEFINE_REAL_PTHREAD_FUNCTIONS
 
 TSAN_INTERCEPTOR(int, pthread_detach, void *th) {
   SCOPED_TSAN_INTERCEPTOR(pthread_detach, th);
-  int tid = ThreadTid(thr, pc, (uptr)th);
+  ThreadContextBase *tctx = ThreadTctx(thr, pc, (uptr)th);
   int res = REAL(pthread_detach)(th);
   if (res == 0) {
-    ThreadDetach(thr, pc, tid);
+    ThreadDetach(thr, pc, tctx->tid);
   }
   return res;
 }
@@ -2332,7 +2400,7 @@ static __sanitizer_sighandler_ptr signal
   internal_memset(&act.sa_mask, -1, sizeof(act.sa_mask));
   act.sa_flags = 0;
   __sanitizer_sigaction old;
-  int res = sigaction(sig, &act, &old);
+  int res = sigaction_symname(sig, &act, &old);
   if (res) return (__sanitizer_sighandler_ptr)sig_err;
   return old.handler;
 }
@@ -2540,6 +2608,17 @@ void InitializeInterceptors() {
   InitializeCommonInterceptors();
   InitializeSignalInterceptors();
 
+#if SANITIZER_NETBSD
+  using __interception::GetRealFunctionAddress;
+  GetRealFunctionAddress("__setjmp14", (uptr*)&REAL(__setjmp14), 0, 0);
+  GetRealFunctionAddress("__sigsetjmp14", (uptr*)&REAL(__sigsetjmp14), 0, 0);
+  GetRealFunctionAddress("_setjmp", (uptr*)&REAL(_setjmp), 0, 0);
+
+  TSAN_INTERCEPT(__longjmp14);
+  TSAN_INTERCEPT(__siglongjmp14);
+  TSAN_INTERCEPT(_longjmp);
+#else
+
 #if !SANITIZER_MAC
   // We can not use TSAN_INTERCEPT to get setjmp addr,
   // because it does &setjmp and setjmp is not present in some versions of libc.
@@ -2552,6 +2631,7 @@ void InitializeInterceptors() {
 
   TSAN_INTERCEPT(longjmp);
   TSAN_INTERCEPT(siglongjmp);
+#endif
 
   TSAN_INTERCEPT(malloc);
   TSAN_INTERCEPT(__libc_memalign);
