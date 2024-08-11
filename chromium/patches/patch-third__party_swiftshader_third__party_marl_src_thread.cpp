$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/swiftshader/third_party/marl/src/thread.cpp.orig	2024-07-24 02:45:44.719376000 +0000
+++ third_party/swiftshader/third_party/marl/src/thread.cpp
@@ -46,6 +46,9 @@
 #include <unistd.h>
 #include <thread>
 #endif
+#if defined(__NetBSD__)
+#include <stdarg.h>
+#endif
 
 namespace {
 
@@ -444,7 +447,9 @@ void Thread::setName(const char* fmt, ..
   pthread_setname_np(name);
 #elif defined(__FreeBSD__)
   pthread_set_name_np(pthread_self(), name);
-#elif !defined(__Fuchsia__) && !defined(__EMSCRIPTEN__)
+#elif defined(__NetBSD__)
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
+#elif !defined(__Fuchsia__) && !defined(__EMSCRIPTEN__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
   pthread_setname_np(pthread_self(), name);
 #endif
 
