$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/utility_process_host.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/utility_process_host.cc
@@ -62,7 +62,7 @@
 #include "content/browser/v8_snapshot_files.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
 #include "base/pickle.h"
@@ -86,7 +86,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 base::ScopedFD PassNetworkContextParentDirs(
     std::vector<base::FilePath> network_context_parent_dirs) {
   base::Pickle pickle;
@@ -179,11 +179,13 @@ const ChildProcessData& UtilityProcessHo
   return process_->GetData();
 }
 
-#if BUILDFLAG(IS_POSIX)
 void UtilityProcessHost::SetEnv(const base::EnvironmentMap& env) {
   env_ = env;
 }
-#endif
+
+void UtilityProcessHost::ClearEnvironment() {
+  inherit_environment_ = false;
+}
 
 bool UtilityProcessHost::Start() {
   return StartProcess();
@@ -230,6 +232,30 @@ void UtilityProcessHost::SetZygoteForTes
 }
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
+#if BUILDFLAG(IS_WIN)
+void UtilityProcessHost::SetStdioHandles(
+    base::win::ScopedHandle stdout_handle,
+    base::win::ScopedHandle stderr_handle) {
+  stdout_handle_ = std::move(stdout_handle);
+  stderr_handle_ = std::move(stderr_handle);
+}
+#elif BUILDFLAG(IS_POSIX)
+void UtilityProcessHost::SetAdditionalFds(base::FileHandleMappingVector mapping) {
+  fds_to_remap_ = std::move(mapping);
+}
+#endif
+
+void UtilityProcessHost::SetCurrentDirectory(
+    const base::FilePath& cwd) {
+  current_directory_ = cwd;
+}
+
+#if BUILDFLAG(IS_WIN)
+void UtilityProcessHost::SetFeedbackCursorOff(bool feedback_cursor_off) {
+  feedback_cursor_off_ = feedback_cursor_off;
+}
+#endif  // BUILDFLAG(IS_WIN)
+
 mojom::ChildProcess* UtilityProcessHost::GetChildProcess() {
   return static_cast<ChildProcessHostImpl*>(process_->GetHost())
       ->child_process();
@@ -347,7 +373,7 @@ bool UtilityProcessHost::StartProcess() 
         switches::kMuteAudio,
         switches::kUseFileForFakeAudioCapture,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD) || \
-    BUILDFLAG(IS_SOLARIS)
+    BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_NETBSD)
         switches::kAlsaInputDevice,
         switches::kAlsaOutputDevice,
 #endif
@@ -403,7 +429,7 @@ bool UtilityProcessHost::StartProcess() 
     file_data_->files_to_preload.merge(GetV8SnapshotFilesToPreload(*cmd_line));
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The network service should have access to the parent directories
     // necessary for its usage.
     if (sandbox_type_ == sandbox::mojom::Sandbox::kNetwork) {
@@ -420,7 +446,7 @@ bool UtilityProcessHost::StartProcess() 
     if (metrics_name_ == video_capture::mojom::VideoCaptureService::Name_) {
       bool pass_gpu_buffer_flag =
           switches::IsVideoCaptureUseGpuMemoryBufferEnabled();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Check if NV12 GPU memory buffer supported at the same time.
       pass_gpu_buffer_flag =
           pass_gpu_buffer_flag &&
@@ -432,9 +458,26 @@ bool UtilityProcessHost::StartProcess() 
     }
 #endif  // BUILDFLAG(ENABLE_GPU_CHANNEL_MEDIA_CAPTURE) && !BUILDFLAG(IS_WIN)
 
+#if BUILDFLAG(IS_WIN)
+    file_data_->stdout_handle = std::move(stdout_handle_);
+    file_data_->stderr_handle = std::move(stderr_handle_);
+#elif BUILDFLAG(IS_POSIX)
+    if (!fds_to_remap_.empty()) {
+      for (const auto& remapped_fd : fds_to_remap_) {
+        file_data_->additional_remapped_fds.emplace(
+            remapped_fd.second, remapped_fd.first);
+      }
+    }
+#endif
+
     std::unique_ptr<UtilitySandboxedProcessLauncherDelegate> delegate =
         std::make_unique<UtilitySandboxedProcessLauncherDelegate>(
-            sandbox_type_, env_, *cmd_line);
+            sandbox_type_, env_, current_directory_, *cmd_line,
+            inherit_environment_);
+
+#if BUILDFLAG(IS_WIN)
+    delegate->SetFeedbackCursorOff(feedback_cursor_off_);
+#endif  // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_WIN)
     if (!preload_libraries_.empty()) {
@@ -472,7 +515,7 @@ void UtilityProcessHost::OnProcessCrashe
   // Take ownership of |client_| so the destructor doesn't notify it of
   // termination.
   auto client = std::move(client_);
-  client->OnProcessCrashed();
+  client->OnProcessCrashed(exit_code);
 }
 
 std::optional<std::string> UtilityProcessHost::GetServiceName() {
