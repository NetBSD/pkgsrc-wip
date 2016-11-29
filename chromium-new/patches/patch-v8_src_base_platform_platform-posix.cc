$NetBSD$

--- v8/src/base/platform/platform-posix.cc.orig	2016-11-10 20:03:08.000000000 +0000
+++ v8/src/base/platform/platform-posix.cc
@@ -27,6 +27,10 @@
 #include <sys/sysctl.h>  // NOLINT, for sysctl
 #endif
 
+#if defined(__NetBSD__)
+#include <lwp.h>	// for _lwp_self
+#endif
+
 #undef MAP_TYPE
 
 #if defined(ANDROID) && !defined(V8_ANDROID_LOG_STDOUT)
@@ -329,6 +333,12 @@ int OS::GetCurrentThreadId() {
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
@@ -532,8 +542,13 @@ Thread::Thread(const Options& options)
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
@@ -549,7 +564,7 @@ static void SetThreadName(const char* na
   pthread_set_name_np(pthread_self(), name);
 #elif V8_OS_NETBSD
   STATIC_ASSERT(Thread::kMaxThreadNameLength <= PTHREAD_MAX_NAMELEN_NP);
-  pthread_setname_np(pthread_self(), "%s", name);
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif V8_OS_MACOSX
   // pthread_setname_np is only available in 10.6 or later, so test
   // for it at runtime.
