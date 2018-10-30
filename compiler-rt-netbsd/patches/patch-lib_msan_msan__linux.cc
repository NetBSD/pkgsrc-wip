$NetBSD$

--- lib/msan/msan_linux.cc.orig	2018-08-21 21:25:44.000000000 +0000
+++ lib/msan/msan_linux.cc
@@ -31,6 +31,7 @@
 #include <sys/time.h>
 #include <sys/resource.h>
 
+#include "interception/interception.h"
 #include "sanitizer_common/sanitizer_common.h"
 #include "sanitizer_common/sanitizer_procmaps.h"
 
@@ -175,13 +176,28 @@ void InstallAtExitHandler() {
 
 // ---------------------- TSD ---------------- {{{1
 
+#if !SANITIZER_NETBSD
 static pthread_key_t tsd_key;
+#endif
+
 static bool tsd_key_inited = false;
 
+#if SANITIZER_NETBSD
+INTERCEPTOR(void, _lwp_exit) {
+  CHECK(tsd_key_inited);
+  MsanTSDDtor(GetCurrentThread());
+  REAL(_lwp_exit)();
+}
+#endif
+
 void MsanTSDInit(void (*destructor)(void *tsd)) {
   CHECK(!tsd_key_inited);
   tsd_key_inited = true;
+#if SANITIZER_NETBSD
+  INTERCEPT_FUNCTION(_lwp_exit);
+#else
   CHECK_EQ(0, pthread_key_create(&tsd_key, destructor));
+#endif
 }
 
 static THREADLOCAL MsanThread* msan_current_thread;
@@ -196,16 +212,20 @@ void SetCurrentThread(MsanThread *t) {
   msan_current_thread = t;
   // Make sure that MsanTSDDtor gets called at the end.
   CHECK(tsd_key_inited);
+#if !SANITIZER_NETBSD
   pthread_setspecific(tsd_key, (void *)t);
+#endif
 }
 
 void MsanTSDDtor(void *tsd) {
+#if !SANITIZER_NETBSD
   MsanThread *t = (MsanThread*)tsd;
   if (t->destructor_iterations_ > 1) {
     t->destructor_iterations_--;
     CHECK_EQ(0, pthread_setspecific(tsd_key, tsd));
     return;
   }
+#endif
   msan_current_thread = nullptr;
   // Make sure that signal handler can not see a stale current thread pointer.
   atomic_signal_fence(memory_order_seq_cst);
