$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/external_vk_image_backing.cc.orig	2024-08-06 19:52:27.270136400 +0000
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing.cc
@@ -51,7 +51,7 @@
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/scoped_binders.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/shared_image/external_vk_image_dawn_representation.h"
 #if BUILDFLAG(DAWN_ENABLE_BACKEND_OPENGLES)
 #include "gpu/command_buffer/service/shared_image/dawn_gl_texture_representation.h"
@@ -696,7 +696,7 @@ std::unique_ptr<DawnImageRepresentation>
     wgpu::BackendType backend_type,
     std::vector<wgpu::TextureFormat> view_formats,
     scoped_refptr<SharedContextState> context_state) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
   auto wgpu_format = ToDawnFormat(format());
 
   if (wgpu_format == wgpu::TextureFormat::Undefined) {
