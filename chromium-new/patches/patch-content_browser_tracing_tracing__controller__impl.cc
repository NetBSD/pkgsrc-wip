$NetBSD$

--- content/browser/tracing/tracing_controller_impl.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/tracing/tracing_controller_impl.cc
@@ -515,7 +515,7 @@ void TracingControllerImpl::AddTraceMess
     return;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux the browser process dumps process metrics for child process due to
   // sandbox.
   tracing::ProcessMetricsMemoryDumpProvider::RegisterForProcess(
