$NetBSD$

--- lib/msan/msan_linux.cc.orig	2018-08-21 21:25:44.000000000 +0000
+++ lib/msan/msan_linux.cc
@@ -34,6 +34,11 @@
 #include "sanitizer_common/sanitizer_common.h"
 #include "sanitizer_common/sanitizer_procmaps.h"
 
+#if SANITIZER_NETBSD
+extern "C" int __cxa_thread_atexit(void (*)(void *), void *,
+                                   void *) SANITIZER_WEAK_ATTRIBUTE;
+#endif
+
 namespace __msan {
 
 void ReportMapRange(const char *descr, uptr beg, uptr size) {
@@ -175,19 +180,59 @@ void InstallAtExitHandler() {
 
 // ---------------------- TSD ---------------- {{{1
 
-static pthread_key_t tsd_key;
+static THREADLOCAL MsanThread *msan_current_thread;
+
+MsanThread *GetCurrentThread() { return msan_current_thread; }
+
+#if SANITIZER_NETBSD
+// Thread Static Data cannot be used in early init on NetBSD
+// Reuse the Asan TSD API for compatibility with existing code
+// with an alternative implementation.
+
 static bool tsd_key_inited = false;
+static void (*tsd_destructor)(void *tsd) = nullptr;
+
+void tsd_at_exit(void *tsd) {
+  CHECK_EQ(tsd, (void *)msan_current_thread);
+  CHECK(tsd);
+  (*tsd_destructor)(tsd);
+}
 
 void MsanTSDInit(void (*destructor)(void *tsd)) {
   CHECK(!tsd_key_inited);
   tsd_key_inited = true;
-  CHECK_EQ(0, pthread_key_create(&tsd_key, destructor));
+  tsd_destructor = destructor;
 }
 
-static THREADLOCAL MsanThread* msan_current_thread;
+void SetCurrentThread(MsanThread *t) {
+  CHECK(tsd_key_inited);
+  // Make sure we do not reset the current MsanThread.
+  CHECK_EQ(0, msan_current_thread);
+  msan_current_thread = t;
+  // Make sure that MsanTSDDtor gets called at the end.
+  CHECK(tsd_key_inited);
+  if (::__cxa_thread_atexit(tsd_at_exit, t, nullptr)) {
+    Printf("MemorySanitizer: failed to setup thread atexit callback");
+    Die();
+  }
+}
 
-MsanThread *GetCurrentThread() {
-  return msan_current_thread;
+void MsanTSDDtor(void *tsd) {
+  CHECK(tsd_key_inited);
+  CHECK_EQ(tsd, (void *)msan_current_thread);
+  msan_current_thread = nullptr;
+  // Make sure that signal handler can not see a stale current thread pointer.
+  atomic_signal_fence(memory_order_seq_cst);
+  MsanThread::TSDDtor(tsd);
+}
+#else
+static pthread_key_t tsd_key;
+static bool tsd_key_inited = false;
+
+void MsanTSDInit(void (*destructor)(void *tsd)) {
+  CHECK(!tsd_key_inited);
+  tsd_key_inited = true;
+  CHECK_EQ(0, pthread_key_create(&tsd_key, destructor));
 }
 
 void SetCurrentThread(MsanThread *t) {
@@ -211,6 +256,7 @@ void MsanTSDDtor(void *tsd) {
   atomic_signal_fence(memory_order_seq_cst);
   MsanThread::TSDDtor(tsd);
 }
+#endif
 
 } // namespace __msan
 
