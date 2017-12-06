$NetBSD$

--- lib/msan/msan_interceptors.cc.orig	2017-12-06 02:12:26.140110473 +0000
+++ lib/msan/msan_interceptors.cc
@@ -32,11 +32,24 @@
 #include "sanitizer_common/sanitizer_libc.h"
 #include "sanitizer_common/sanitizer_linux.h"
 #include "sanitizer_common/sanitizer_tls_get_addr.h"
+#include "sanitizer_common/sanitizer_vector.h"
 
 #include <stdarg.h>
 // ACHTUNG! No other system header includes in this file.
 // Ideally, we should get rid of stdarg.h as well.
 
+#if SANITIZER_NETBSD
+#define gettimeofday __gettimeofday50
+#define getrusage __getrusage50
+#define shmctl __shmctl50
+#endif
+
+#if SANITIZER_NETBSD
+#define sigaction_symname __sigaction14
+#else
+#define sigaction_symname sigaction
+#endif
+
 using namespace __msan;
 
 using __sanitizer::memory_order;
@@ -1115,23 +1128,82 @@ struct MSanAtExitRecord {
   void *arg;
 };
 
-void MSanAtExitWrapper(void *arg) {
+struct InterceptorContext {
+  BlockingMutex atexit_mu;
+  Vector<struct MSanAtExitRecord *> AtExitStack;
+
+  InterceptorContext()
+      : AtExitStack() {
+  }
+};
+
+static ALIGNED(64) char interceptor_placeholder[sizeof(InterceptorContext)];
+InterceptorContext *interceptor_ctx() {
+  return reinterpret_cast<InterceptorContext*>(&interceptor_placeholder[0]);
+}
+
+void MSanAtExitWrapper() {
+  MSanAtExitRecord *r;
+  {
+    // Ensure thread-safety.
+    BlockingMutexLock l(&interceptor_ctx()->atexit_mu);
+
+    // Pop AtExitCtx from the top of the stack of callback functions
+    uptr element = interceptor_ctx()->AtExitStack.Size() - 1;
+    r = interceptor_ctx()->AtExitStack[element];
+    interceptor_ctx()->AtExitStack.PopBack();
+  }
+
+  UnpoisonParam(1);
+  ((void(*)())r->func)();
+  InternalFree(r);
+}
+
+void MSanCxaAtExitWrapper(void *arg) {
   UnpoisonParam(1);
   MSanAtExitRecord *r = (MSanAtExitRecord *)arg;
   r->func(r->arg);
   InternalFree(r);
 }
 
+static int setup_at_exit_wrapper(void(*f)(), void *arg, void *dso);
+
+// Unpoison argument shadow for C++ module destructors.
+INTERCEPTOR(int, atexit, void (*func)()) {
+  if (msan_init_is_running) return REAL(atexit)(func);
+  return setup_at_exit_wrapper((void(*)())func, 0, 0);
+}
+
 // Unpoison argument shadow for C++ module destructors.
 INTERCEPTOR(int, __cxa_atexit, void (*func)(void *), void *arg,
             void *dso_handle) {
   if (msan_init_is_running) return REAL(__cxa_atexit)(func, arg, dso_handle);
+  return setup_at_exit_wrapper((void(*)())func, arg, dso_handle);
+}
+
+static int setup_at_exit_wrapper(void(*f)(), void *arg, void *dso) {
   ENSURE_MSAN_INITED();
   MSanAtExitRecord *r =
       (MSanAtExitRecord *)InternalAlloc(sizeof(MSanAtExitRecord));
-  r->func = func;
+  r->func = (void(*)(void *a))f;
   r->arg = arg;
-  return REAL(__cxa_atexit)(MSanAtExitWrapper, r, dso_handle);
+  int res;
+  if (!dso) {
+    // NetBSD does not preserve the 2nd argument if dso is equal to 0
+    // Store ctx in a local stack-like structure
+
+    // Ensure thread-safety.
+    BlockingMutexLock l(&interceptor_ctx()->atexit_mu);
+
+    res = REAL(__cxa_atexit)((void (*)(void *a))MSanAtExitWrapper, 0, 0);
+    // Push AtExitCtx on the top of the stack of callback functions
+    if (!res) {
+      interceptor_ctx()->AtExitStack.PushBack(r);
+    }
+  } else {
+    res = REAL(__cxa_atexit)(MSanCxaAtExitWrapper, r, dso);
+  }
+  return res;
 }
 
 DECLARE_REAL(int, shmctl, int shmid, int cmd, void *buf)
@@ -1340,7 +1412,7 @@ static int sigaction_impl(int signo, con
         pnew_act->sigaction = (decltype(pnew_act->sigaction))new_cb;
       }
     }
-    res = REAL(sigaction)(signo, pnew_act, oldact);
+    res = REAL(sigaction_symname)(signo, pnew_act, oldact);
     if (res == 0 && oldact) {
       uptr cb = (uptr)oldact->sigaction;
       if (cb == (uptr)SignalAction || cb == (uptr)SignalHandler) {
@@ -1348,7 +1420,7 @@ static int sigaction_impl(int signo, con
       }
     }
   } else {
-    res = REAL(sigaction)(signo, act, oldact);
+    res = REAL(sigaction_symname)(signo, act, oldact);
   }
 
   if (res == 0 && oldact) {
@@ -1531,6 +1603,9 @@ namespace __msan {
 void InitializeInterceptors() {
   static int inited = 0;
   CHECK_EQ(inited, 0);
+
+  new(interceptor_ctx()) InterceptorContext();
+
   InitializeCommonInterceptors();
   InitializeSignalInterceptors();
 
@@ -1646,6 +1721,7 @@ void InitializeInterceptors() {
 
   INTERCEPT_FUNCTION(pthread_join);
   INTERCEPT_FUNCTION(tzset);
+  INTERCEPT_FUNCTION(atexit);
   INTERCEPT_FUNCTION(__cxa_atexit);
   INTERCEPT_FUNCTION(shmat);
   INTERCEPT_FUNCTION(fork);
