$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gpu/command_buffer/service/webgpu_decoder_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ gpu/command_buffer/service/webgpu_decoder_impl.cc
@@ -1341,7 +1341,7 @@ WGPUFuture WebGPUDecoderImpl::RequestAda
     force_fallback_adapter = true;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!shared_context_state_->GrContextIsVulkan() &&
       !shared_context_state_->IsGraphiteDawnVulkan() &&
       use_webgpu_adapter_ != WebGPUAdapterName::kOpenGLES) {
@@ -2026,7 +2026,7 @@ WebGPUDecoderImpl::AssociateMailboxDawn(
   }
 
 #if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_APPLE) && \
-    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_LINUX)
+    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   if (usage & wgpu::TextureUsage::StorageBinding) {
     LOG(ERROR) << "AssociateMailbox: wgpu::TextureUsage::StorageBinding is NOT "
                   "supported yet on this platform.";
