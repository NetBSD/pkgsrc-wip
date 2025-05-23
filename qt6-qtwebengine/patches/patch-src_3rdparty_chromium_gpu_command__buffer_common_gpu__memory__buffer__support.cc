$NetBSD$

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/command_buffer/common/gpu_memory_buffer_support.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/gpu/command_buffer/common/gpu_memory_buffer_support.cc
@@ -182,7 +182,7 @@ uint32_t GetPlatformSpecificTextureTarge
 #if BUILDFLAG(IS_MAC)
   return macos_specific_texture_target;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return GL_TEXTURE_EXTERNAL_OES;
 #elif BUILDFLAG(IS_IOS)
   return GL_TEXTURE_2D;
@@ -217,7 +217,7 @@ GPU_EXPORT bool NativeBufferNeedsPlatfor
     gfx::BufferFormat format,
     gfx::BufferPlane plane) {
 #if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Always use GL_TEXTURE_2D as the target for RGB textures.
   // https://crbug.com/916728
   if (format == gfx::BufferFormat::R_8 || format == gfx::BufferFormat::RG_88 ||
