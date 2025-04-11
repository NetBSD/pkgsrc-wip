$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/webgpu_decoder_impl.cc.orig	2025-03-31 15:23:48.000000000 +0000
+++ gpu/command_buffer/service/webgpu_decoder_impl.cc
@@ -1752,7 +1752,7 @@ wgpu::Adapter WebGPUDecoderImpl::CreateP
       backend_types = {wgpu::BackendType::D3D12};
 #elif BUILDFLAG(IS_MAC)
       backend_types = {wgpu::BackendType::Metal};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (shared_context_state_->GrContextIsVulkan() ||
           shared_context_state_->IsGraphiteDawnVulkan()) {
         backend_types = {wgpu::BackendType::Vulkan};
@@ -1994,7 +1994,7 @@ WebGPUDecoderImpl::AssociateMailboxDawn(
   }
 
 #if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_APPLE) && \
-    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_LINUX)
+    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   if (usage & wgpu::TextureUsage::StorageBinding) {
     LOG(ERROR) << "AssociateMailbox: wgpu::TextureUsage::StorageBinding is NOT "
                   "supported yet on this platform.";
