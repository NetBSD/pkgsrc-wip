$NetBSD$

--- lib/msan/msan_interceptors.cc.orig	2017-12-04 19:21:18.823244713 +0000
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
@@ -140,9 +153,14 @@ INTERCEPTOR(SSIZE_T, readlink, const cha
   return res;
 }
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(void *, mempcpy, void *dest, const void *src, SIZE_T n) {
   return (char *)__msan_memcpy(dest, src, n) + n;
 }
+#define MSAN_MAYBE_INTERCEPT_MEMPCPY INTERCEPT_FUNCTION(mempcpy)
+#else
+#define MSAN_MAYBE_INTERCEPT_MEMPCPY
+#endif
 
 INTERCEPTOR(void *, memccpy, void *dest, const void *src, int c, SIZE_T n) {
   ENSURE_MSAN_INITED();
@@ -182,6 +200,7 @@ INTERCEPTOR(void *, aligned_alloc, SIZE_
   return msan_aligned_alloc(alignment, size, &stack);
 }
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(void *, __libc_memalign, SIZE_T alignment, SIZE_T size) {
   GET_MALLOC_STACK_TRACE;
   void *ptr = msan_memalign(alignment, size, &stack);
@@ -189,6 +208,10 @@ INTERCEPTOR(void *, __libc_memalign, SIZ
     DTLS_on_libc_memalign(ptr, size);
   return ptr;
 }
+#define MSAN_MAYBE_INTERCEPT___LIBC_MEMALIGN INTERCEPT_FUNCTION(__libc_memalign)
+#else
+#define MSAN_MAYBE_INTERCEPT___LIBC_MEMALIGN
+#endif
 
 INTERCEPTOR(void *, valloc, SIZE_T size) {
   GET_MALLOC_STACK_TRACE;
@@ -222,9 +245,15 @@ INTERCEPTOR(void, cfree, void *ptr) {
 #define MSAN_MAYBE_INTERCEPT_CFREE
 #endif
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(uptr, malloc_usable_size, void *ptr) {
   return __sanitizer_get_allocated_size(ptr);
 }
+#define MSAN_MAYBE_INTERCEPT_MALLOC_USABLE_SIZE \
+  INTERCEPT_FUNCTION(malloc_usable_size)
+#else
+#define MSAN_MAYBE_INTERCEPT_MALLOC_USABLE_SIZE
+#endif
 
 #if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 // This function actually returns a struct by value, but we can't unpoison a
@@ -285,6 +314,7 @@ INTERCEPTOR(char *, strncpy, char *dest,
   return res;
 }
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(char *, stpcpy, char *dest, const char *src) {  // NOLINT
   ENSURE_MSAN_INITED();
   GET_STORE_STACK_TRACE;
@@ -294,6 +324,10 @@ INTERCEPTOR(char *, stpcpy, char *dest, 
   CopyShadowAndOrigin(dest, src, n + 1, &stack);
   return res;
 }
+#define MSAN_MAYBE_INTERCEPT_STPCPY INTERCEPT_FUNCTION(stpcpy)
+#else
+#define MSAN_MAYBE_INTERCEPT_STPCPY
+#endif
 
 INTERCEPTOR(char *, strdup, char *src) {
   ENSURE_MSAN_INITED();
@@ -322,6 +356,7 @@ INTERCEPTOR(char *, __strdup, char *src)
 #define MSAN_MAYBE_INTERCEPT___STRDUP
 #endif
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(char *, gcvt, double number, SIZE_T ndigit, char *buf) {
   ENSURE_MSAN_INITED();
   char *res = REAL(gcvt)(number, ndigit, buf);
@@ -329,6 +364,10 @@ INTERCEPTOR(char *, gcvt, double number,
   __msan_unpoison(buf, n + 1);
   return res;
 }
+#define MSAN_MAYBE_INTERCEPT_GCVT INTERCEPT_FUNCTION(gcvr)
+#else
+#define MSAN_MAYBE_INTERCEPT_GCVT
+#endif
 
 INTERCEPTOR(char *, strcat, char *dest, const char *src) {  // NOLINT
   ENSURE_MSAN_INITED();
@@ -543,6 +582,7 @@ INTERCEPTOR(wchar_t *, wmemcpy, wchar_t 
   return res;
 }
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(wchar_t *, wmempcpy, wchar_t *dest, const wchar_t *src, SIZE_T n) {
   ENSURE_MSAN_INITED();
   GET_STORE_STACK_TRACE;
@@ -550,6 +590,10 @@ INTERCEPTOR(wchar_t *, wmempcpy, wchar_t
   CopyShadowAndOrigin(dest, src, n * sizeof(wchar_t), &stack);
   return res;
 }
+#define MSAN_MAYBE_INTERCEPT_WMEMPCPY INTERCEPT_FUNCTION(wmempcpy)
+#else
+#define MSAN_MAYBE_INTERCEPT_WMEMPCPY
+#endif
 
 INTERCEPTOR(wchar_t *, wmemset, wchar_t *s, wchar_t c, SIZE_T n) {
   CHECK(MEM_IS_APP(s));
@@ -583,6 +627,7 @@ INTERCEPTOR(int, gettimeofday, void *tv,
   return res;
 }
 
+#if !SANITIZER_NETBSD
 INTERCEPTOR(char *, fcvt, double x, int a, int *b, int *c) {
   ENSURE_MSAN_INITED();
   char *res = REAL(fcvt)(x, a, b, c);
@@ -591,6 +636,10 @@ INTERCEPTOR(char *, fcvt, double x, int 
   if (res) __msan_unpoison(res, REAL(strlen)(res) + 1);
   return res;
 }
+#define MSAN_MAYBE_INTERCEPT_FCVT INTERCEPT_FUNCTION(fcvr)
+#else
+#define MSAN_MAYBE_INTERCEPT_FCVT
+#endif
 
 INTERCEPTOR(char *, getenv, char *name) {
   if (msan_init_is_running)
@@ -1073,23 +1122,82 @@ struct MSanAtExitRecord {
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
@@ -1298,7 +1406,7 @@ static int sigaction_impl(int signo, con
         pnew_act->sigaction = (decltype(pnew_act->sigaction))new_cb;
       }
     }
-    res = REAL(sigaction)(signo, pnew_act, oldact);
+    res = REAL(sigaction_symname)(signo, pnew_act, oldact);
     if (res == 0 && oldact) {
       uptr cb = (uptr)oldact->sigaction;
       if (cb == (uptr)SignalAction || cb == (uptr)SignalHandler) {
@@ -1306,7 +1414,7 @@ static int sigaction_impl(int signo, con
       }
     }
   } else {
-    res = REAL(sigaction)(signo, act, oldact);
+    res = REAL(sigaction_symname)(signo, act, oldact);
   }
 
   if (res == 0 && oldact) {
@@ -1484,11 +1592,19 @@ void __msan_unpoison_string(const char* 
   __msan_unpoison(s, REAL(strlen)(s) + 1);
 }
 
+#if SANITIZER_NETBSD
+INTERCEPTOR(void, __libc_thr_keycreate, void *m, void (*dtor)(void *value)) \
+  ALIAS(WRAPPER_NAME(pthread_key_create));
+#endif
+
 namespace __msan {
 
 void InitializeInterceptors() {
   static int inited = 0;
   CHECK_EQ(inited, 0);
+
+  new(interceptor_ctx()) InterceptorContext();
+
   InitializeCommonInterceptors();
   InitializeSignalInterceptors();
 
@@ -1496,7 +1612,7 @@ void InitializeInterceptors() {
   MSAN_MAYBE_INTERCEPT_MMAP64;
   INTERCEPT_FUNCTION(posix_memalign);
   MSAN_MAYBE_INTERCEPT_MEMALIGN;
-  INTERCEPT_FUNCTION(__libc_memalign);
+  MSAN_MAYBE_INTERCEPT___LIBC_MEMALIGN;
   INTERCEPT_FUNCTION(valloc);
   MSAN_MAYBE_INTERCEPT_PVALLOC;
   INTERCEPT_FUNCTION(malloc);
@@ -1504,7 +1620,7 @@ void InitializeInterceptors() {
   INTERCEPT_FUNCTION(realloc);
   INTERCEPT_FUNCTION(free);
   MSAN_MAYBE_INTERCEPT_CFREE;
-  INTERCEPT_FUNCTION(malloc_usable_size);
+  MSAN_MAYBE_INTERCEPT_MALLOC_USABLE_SIZE;
   MSAN_MAYBE_INTERCEPT_MALLINFO;
   MSAN_MAYBE_INTERCEPT_MALLOPT;
   MSAN_MAYBE_INTERCEPT_MALLOC_STATS;
@@ -1512,18 +1628,18 @@ void InitializeInterceptors() {
   MSAN_MAYBE_INTERCEPT_FREAD_UNLOCKED;
   INTERCEPT_FUNCTION(readlink);
   INTERCEPT_FUNCTION(memccpy);
-  INTERCEPT_FUNCTION(mempcpy);
+  MSAN_MAYBE_INTERCEPT_MEMPCPY;
   INTERCEPT_FUNCTION(bcopy);
   INTERCEPT_FUNCTION(wmemset);
   INTERCEPT_FUNCTION(wmemcpy);
-  INTERCEPT_FUNCTION(wmempcpy);
+  MSAN_MAYBE_INTERCEPT_WMEMPCPY;
   INTERCEPT_FUNCTION(wmemmove);
   INTERCEPT_FUNCTION(strcpy);  // NOLINT
-  INTERCEPT_FUNCTION(stpcpy);  // NOLINT
+  MSAN_MAYBE_INTERCEPT_STPCPY;  // NOLINT
   INTERCEPT_FUNCTION(strdup);
   MSAN_MAYBE_INTERCEPT___STRDUP;
   INTERCEPT_FUNCTION(strncpy);  // NOLINT
-  INTERCEPT_FUNCTION(gcvt);
+  MSAN_MAYBE_INTERCEPT_GCVT;
   INTERCEPT_FUNCTION(strcat);  // NOLINT
   INTERCEPT_FUNCTION(strncat);  // NOLINT
   INTERCEPT_STRTO(strtod);
@@ -1568,7 +1684,7 @@ void InitializeInterceptors() {
   INTERCEPT_FUNCTION(setenv);
   INTERCEPT_FUNCTION(putenv);
   INTERCEPT_FUNCTION(gettimeofday);
-  INTERCEPT_FUNCTION(fcvt);
+  MSAN_MAYBE_INTERCEPT_FCVT;
   MSAN_MAYBE_INTERCEPT___FXSTAT;
   MSAN_INTERCEPT_FSTATAT;
   MSAN_MAYBE_INTERCEPT___FXSTAT64;
@@ -1598,12 +1714,17 @@ void InitializeInterceptors() {
   INTERCEPT_FUNCTION(pthread_key_create);
   INTERCEPT_FUNCTION(pthread_join);
   INTERCEPT_FUNCTION(tzset);
+  INTERCEPT_FUNCTION(atexit);
   INTERCEPT_FUNCTION(__cxa_atexit);
   INTERCEPT_FUNCTION(shmat);
   INTERCEPT_FUNCTION(fork);
   INTERCEPT_FUNCTION(openpty);
   INTERCEPT_FUNCTION(forkpty);
 
+#if SANITIZER_NETBSD
+  INTERCEPT_FUNCTION(__libc_thr_keycreate);
+#endif
+
   inited = 1;
 }
 } // namespace __msan
