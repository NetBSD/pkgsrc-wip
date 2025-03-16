$NetBSD: patch-media_gpu_sandbox_hardware__video__encoding__sandbox__hook__linux.cc,v 1.1 2025/02/06 09:58:13 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/sandbox/hardware_video_encoding_sandbox_hook_linux.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/gpu/sandbox/hardware_video_encoding_sandbox_hook_linux.cc
@@ -18,12 +18,15 @@
 #include "media/gpu/v4l2/v4l2_device.h"
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
+#endif
 
 namespace media {
 
 bool HardwareVideoEncodingPreSandboxHook(
     sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
   sandbox::syscall_broker::BrokerCommandSet command_set;
   std::vector<BrokerFilePermission> permissions;
 
@@ -132,6 +135,7 @@ bool HardwareVideoEncodingPreSandboxHook
     dlopen("libvulkan_radeon.so", kDlopenFlags);
   }
 #endif
+#endif
   return true;
 }
 
