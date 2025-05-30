$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.cc
@@ -16,7 +16,9 @@
 #include "media/gpu/vaapi/vaapi_wrapper.h"
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
+#endif
 
 // TODO(b/195769334): the hardware video decoding sandbox is really only useful
 // when building with VA-API or V4L2 (otherwise, we're not really doing hardware
@@ -32,6 +34,7 @@ using sandbox::syscall_broker::BrokerFil
 namespace media {
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 void AllowAccessToRenderNodes(std::vector<BrokerFilePermission>& permissions,
                               bool include_sys_dev_char,
                               bool read_write) {
@@ -188,6 +191,7 @@ bool HardwareVideoDecodingPreSandboxHook
   NOTREACHED();
 #endif  // BUILDFLAG(USE_V4L2_CODEC)
 }
+#endif
 
 }  // namespace
 
@@ -203,6 +207,7 @@ bool HardwareVideoDecodingPreSandboxHook
 //   (at least).
 bool HardwareVideoDecodingPreSandboxHook(
     sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
   using HardwareVideoDecodingProcessPolicy =
       sandbox::policy::HardwareVideoDecodingProcessPolicy;
   using PolicyType =
@@ -248,6 +253,7 @@ bool HardwareVideoDecodingPreSandboxHook
   // |permissions| is empty?
   sandbox::policy::SandboxLinux::GetInstance()->StartBrokerProcess(
       command_set, permissions, options);
+#endif
   return true;
 }
 
