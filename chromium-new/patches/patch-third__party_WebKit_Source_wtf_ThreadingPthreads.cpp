$NetBSD$

--- third_party/WebKit/Source/wtf/ThreadingPthreads.cpp.orig	2016-11-10 20:02:27.000000000 +0000
+++ third_party/WebKit/Source/wtf/ThreadingPthreads.cpp
@@ -49,11 +49,15 @@
 #include <objc/objc-auto.h>
 #endif
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(BSD)
 #include <sys/syscall.h>
 #endif
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(BSD) && !defined(__NetBSD__)
+#include <pthread_np.h>
+#endif
+
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
 #include <unistd.h>
 #endif
 
@@ -95,6 +99,8 @@ ThreadIdentifier currentThread()
     return pthread_mach_thread_np(pthread_self());
 #elif OS(LINUX)
     return syscall(__NR_gettid);
+#elif defined(__FreeBSD__)
+    return pthread_getthreadid_np();
 #elif OS(ANDROID)
     return gettid();
 #else
