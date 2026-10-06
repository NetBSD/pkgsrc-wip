$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_process_host_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -220,7 +220,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
@@ -1082,7 +1082,7 @@ static constexpr size_t kUnknownPlatform
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1259,7 +1259,7 @@ RenderProcessHostImpl::IOThreadHostImpl:
 
 void RenderProcessHostImpl::IOThreadHostImpl::SetPid(
     base::ProcessId child_pid) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(child_pid);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
@@ -1754,6 +1754,10 @@ bool RenderProcessHostImpl::Init() {
     std::unique_ptr<SandboxedProcessLauncherDelegate> sandbox_delegate =
         std::make_unique<RendererSandboxedProcessLauncherDelegateWin>(
             *cmd_line, IsPdf(), IsJitDisabled());
+#elif BUILDFLAG(USE_ZYGOTE)
+    bool use_zygote = !cmd_line->HasSwitch(switches::kNoZygote);
+    std::unique_ptr<SandboxedProcessLauncherDelegate> sandbox_delegate =
+        std::make_unique<RendererSandboxedProcessLauncherDelegate>(use_zygote);
 #else
     std::unique_ptr<SandboxedProcessLauncherDelegate> sandbox_delegate =
         std::make_unique<RendererSandboxedProcessLauncherDelegate>();
@@ -2106,7 +2110,7 @@ void RenderProcessHostImpl::CreateNotifi
     case RenderProcessHost::NotificationServiceCreatorType::kSharedWorker:
     case RenderProcessHost::NotificationServiceCreatorType::kDedicatedWorker: {
       storage_partition_impl_->GetPlatformNotificationContext()->CreateService(
-          this, storage_key, /*document_url=*/GURL(), weak_document_ptr,
+          this, rfh, storage_key, /*document_url=*/GURL(), weak_document_ptr,
           creator_type, std::move(receiver));
       break;
     }
@@ -2114,7 +2118,7 @@ void RenderProcessHostImpl::CreateNotifi
       CHECK(rfh);
 
       storage_partition_impl_->GetPlatformNotificationContext()->CreateService(
-          this, storage_key, rfh->GetLastCommittedURL(), weak_document_ptr,
+          this, rfh, storage_key, rfh->GetLastCommittedURL(), weak_document_ptr,
           creator_type, std::move(receiver));
       break;
     }
@@ -3261,7 +3265,7 @@ void RenderProcessHostImpl::AppendRender
             base::TimeTicks::UnixEpoch().since_origin().InMicroseconds()));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Append `kDisableVideoCaptureUseGpuMemoryBuffer` flag if there is no support
   // for NV12 GPU memory buffer.
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled() &&
@@ -3318,6 +3322,7 @@ void RenderProcessHostImpl::PropagateBro
       switches::kDisableSpeechAPI,
       switches::kDisableThreadedCompositing,
       switches::kDisableTouchDragDrop,
+      switches::kDisableUnveil,
       switches::kDisableV8IdleTasks,
       switches::kDisableVideoCaptureUseGpuMemoryBuffer,
       switches::kDisableWebGLImageChromium,
@@ -5107,7 +5112,7 @@ uint64_t RenderProcessHostImpl::GetPriva
   // - Win: https://crbug.com/707022 .
   uint64_t total_size = 0;
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   total_size = dump->platform_private_footprint->rss_anon_bytes +
                dump->platform_private_footprint->vm_swap_bytes;
 #elif BUILDFLAG(IS_APPLE)
