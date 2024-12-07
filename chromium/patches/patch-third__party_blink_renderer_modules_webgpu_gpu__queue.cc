$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/webgpu/gpu_queue.cc.orig	2024-12-03 23:30:28.507529500 +0000
+++ third_party/blink/renderer/modules/webgpu/gpu_queue.cc
@@ -788,7 +788,7 @@ bool GPUQueue::CopyFromCanvasSourceImage
 // on linux platform.
 // TODO(crbug.com/1424119): using a webgpu mailbox texture on the OpenGLES
 // backend is failing for unknown reasons.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool forceReadback = true;
 #elif BUILDFLAG(IS_ANDROID)
   // TODO(crbug.com/dawn/1969): Some Android devices don't fail to copy from
