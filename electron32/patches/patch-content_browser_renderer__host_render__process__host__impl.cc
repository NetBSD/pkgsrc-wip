$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_process_host_impl.cc.orig	2024-10-18 12:34:13.578814700 +0000
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -218,7 +218,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
@@ -948,7 +948,7 @@ static constexpr size_t kUnknownPlatform
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1121,7 +1121,7 @@ RenderProcessHostImpl::IOThreadHostImpl:
 
 void RenderProcessHostImpl::IOThreadHostImpl::SetPid(
     base::ProcessId child_pid) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(child_pid);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
@@ -1613,9 +1613,15 @@ bool RenderProcessHostImpl::Init() {
         std::make_unique<RendererSandboxedProcessLauncherDelegateWin>(
             *cmd_line, IsPdf(), /*is_jit_disabled=*/IsPdf());
 #else
+#if BUILDFLAG(USE_ZYGOTE)
+    bool use_zygote = !cmd_line->HasSwitch(switches::kNoZygote);
+    std::unique_ptr<SandboxedProcessLauncherDelegate> sandbox_delegate =
+        std::make_unique<RendererSandboxedProcessLauncherDelegate>(use_zygote);
+#else
     std::unique_ptr<SandboxedProcessLauncherDelegate> sandbox_delegate =
         std::make_unique<RendererSandboxedProcessLauncherDelegate>();
 #endif
+#endif
 
     auto tracing_config_memory_region =
         tracing::CreateTracingConfigSharedMemory();
@@ -1978,7 +1984,7 @@ void RenderProcessHostImpl::CreateNotifi
     case RenderProcessHost::NotificationServiceCreatorType::kSharedWorker:
     case RenderProcessHost::NotificationServiceCreatorType::kDedicatedWorker: {
       storage_partition_impl_->GetPlatformNotificationContext()->CreateService(
-          this, storage_key, /*document_url=*/GURL(), weak_document_ptr,
+          this, rfh, storage_key, /*document_url=*/GURL(), weak_document_ptr,
           creator_type, std::move(receiver));
       break;
     }
@@ -1986,7 +1992,7 @@ void RenderProcessHostImpl::CreateNotifi
       CHECK(rfh);
 
       storage_partition_impl_->GetPlatformNotificationContext()->CreateService(
-          this, storage_key, rfh->GetLastCommittedURL(), weak_document_ptr,
+          this, rfh, storage_key, rfh->GetLastCommittedURL(), weak_document_ptr,
           creator_type, std::move(receiver));
       break;
     }
@@ -3131,7 +3137,7 @@ void RenderProcessHostImpl::AppendRender
             base::TimeTicks::UnixEpoch().since_origin().InMicroseconds()));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Append `kDisableVideoCaptureUseGpuMemoryBuffer` flag if there is no support
   // for NV12 GPU memory buffer.
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled() &&
@@ -3188,6 +3194,7 @@ void RenderProcessHostImpl::PropagateBro
     switches::kDisableSpeechAPI,
     switches::kDisableThreadedCompositing,
     switches::kDisableTouchDragDrop,
+    switches::kDisableUnveil,
     switches::kDisableV8IdleTasks,
     switches::kDisableVideoCaptureUseGpuMemoryBuffer,
     switches::kDisableWebGLImageChromium,
