$NetBSD: patch-base_logging.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/logging.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/logging.cc
@@ -133,7 +133,7 @@ int32 CurrentThreadId() {
   return mach_thread_self();
 #elif defined(OS_LINUX)
   return syscall(__NR_gettid);
-#elif defined(OS_FREEBSD)
+#elif defined(OS_BSD)
   // TODO(BSD): find a better thread ID
   return reinterpret_cast<int64>(pthread_self());
 #elif defined(OS_NACL)
