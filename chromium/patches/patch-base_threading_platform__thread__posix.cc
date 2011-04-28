$NetBSD: patch-base_threading_platform__thread__posix.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/threading/platform_thread_posix.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/threading/platform_thread_posix.cc
@@ -124,7 +124,7 @@ PlatformThreadId PlatformThread::Current
   return mach_thread_self();
 #elif defined(OS_LINUX)
   return syscall(__NR_gettid);
-#elif defined(OS_FREEBSD)
+#elif defined(OS_BSD)
   // TODO(BSD): find a better thread ID
   return reinterpret_cast<int64>(pthread_self());
 #elif defined(OS_NACL)
