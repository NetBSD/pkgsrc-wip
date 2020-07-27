$NetBSD$

--- base/threading/platform_thread_posix.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ base/threading/platform_thread_posix.cc
@@ -66,7 +66,7 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::ThreadRestrictions::SetSingletonAllowed(false);
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
     // Threads on linux/android may inherit their priority from the thread
     // where they were created. This explicitly sets the priority of all new
     // threads.
