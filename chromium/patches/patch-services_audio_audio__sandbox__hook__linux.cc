$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/audio/audio_sandbox_hook_linux.cc.orig	2024-07-24 02:44:43.597455700 +0000
+++ services/audio/audio_sandbox_hook_linux.cc
@@ -143,6 +143,7 @@ void AddPulseAudioFilePermissions(
 }
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 std::vector<BrokerFilePermission> GetAudioFilePermissions() {
   std::vector<BrokerFilePermission> permissions{
       BrokerFilePermission::ReadOnly("/dev/urandom"),
@@ -171,10 +172,12 @@ void LoadAudioLibraries() {
     }
   }
 }
+#endif
 
 }  // namespace
 
 bool AudioPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
   LoadAudioLibraries();
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
   instance->StartBrokerProcess(MakeBrokerCommandSet({
@@ -192,6 +195,7 @@ bool AudioPreSandboxHook(sandbox::policy
   // TODO(crbug.com/40579955) enable namespace sandbox. Currently, if
   // enabled, connect() on pulse native socket fails with ENOENT (called from
   // pa_context_connect).
+#endif
 
   return true;
 }
