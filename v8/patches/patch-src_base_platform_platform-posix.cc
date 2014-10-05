$NetBSD: patch-src_base_platform_platform-posix.cc,v 1.2 2014/10/05 11:12:29 heidnes Exp $

Use pthread_self() instead of non-portable SYS_gettid.
Provide a default for PTHREAD_STACK_MIN if it's missing (NetBSD...)
Also force IEEE 754 version of libm.

--- src/base/platform/platform-posix.cc.orig	2014-08-21 07:04:57.000000000 +0000
+++ src/base/platform/platform-posix.cc
@@ -210,6 +210,9 @@ void OS::Initialize(int64_t random_seed,
   }
   g_hard_abort = hard_abort;
   g_gc_fake_mmap = gc_fake_mmap;
+#ifdef __NetBSD__
+  _LIB_VERSION = _IEEE_;	/* Force IEEE 754 version of libm */
+#endif
 }
 
 
@@ -324,7 +327,7 @@ int OS::GetCurrentThreadId() {
 #if defined(ANDROID)
   return static_cast<int>(syscall(__NR_gettid));
 #else
-  return static_cast<int>(syscall(SYS_gettid));
+  return static_cast<int>((intptr_t)pthread_self());
 #endif  // defined(ANDROID)
 }
 
@@ -511,6 +514,10 @@ class Thread::PlatformData {
   Mutex thread_creation_mutex_;
 };
 
+#ifndef PTHREAD_STACK_MIN
+#define PTHREAD_STACK_MIN 16384 /* Somewhat arbitrarily chosen */
+#endif
+
 Thread::Thread(const Options& options)
     : data_(new PlatformData),
       stack_size_(options.stack_size()),
@@ -532,7 +539,7 @@ static void SetThreadName(const char* na
   pthread_set_name_np(pthread_self(), name);
 #elif V8_OS_NETBSD
   STATIC_ASSERT(Thread::kMaxThreadNameLength <= PTHREAD_MAX_NAMELEN_NP);
-  pthread_setname_np(pthread_self(), "%s", name);
+  pthread_setname_np(pthread_self(), "%s", (void*)name);
 #elif V8_OS_MACOSX
   // pthread_setname_np is only available in 10.6 or later, so test
   // for it at runtime.
