$NetBSD$

--- test/tsan/thread_name.cc.orig	2017-07-04 05:53:07.000000000 +0000
+++ test/tsan/thread_name.cc
@@ -3,10 +3,14 @@
 
 #if defined(__linux__)
 #define USE_PTHREAD_SETNAME_NP __GLIBC_PREREQ(2, 12)
+#define tsan_pthread_setname_np pthread_setname_np
 #elif defined(__FreeBSD__)
 #include <pthread_np.h>
 #define USE_PTHREAD_SETNAME_NP 1
-#define pthread_setname_np pthread_set_name_np
+#define tasn_pthread_setname_np pthread_set_name_np
+#elif defined(__NetBSD__)
+#define USE_PTHREAD_SETNAME_NP 1
+#define tsan_pthread_setname_np(a,b) pthread_setname_np((a),"%s",(void*)(b))
 #else
 #define USE_PTHREAD_SETNAME_NP 0
 #endif
@@ -24,7 +28,7 @@ void *Thread1(void *x) {
 
 void *Thread2(void *x) {
 #if USE_PTHREAD_SETNAME_NP
-  pthread_setname_np(pthread_self(), "Thread2");
+  tsan_pthread_setname_np(pthread_self(), "Thread2");
 #else
   AnnotateThreadName(__FILE__, __LINE__, "Thread2");
 #endif
