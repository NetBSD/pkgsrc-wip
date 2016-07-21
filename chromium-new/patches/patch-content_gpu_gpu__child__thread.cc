$NetBSD$

--- content/gpu/gpu_child_thread.cc.orig	2016-06-24 01:02:21.000000000 +0000
+++ content/gpu/gpu_child_thread.cc
@@ -435,6 +435,7 @@ void GpuChildThread::StopWatchdog() {
 }
 
 void GpuChildThread::OnCollectGraphicsInfo() {
+#if !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 #if defined(OS_WIN)
   // GPU full info collection should only happen on un-sandboxed GPU process
   // or single process/in-process gpu mode on Windows.
@@ -477,6 +478,7 @@ void GpuChildThread::OnCollectGraphicsIn
     base::MessageLoop::current()->QuitWhenIdle();
   }
 #endif  // OS_WIN
+#endif  // XXX(rene) !FreeBSD
 }
 
 void GpuChildThread::OnGetVideoMemoryUsageStats() {
