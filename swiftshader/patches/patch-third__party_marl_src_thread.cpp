$NetBSD$

* Import patch from chromium

--- third_party/marl/src/thread.cpp.orig	2025-11-19 17:20:56.859996246 +0000
+++ third_party/marl/src/thread.cpp
@@ -45,6 +45,9 @@
 #include <pthread.h>
 #include <unistd.h>
 #include <thread>
+#if defined(__NetBSD__)
+#include <stdarg.h>
+#endif
 #endif
 
 namespace {
@@ -444,6 +447,8 @@ void Thread::setName(const char* fmt, ..
   pthread_setname_np(name);
 #elif defined(__FreeBSD__)
   pthread_set_name_np(pthread_self(), name);
+#elif defined(__NetBSD__)
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif !defined(__Fuchsia__) && !defined(__EMSCRIPTEN__)
   pthread_setname_np(pthread_self(), name);
 #endif
