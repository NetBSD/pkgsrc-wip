$NetBSD: patch-src_base_platform_platform-posix.cc,v 1.1 2014/08/23 17:44:12 heidnes Exp $

Use pthread_self() instead of non-portable SYS_gettid.
Provide a default for PTHREAD_STACK_MIN if it's missing (NetBSD...)

--- src/base/platform/platform-posix.cc.orig	2014-08-08 13:04:31.000000000 +0000
+++ src/base/platform/platform-posix.cc
@@ -324,7 +324,7 @@ int OS::GetCurrentThreadId() {
 #if defined(ANDROID)
   return static_cast<int>(syscall(__NR_gettid));
 #else
-  return static_cast<int>(syscall(SYS_gettid));
+  return static_cast<int>((intptr_t)pthread_self());
 #endif  // defined(ANDROID)
 }
 
@@ -511,6 +511,10 @@ class Thread::PlatformData {
   Mutex thread_creation_mutex_;
 };
 
+#ifndef PTHREAD_STACK_MIN
+#define PTHREAD_STACK_MIN 16384 /* Somewhat arbitrarily chosen */
+#endif
+
 Thread::Thread(const Options& options)
     : data_(new PlatformData),
       stack_size_(options.stack_size()),
@@ -532,7 +536,7 @@ static void SetThreadName(const char* na
   pthread_set_name_np(pthread_self(), name);
 #elif V8_OS_NETBSD
   STATIC_ASSERT(Thread::kMaxThreadNameLength <= PTHREAD_MAX_NAMELEN_NP);
-  pthread_setname_np(pthread_self(), "%s", name);
+  pthread_setname_np(pthread_self(), "%s", (void*)name);
 #elif V8_OS_MACOSX
   // pthread_setname_np is only available in 10.6 or later, so test
   // for it at runtime.
