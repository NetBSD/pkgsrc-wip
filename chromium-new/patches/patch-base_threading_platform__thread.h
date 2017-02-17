$NetBSD$

--- base/threading/platform_thread.h.orig	2017-02-02 02:02:47.000000000 +0000
+++ base/threading/platform_thread.h
@@ -205,7 +205,7 @@ class BASE_EXPORT PlatformThread {
 
   static ThreadPriority GetCurrentThreadPriority();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Toggles a specific thread's priority at runtime. This can be used to
   // change the priority of a thread in a different process and will fail
   // if the calling process does not have proper permissions. The
