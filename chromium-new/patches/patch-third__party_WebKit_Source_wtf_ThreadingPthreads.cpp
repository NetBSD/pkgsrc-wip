$NetBSD$

--- third_party/WebKit/Source/wtf/ThreadingPthreads.cpp.orig	2017-02-02 02:03:10.000000000 +0000
+++ third_party/WebKit/Source/wtf/ThreadingPthreads.cpp
@@ -49,11 +49,15 @@
 #include <objc/objc-auto.h>
 #endif
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(BSD)
 #include <sys/syscall.h>
 #endif
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(FREEBSD)
+#include <pthread_np.h>
+#endif
+
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
 #include <unistd.h>
 #endif
 
@@ -91,6 +95,8 @@ ThreadIdentifier currentThread() {
   return pthread_mach_thread_np(pthread_self());
 #elif OS(LINUX)
   return syscall(__NR_gettid);
+#elif OS(FREEBSD)
+  return pthread_getthreadid_np();
 #elif OS(ANDROID)
   return gettid();
 #else
