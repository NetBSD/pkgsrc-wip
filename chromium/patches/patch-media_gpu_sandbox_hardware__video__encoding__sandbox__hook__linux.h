$NetBSD: patch-media_gpu_sandbox_hardware__video__encoding__sandbox__hook__linux.h,v 1.1 2025/02/06 09:58:13 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/sandbox/hardware_video_encoding_sandbox_hook_linux.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/gpu/sandbox/hardware_video_encoding_sandbox_hook_linux.h
@@ -5,7 +5,13 @@
 #ifndef MEDIA_GPU_SANDBOX_HARDWARE_VIDEO_ENCODING_SANDBOX_HOOK_LINUX_H_
 #define MEDIA_GPU_SANDBOX_HARDWARE_VIDEO_ENCODING_SANDBOX_HOOK_LINUX_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace media {
 
@@ -14,4 +20,4 @@ bool HardwareVideoEncodingPreSandboxHook
 
 }  // namespace media
 
-#endif  // MEDIA_GPU_SANDBOX_HARDWARE_VIDEO_ENCODING_SANDBOX_HOOK_LINUX_H_
\ No newline at end of file
+#endif  // MEDIA_GPU_SANDBOX_HARDWARE_VIDEO_ENCODING_SANDBOX_HOOK_LINUX_H_
