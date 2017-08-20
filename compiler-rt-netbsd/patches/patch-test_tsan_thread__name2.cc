$NetBSD$

--- test/tsan/thread_name2.cc.orig	2017-07-04 05:53:06.000000000 +0000
+++ test/tsan/thread_name2.cc
@@ -6,7 +6,11 @@
 
 #if defined(__FreeBSD__)
 #include <pthread_np.h>
-#define pthread_setname_np pthread_set_name_np
+#define tsan_pthread_setname_np pthread_set_name_np
+#elif defined(__NetBSD__)
+#define tsan_pthread_setname_np(a, b) pthread_setname_np((a), "%s", (void*)(b))
+#else
+#define tsan_pthread_setname_np pthread_setname_np
 #endif
 
 long long Global;
@@ -18,7 +22,7 @@ void *Thread1(void *x) {
 }
 
 void *Thread2(void *x) {
-  pthread_setname_np(pthread_self(), "foobar2");
+  tsan_pthread_setname_np(pthread_self(), "foobar2");
   Global--;
   barrier_wait(&barrier);
   return 0;
@@ -29,7 +33,7 @@ int main() {
   pthread_t t[2];
   pthread_create(&t[0], 0, Thread1, 0);
   pthread_create(&t[1], 0, Thread2, 0);
-  pthread_setname_np(t[0], "foobar1");
+  tsan_pthread_setname_np(t[0], "foobar1");
   barrier_wait(&barrier);
   pthread_join(t[0], NULL);
   pthread_join(t[1], NULL);
