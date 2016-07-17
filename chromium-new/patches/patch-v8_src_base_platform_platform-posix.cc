$NetBSD$

--- v8/src/base/platform/platform-posix.cc.orig	2016-06-24 01:04:22.000000000 +0000
+++ v8/src/base/platform/platform-posix.cc
@@ -55,6 +55,14 @@
 #include <sys/prctl.h>  // NOLINT, for prctl
 #endif
 
+#if V8_OS_FREEBSD && !defined(__DragonFly__)
+#include <sys/thr.h>   // for thr_self
+#endif
+
+#if V8_OS_NETBSD
+#include <lwp.h>       // for _lwp_self
+#endif
+
 #if !defined(V8_OS_NACL) && !defined(_AIX)
 #include <sys/syscall.h>
 #endif
@@ -343,6 +351,12 @@ int OS::GetCurrentThreadId() {
   return static_cast<int>(syscall(__NR_gettid));
 #elif V8_OS_ANDROID
   return static_cast<int>(gettid());
+#elif V8_OS_DRAGONFLYBSD || defined(__DragonFly__)
+  return static_cast<int>(lwp_gettid());
+#elif V8_OS_FREEBSD
+  return static_cast<int>(pthread_getthreadid_np());
+#elif V8_OS_NETBSD
+  return static_cast<int>(_lwp_self());
 #elif V8_OS_AIX
   return static_cast<int>(thread_self());
 #elif V8_OS_SOLARIS
@@ -550,8 +564,13 @@ Thread::Thread(const Options& options)
     : data_(new PlatformData),
       stack_size_(options.stack_size()),
       start_semaphore_(NULL) {
+#if defined(__NetBSD__)
+  if (stack_size_ > 0 && static_cast<size_t>(stack_size_) < sysconf(_SC_THREAD_STACK_MIN)) {
+    stack_size_ = sysconf(_SC_THREAD_STACK_MIN);
+#else
   if (stack_size_ > 0 && static_cast<size_t>(stack_size_) < PTHREAD_STACK_MIN) {
     stack_size_ = PTHREAD_STACK_MIN;
+#endif
   }
   set_name(options.name());
 }
@@ -567,7 +586,7 @@ static void SetThreadName(const char* na
   pthread_set_name_np(pthread_self(), name);
 #elif V8_OS_NETBSD
   STATIC_ASSERT(Thread::kMaxThreadNameLength <= PTHREAD_MAX_NAMELEN_NP);
-  pthread_setname_np(pthread_self(), "%s", name);
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif V8_OS_MACOSX
   // pthread_setname_np is only available in 10.6 or later, so test
   // for it at runtime.
