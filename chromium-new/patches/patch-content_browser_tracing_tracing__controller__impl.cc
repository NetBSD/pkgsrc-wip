$NetBSD$

--- content/browser/tracing/tracing_controller_impl.cc.orig	2017-02-02 02:02:53.000000000 +0000
+++ content/browser/tracing/tracing_controller_impl.cc
@@ -475,7 +475,7 @@ void TracingControllerImpl::AddTraceMess
     return;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux the browser process dumps process metrics for child process due to
   // sandbox.
   tracing::ProcessMetricsMemoryDumpProvider::RegisterForProcess(
