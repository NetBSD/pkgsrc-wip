$NetBSD$

--- lib/msan/msan_interceptors.cc.orig	2018-01-08 15:33:13.000000000 +0000
+++ lib/msan/msan_interceptors.cc
@@ -33,6 +33,7 @@
 #include "sanitizer_common/sanitizer_libc.h"
 #include "sanitizer_common/sanitizer_linux.h"
 #include "sanitizer_common/sanitizer_tls_get_addr.h"
+#include "sanitizer_common/sanitizer_vector.h"
 
 #if SANITIZER_NETBSD
 #define fstat __fstat50
@@ -689,6 +690,73 @@ INTERCEPTOR(int, putenv, char *string) {
   return res;
 }
 
+#if SANITIZER_NETBSD && 0
+INTERCEPTOR(int, kvm_dump_header, void *kb, int op, int arg, void *cnt) {
+  ENSURE_MSAN_INITED();
+  int res = REAL(fstat)(fd, buf);
+  if (!res)
+    __msan_unpoison(buf, __sanitizer::struct_stat_sz);
+  return res;
+}
+
+INTERCEPTOR(void *, kvm_getprocs, void *kb, int op, int arg, void *cnt) {
+  ENSURE_MSAN_INITED();
+  int res = REAL(fstat)(fd, buf);
+  if (!res)
+    __msan_unpoison(buf, __sanitizer::struct_stat_sz);
+  return res;
+}
+
+kvm_close
+0000000000004b99 T kvm_dump_header
+000000000000565e T kvm_dump_inval
+00000000000048cc T kvm_dump_mkheader
+0000000000004d35 T kvm_dump_wrtheader
+0000000000003f7e T kvm_getargv
+0000000000004006 T kvm_getargv2
+0000000000003fc2 T kvm_getenvv
+0000000000004015 T kvm_getenvv2
+00000000000043d3 T kvm_geterr
+000000000000194b T kvm_getfiles
+00000000000043d8 T kvm_getkernelname
+00000000000017ec T kvm_getloadavg
+00000000000020f3 T kvm_getlwps
+0000000000002ed4 T kvm_getproc2
+0000000000002ae8 T kvm_getprocs
+00000000000055ca T kvm_nlist
+0000000000005524 T kvm_open
+00000000000054b1 T kvm_openfiles
+00000000000057b9 T kvm_read
+0000000000004024 T kvm_uread
+000000000000595f T kvm_write
+
+#define MSAN_MAYBE_INTERCEPT_LIBKVM_FUNCTIONS \
+  INTERCEPT_FUNCTION(kvm_getproc2); \
+  INTERCEPT_FUNCTION(kvm_dump_header); \
+  INTERCEPT_FUNCTION(kvm_dump_inval); \
+  INTERCEPT_FUNCTION(kvm_dump_mkheader); \
+  INTERCEPT_FUNCTION(kvm_dump_wrtheader); \
+  INTERCEPT_FUNCTION(kvm_getargv); \
+  INTERCEPT_FUNCTION(kvm_getargv2); \
+  INTERCEPT_FUNCTION(kvm_getenvv); \
+  INTERCEPT_FUNCTION(kvm_getenvv2); \
+  INTERCEPT_FUNCTION(kvm_geterr); \
+  INTERCEPT_FUNCTION(kvm_getfiles); \
+  INTERCEPT_FUNCTION(kvm_getkernelname); \
+  INTERCEPT_FUNCTION(kvm_getloadavg); \
+  INTERCEPT_FUNCTION(kvm_getlwps); \
+  INTERCEPT_FUNCTION(kvm_getproc2); \
+  INTERCEPT_FUNCTION(kvm_getprocs); \
+  INTERCEPT_FUNCTION(kvm_nlist); \
+  INTERCEPT_FUNCTION(kvm_open); \
+  INTERCEPT_FUNCTION(kvm_openfiles); \
+  INTERCEPT_FUNCTION(kvm_read); \
+  INTERCEPT_FUNCTION(kvm_uread); \
+  INTERCEPT_FUNCTION(kvm_write)
+#else
+#define MSAN_MAYBE_INTERCEPT_LIBKVM_FUNCTIONS
+#endif
+
 #if SANITIZER_NETBSD
 INTERCEPTOR(int, fstat, int fd, void *buf) {
   ENSURE_MSAN_INITED();
@@ -1152,23 +1220,78 @@ struct MSanAtExitRecord {
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
@@ -1401,6 +1524,7 @@ static uptr signal_impl(int signo, uptr 
   } while (false)
 #define COMMON_SYSCALL_POST_WRITE_RANGE(p, s) __msan_unpoison(p, s)
 #include "sanitizer_common/sanitizer_common_syscalls.inc"
+#include "sanitizer_common/sanitizer_netbsd_syscalls.inc"
 
 struct dlinfo {
   char *dli_fname;
@@ -1566,6 +1690,9 @@ namespace __msan {
 void InitializeInterceptors() {
   static int inited = 0;
   CHECK_EQ(inited, 0);
+
+  new(interceptor_ctx()) InterceptorContext();
+
   InitializeCommonInterceptors();
   InitializeSignalInterceptors();
 
@@ -1682,6 +1809,7 @@ void InitializeInterceptors() {
 
   INTERCEPT_FUNCTION(pthread_join);
   INTERCEPT_FUNCTION(tzset);
+  INTERCEPT_FUNCTION(atexit);
   INTERCEPT_FUNCTION(__cxa_atexit);
   INTERCEPT_FUNCTION(shmat);
   INTERCEPT_FUNCTION(fork);
