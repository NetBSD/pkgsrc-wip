$NetBSD$

--- lib/asan/asan_posix.cc.orig	2018-08-21 21:25:41.000000000 +0000
+++ lib/asan/asan_posix.cc
@@ -30,6 +30,11 @@
 #include <sys/resource.h>
 #include <unistd.h>
 
+#if SANITIZER_NETBSD
+extern "C" int __cxa_thread_atexit(void (*)(void *), void *,
+                                   void *) SANITIZER_WEAK_ATTRIBUTE;
+#endif
+
 namespace __asan {
 
 void AsanOnDeadlySignal(int signo, void *siginfo, void *context) {
@@ -40,6 +45,51 @@ void AsanOnDeadlySignal(int signo, void 
 
 // ---------------------- TSD ---------------- {{{1
 
+#if SANITIZER_NETBSD
+// Thread Static Data cannot be used in early init on NetBSD
+// Reuse the Asan TSD API for compatibility with existing code
+// with an alternative implementation.
+
+static bool tsd_key_inited = false;
+static void (*tsd_destructor)(void *tsd) = nullptr;
+static THREADLOCAL void *tsd_key = nullptr;
+
+void tsd_at_exit(void *tsd) {
+  CHECK_EQ(tsd, tsd_key);
+  CHECK(tsd_key);
+  (*tsd_destructor)(tsd_key);
+}
+
+void AsanTSDInit(void (*destructor)(void *tsd)) {
+  CHECK(!tsd_key_inited);
+  tsd_key_inited = true;
+  tsd_destructor = destructor;
+}
+
+void *AsanTSDGet() {
+  CHECK(tsd_key_inited);
+  return tsd_key;
+}
+
+void AsanTSDSet(void *tsd) {
+  CHECK(tsd_key_inited);
+  CHECK(tsd);
+  CHECK(!tsd_key);
+  tsd_key = tsd;
+  if (::__cxa_thread_atexit(tsd_at_exit, tsd, nullptr)) {
+    Printf("AddressSanitizer: failed to setup thread atexit callback");
+    Die();
+  }
+}
+
+void PlatformTSDDtor(void *tsd) {
+  CHECK(tsd_key_inited);
+  tsd_key = nullptr;
+  // Make sure that signal handler can not see a stale current thread pointer.
+  atomic_signal_fence(memory_order_seq_cst);
+  AsanThread::TSDDtor(tsd);
+}
+#else
 static pthread_key_t tsd_key;
 static bool tsd_key_inited = false;
 void AsanTSDInit(void (*destructor)(void *tsd)) {
@@ -67,6 +117,7 @@ void PlatformTSDDtor(void *tsd) {
   }
   AsanThread::TSDDtor(tsd);
 }
+#endif
 }  // namespace __asan
 
 #endif  // SANITIZER_POSIX
