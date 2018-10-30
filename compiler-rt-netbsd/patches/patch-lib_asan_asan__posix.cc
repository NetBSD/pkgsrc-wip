$NetBSD$

--- lib/asan/asan_posix.cc.orig	2018-08-21 21:25:41.000000000 +0000
+++ lib/asan/asan_posix.cc
@@ -40,31 +40,35 @@ void AsanOnDeadlySignal(int signo, void 
 
 // ---------------------- TSD ---------------- {{{1
 
-static pthread_key_t tsd_key;
+struct TsdKey {
+  void *data;
+  void (*dst)(void *value);
+  TsdKey() : data(nullptr), dst(nullptr) {}
+  ~TsdKey() {
+    if (dst)
+      dst(data);
+  }
+};
+
+static thread_local TsdKey Tk;
 static bool tsd_key_inited = false;
 void AsanTSDInit(void (*destructor)(void *tsd)) {
   CHECK(!tsd_key_inited);
   tsd_key_inited = true;
-  CHECK_EQ(0, pthread_key_create(&tsd_key, destructor));
+  Tk.dst = destructor;
 }
 
 void *AsanTSDGet() {
   CHECK(tsd_key_inited);
-  return pthread_getspecific(tsd_key);
+  return Tk.data;
 }
 
 void AsanTSDSet(void *tsd) {
   CHECK(tsd_key_inited);
-  pthread_setspecific(tsd_key, tsd);
+  Tk.data = tsd;
 }
 
 void PlatformTSDDtor(void *tsd) {
-  AsanThreadContext *context = (AsanThreadContext*)tsd;
-  if (context->destructor_iterations > 1) {
-    context->destructor_iterations--;
-    CHECK_EQ(0, pthread_setspecific(tsd_key, tsd));
-    return;
-  }
   AsanThread::TSDDtor(tsd);
 }
 }  // namespace __asan
