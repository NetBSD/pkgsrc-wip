$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/common/gpu_memory_buffer_support.cc.orig	2024-08-06 19:52:27.206131000 +0000
+++ gpu/command_buffer/common/gpu_memory_buffer_support.cc
@@ -182,7 +182,7 @@ uint32_t GetPlatformSpecificTextureTarge
 #if BUILDFLAG(IS_MAC)
   return macos_specific_texture_target;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return GL_TEXTURE_EXTERNAL_OES;
 #elif BUILDFLAG(IS_IOS)
   return GL_TEXTURE_2D;
@@ -209,7 +209,7 @@ GPU_EXPORT bool NativeBufferNeedsPlatfor
     gfx::BufferFormat format,
     gfx::BufferPlane plane) {
 #if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Always use GL_TEXTURE_2D as the target for RGB textures.
   // https://crbug.com/916728
   if (format == gfx::BufferFormat::R_8 || format == gfx::BufferFormat::RG_88 ||
