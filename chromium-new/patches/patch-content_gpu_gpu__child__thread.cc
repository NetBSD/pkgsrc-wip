$NetBSD$

--- content/gpu/gpu_child_thread.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/gpu/gpu_child_thread.cc
@@ -419,6 +419,7 @@ void GpuChildThread::OnCollectGraphicsIn
   if (dead_on_arrival_)
     return;
 
+#if !defined(OS_BSD)
 #if defined(OS_WIN)
   // GPU full info collection should only happen on un-sandboxed GPU process
   // or single process/in-process gpu mode on Windows.
@@ -461,6 +462,7 @@ void GpuChildThread::OnCollectGraphicsIn
     base::MessageLoop::current()->QuitWhenIdle();
   }
 #endif  // OS_WIN
+#endif  // XXX(rene) !FreeBSD
 }
 
 void GpuChildThread::OnGetVideoMemoryUsageStats() {
