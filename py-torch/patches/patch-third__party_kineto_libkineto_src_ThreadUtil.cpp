$NetBSD$

--- third_party/kineto/libkineto/src/ThreadUtil.cpp.orig	2022-07-22 04:49:10.227928374 +0000
+++ third_party/kineto/libkineto/src/ThreadUtil.cpp
@@ -1,5 +1,8 @@
 #include "ThreadUtil.h"
 
+#ifdef __NetBSD__
+#include <lwp.h>
+#endif
 #ifndef _MSC_VER
 #include <pthread.h>
 #include <unistd.h>
@@ -48,6 +51,8 @@ int32_t systemThreadId() {
     _sysTid = (int32_t)syscall(SYS_thread_selfid);
 #elif defined _MSC_VER
     _sysTid = (int32_t)GetCurrentThreadId();
+#elif defined __NetBSD__
+    _sysTid = (int32_t) _lwp_self();
 #else
     _sysTid = (int32_t)syscall(SYS_gettid);
 #endif
@@ -101,6 +106,8 @@ bool setThreadName(const std::string& na
   std::wstring wname = conv.from_bytes(name);
   HRESULT hr = _SetThreadDescription(GetCurrentThread(), wname.c_str());
   return SUCCEEDED(hr);
+#elif defined __NetBSD__
+  return 0 == pthread_setname_np(pthread_self(), name.c_str(), (void*) "%s");
 #else
   return 0 == pthread_setname_np(pthread_self(), name.c_str());
 #endif
