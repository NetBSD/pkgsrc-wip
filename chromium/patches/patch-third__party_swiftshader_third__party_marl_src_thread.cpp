$NetBSD$

--- third_party/swiftshader/third_party/marl/src/thread.cpp.orig	2020-07-15 19:01:48.000000000 +0000
+++ third_party/swiftshader/third_party/marl/src/thread.cpp
@@ -420,6 +420,8 @@ void Thread::setName(const char* fmt, ..
   pthread_setname_np(name);
 #elif defined(__FreeBSD__)
   pthread_set_name_np(pthread_self(), name);
+#elif defined(__NetBSD__)
+  pthread_setname_np(pthread_self(), "%s", name);
 #elif !defined(__Fuchsia__)
   pthread_setname_np(pthread_self(), name);
 #endif
