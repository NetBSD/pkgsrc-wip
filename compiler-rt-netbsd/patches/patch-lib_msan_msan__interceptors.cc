$NetBSD$

--- lib/msan/msan_interceptors.cc.orig	2018-02-01 23:46:00.000000000 +0000
+++ lib/msan/msan_interceptors.cc
@@ -33,11 +33,13 @@
 #include "sanitizer_common/sanitizer_libc.h"
 #include "sanitizer_common/sanitizer_linux.h"
 #include "sanitizer_common/sanitizer_tls_get_addr.h"
+#include "sanitizer_common/sanitizer_vector.h"
 
 #if SANITIZER_NETBSD
 #define fstat __fstat50
 #define gettimeofday __gettimeofday50
 #define getrusage __getrusage50
+#define tzset __tzset50
 #endif
 
 #include <stdarg.h>
@@ -514,6 +516,7 @@ INTERCEPTOR(SIZE_T, __strxfrm_l, char *d
 
 #define INTERCEPTOR_STRFTIME_BODY(char_type, ret_type, func, s, ...) \
   ENSURE_MSAN_INITED();                                              \
+  InterceptorScope interceptor_scope;                                \
   ret_type res = REAL(func)(s, __VA_ARGS__);                         \
   if (s) __msan_unpoison(s, sizeof(char_type) * (res + 1));          \
   return res;
@@ -779,6 +782,7 @@ INTERCEPTOR(int, socketpair, int domain,
 
 INTERCEPTOR(char *, fgets, char *s, int size, void *stream) {
   ENSURE_MSAN_INITED();
+  InterceptorScope interceptor_scope;
   char *res = REAL(fgets)(s, size, stream);
   if (res)
     __msan_unpoison(s, REAL(strlen)(s) + 1);
@@ -1128,6 +1132,18 @@ INTERCEPTOR(int, pthread_join, void *th,
 
 extern char *tzname[2];
 
+#if SANITIZER_NETBSD
+INTERCEPTOR(void, tzset, void) {
+  ENSURE_MSAN_INITED();
+  InterceptorScope interceptor_scope;
+  REAL(tzset)();
+  if (tzname[0])
+    __msan_unpoison(tzname[0], REAL(strlen)(tzname[0]) + 1);
+  if (tzname[1])
+    __msan_unpoison(tzname[1], REAL(strlen)(tzname[1]) + 1);
+  return;
+}
+#else
 INTERCEPTOR(void, tzset, int fake) {
   ENSURE_MSAN_INITED();
   REAL(tzset)(fake);
@@ -1137,29 +1153,85 @@ INTERCEPTOR(void, tzset, int fake) {
     __msan_unpoison(tzname[1], REAL(strlen)(tzname[1]) + 1);
   return;
 }
+#endif
 
 struct MSanAtExitRecord {
   void (*func)(void *arg);
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
+    BlockingMutexLock l(&interceptor_ctx()->atexit_mu);
+
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
+    BlockingMutexLock l(&interceptor_ctx()->atexit_mu);
+
+    res = REAL(__cxa_atexit)((void (*)(void *a))MSanAtExitWrapper, 0, 0);
+    if (!res) {
+      interceptor_ctx()->AtExitStack.PushBack(r);
+    }
+  } else {
+    res = REAL(__cxa_atexit)(MSanCxaAtExitWrapper, r, dso);
+  }
+  return res;
 }
 
 static void BeforeFork() {
@@ -1313,6 +1385,11 @@ int OnExit() {
     __msan_unpoison(to + size, 1);                          \
   } while (false)
 
+#if SANITIZER_NETBSD1
+#define COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE       \
+  InterceptorScope interceptor_scope;
+#endif
+
 #include "sanitizer_common/sanitizer_platform_interceptors.h"
 #include "sanitizer_common/sanitizer_common_interceptors.inc"
 
@@ -1392,6 +1469,7 @@ static uptr signal_impl(int signo, uptr 
   } while (false)
 #define COMMON_SYSCALL_POST_WRITE_RANGE(p, s) __msan_unpoison(p, s)
 #include "sanitizer_common/sanitizer_common_syscalls.inc"
+#include "sanitizer_common/sanitizer_netbsd_syscalls.inc"
 
 struct dlinfo {
   char *dli_fname;
@@ -1557,6 +1635,9 @@ namespace __msan {
 void InitializeInterceptors() {
   static int inited = 0;
   CHECK_EQ(inited, 0);
+
+  new(interceptor_ctx()) InterceptorContext();
+
   InitializeCommonInterceptors();
   InitializeSignalInterceptors();
 
@@ -1672,6 +1753,7 @@ void InitializeInterceptors() {
 
   INTERCEPT_FUNCTION(pthread_join);
   INTERCEPT_FUNCTION(tzset);
+  INTERCEPT_FUNCTION(atexit);
   INTERCEPT_FUNCTION(__cxa_atexit);
   INTERCEPT_FUNCTION(shmat);
   INTERCEPT_FUNCTION(fork);
