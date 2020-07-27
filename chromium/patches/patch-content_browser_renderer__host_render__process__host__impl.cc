$NetBSD$

--- content/browser/renderer_host/render_process_host_impl.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -240,7 +240,7 @@
 #include "content/browser/gpu/gpu_data_manager_impl.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/resource.h>
 #include <sys/time.h>
 
@@ -1224,7 +1224,7 @@ static constexpr size_t kUnknownPlatform
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1329,7 +1329,7 @@ class RenderProcessHostImpl::IOThreadHos
         return;
     }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
       ConnectToFontService(std::move(font_receiver));
       return;
@@ -1763,7 +1763,7 @@ bool RenderProcessHostImpl::Init() {
   renderer_prefix =
       browser_command_line.GetSwitchValueNative(switches::kRendererCmdPrefix);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int flags = renderer_prefix.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                       : ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MACOSX)
@@ -3269,7 +3269,7 @@ void RenderProcessHostImpl::PropagateBro
     service_manager::switches::kDisableInProcessStackTraces,
     service_manager::switches::kDisableSeccompFilterSandbox,
     service_manager::switches::kNoSandbox,
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     switches::kDisableDevShmUsage,
 #endif
 #if defined(OS_MACOSX)
@@ -3681,7 +3681,7 @@ void RenderProcessHostImpl::OnChannelCon
     for (auto& observer : observers_)
       observer.RenderProcessReady(this);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Provide /proc/{renderer pid}/status and statm files for
     // MemoryUsageMonitor in blink.
     ProvideStatusFileForRenderer();
@@ -4983,7 +4983,7 @@ void RenderProcessHostImpl::OnProcessLau
     for (auto& observer : observers_)
       observer.RenderProcessReady(this);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Provide /proc/{renderer pid}/status and statm files for
     // MemoryUsageMonitor in blink.
     ProvideStatusFileForRenderer();
@@ -5153,7 +5153,7 @@ void RenderProcessHost::InterceptBindHos
   GetBindHostReceiverInterceptor() = std::move(callback);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void RenderProcessHostImpl::ProvideStatusFileForRenderer() {
   // We use ScopedAllowBlocking, because opening /proc/{pid}/status and
   // /proc/{pid}/statm is not blocking call.
