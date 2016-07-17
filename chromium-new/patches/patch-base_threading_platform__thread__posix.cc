$NetBSD$

--- base/threading/platform_thread_posix.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/threading/platform_thread_posix.cc
@@ -55,7 +55,7 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::ThreadRestrictions::SetSingletonAllowed(false);
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
     // Threads on linux/android may inherit their priority from the thread
     // where they were created. This explicitly sets the priority of all new
     // threads.
