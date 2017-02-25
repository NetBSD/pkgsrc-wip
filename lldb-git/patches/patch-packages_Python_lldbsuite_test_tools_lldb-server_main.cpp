$NetBSD$

--- packages/Python/lldbsuite/test/tools/lldb-server/main.cpp.orig	2017-02-25 06:05:33.924756574 +0000
+++ packages/Python/lldbsuite/test/tools/lldb-server/main.cpp
@@ -27,6 +27,8 @@ __OSX_AVAILABLE_STARTING(__MAC_10_6, __I
 int pthread_threadid_np(pthread_t, __uint64_t *);
 #elif defined(__linux__)
 #include <sys/syscall.h>
+#elif defined(__NetBSD__)
+#include <lwp.h>
 #endif
 
 static const char *const RETVAL_PREFIX = "retval:";
@@ -71,6 +73,9 @@ static void print_thread_id() {
 #elif defined(__linux__)
   // This is a call to gettid() via syscall.
   printf("%" PRIx64, static_cast<uint64_t>(syscall(__NR_gettid)));
+#elif defined(__NetBSD__)
+  // Technically lwpid_t is 32-bit signed integer
+  printf("%" PRIx64, static_cast<uint64_t>(_lwp_self()));
 #else
   printf("{no-tid-support}");
 #endif
