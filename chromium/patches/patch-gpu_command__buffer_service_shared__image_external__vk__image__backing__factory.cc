$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2024-07-24 02:44:39.209030600 +0000
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -147,7 +147,7 @@ bool IsFormatSupported(viz::SharedImageF
 }  // namespace
 
 constexpr uint32_t kSupportedUsage =
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
     SHARED_IMAGE_USAGE_WEBGPU_READ | SHARED_IMAGE_USAGE_WEBGPU_WRITE |
     SHARED_IMAGE_USAGE_WEBGPU_SWAP_CHAIN_TEXTURE |
     SHARED_IMAGE_USAGE_WEBGPU_STORAGE_TEXTURE |
