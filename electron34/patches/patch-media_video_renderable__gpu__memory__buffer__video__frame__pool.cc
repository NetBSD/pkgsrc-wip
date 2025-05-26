$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/video/renderable_gpu_memory_buffer_video_frame_pool.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ media/video/renderable_gpu_memory_buffer_video_frame_pool.cc
@@ -193,7 +193,7 @@ gfx::Size GetBufferSizeInPixelsForVideoP
 bool FrameResources::Initialize() {
   auto* context = pool_->GetContext();
 
-  constexpr gfx::BufferUsage kBufferUsage =
+  gfx::BufferUsage buffer_usage =
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
       gfx::BufferUsage::SCANOUT_VEA_CPU_READ
 #else
@@ -207,6 +207,23 @@ bool FrameResources::Initialize() {
   const gfx::Size buffer_size_in_pixels =
       GetBufferSizeInPixelsForVideoPixelFormat(format_, coded_size_);
 
+#if BUILDFLAG(IS_WIN)
+  // For CEF OSR feature, currently there's no other place in chromium use RGBA.
+  // If the format is RGBA, currently CEF do not write to the texture anymore
+  // once the GMB is returned from CopyRequest. So there will be no race
+  // condition on that texture. We can request a GMB without a keyed mutex to
+  // accelerate and probably prevent some driver deadlock.
+  if (format_ == PIXEL_FORMAT_ARGB || format_ == PIXEL_FORMAT_ABGR) {
+    // This value is 'borrowed', SCANOUT_VEA_CPU_READ is probably invalid
+    // cause there's no real SCANOUT on Windows. We simply use this enum as a
+    // flag to disable mutex in the GMBFactoryDXGI because this enum is also
+    // used above in macOS and CrOS for similar usage (claim no other one will
+    // concurrently use the resource).
+    // https://chromium-review.googlesource.com/c/chromium/src/+/5302103
+    buffer_usage = gfx::BufferUsage::SCANOUT_VEA_CPU_READ;
+  }
+#endif
+
   constexpr gpu::SharedImageUsageSet kSharedImageUsage =
 #if BUILDFLAG(IS_MAC)
       gpu::SHARED_IMAGE_USAGE_MACOS_VIDEO_TOOLBOX |
@@ -231,7 +248,7 @@ bool FrameResources::Initialize() {
       viz::GetSharedImageFormat(buffer_format);
 
   shared_image_ = context->CreateSharedImage(
-      buffer_size_in_pixels, kBufferUsage, si_format, color_space_,
+      buffer_size_in_pixels, buffer_usage, si_format, color_space_,
       kTopLeft_GrSurfaceOrigin, kPremul_SkAlphaType, kSharedImageUsage,
       sync_token_);
   if (!shared_image_) {
