$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/utility_process_host.cc.orig	2024-10-18 12:34:14.010591500 +0000
+++ content/browser/utility_process_host.cc
@@ -61,7 +61,7 @@
 #include "content/browser/v8_snapshot_files.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
 #include "base/pickle.h"
@@ -74,7 +74,7 @@
 #include "services/network/public/mojom/network_service.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "base/task/sequenced_task_runner.h"
 #include "components/viz/host/gpu_client.h"
 #include "media/capture/capture_switches.h"
@@ -85,7 +85,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 base::ScopedFD PassNetworkContextParentDirs(
     std::vector<base::FilePath> network_context_parent_dirs) {
   base::Pickle pickle;
@@ -150,7 +150,7 @@ UtilityProcessHost::UtilityProcessHost(s
       started_(false),
       name_(u"utility process"),
       file_data_(std::make_unique<ChildProcessLauncherFileData>()),
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       allowed_gpu_(false),
       gpu_client_(nullptr, base::OnTaskRunnerDeleter(nullptr)),
 #endif
@@ -178,11 +178,13 @@ const ChildProcessData& UtilityProcessHo
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
@@ -209,7 +211,7 @@ void UtilityProcessHost::SetPreloadLibra
 #endif  // BUILDFLAG(IS_WIN)
 
 void UtilityProcessHost::SetAllowGpuClient() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   allowed_gpu_ = true;
 #endif
 }
@@ -229,6 +231,24 @@ void UtilityProcessHost::SetZygoteForTes
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
 mojom::ChildProcess* UtilityProcessHost::GetChildProcess() {
   return static_cast<ChildProcessHostImpl*>(process_->GetHost())
       ->child_process();
@@ -348,7 +368,7 @@ bool UtilityProcessHost::StartProcess() 
       switches::kMuteAudio,
       switches::kUseFileForFakeAudioCapture,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD) || \
-    BUILDFLAG(IS_SOLARIS)
+    BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_NETBSD)
       switches::kAlsaInputDevice,
       switches::kAlsaOutputDevice,
 #endif
@@ -407,7 +427,7 @@ bool UtilityProcessHost::StartProcess() 
     file_data_->files_to_preload.merge(GetV8SnapshotFilesToPreload(*cmd_line));
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The network service should have access to the parent directories
     // necessary for its usage.
     if (sandbox_type_ == sandbox::mojom::Sandbox::kNetwork) {
@@ -418,13 +438,13 @@ bool UtilityProcessHost::StartProcess() 
     }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     // Pass `kVideoCaptureUseGpuMemoryBuffer` flag to video capture service only
     // when the video capture use GPU memory buffer enabled.
     if (metrics_name_ == video_capture::mojom::VideoCaptureService::Name_) {
       bool pass_gpu_buffer_flag =
           switches::IsVideoCaptureUseGpuMemoryBufferEnabled();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Check if NV12 GPU memory buffer supported at the same time.
       pass_gpu_buffer_flag =
           pass_gpu_buffer_flag &&
@@ -436,9 +456,22 @@ bool UtilityProcessHost::StartProcess() 
     }
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
 
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
 
 #if BUILDFLAG(IS_WIN)
     if (!preload_libraries_.empty()) {
@@ -476,7 +509,7 @@ void UtilityProcessHost::OnProcessCrashe
   // Take ownership of |client_| so the destructor doesn't notify it of
   // termination.
   auto client = std::move(client_);
-  client->OnProcessCrashed();
+  client->OnProcessCrashed(exit_code);
 }
 
 std::optional<std::string> UtilityProcessHost::GetServiceName() {
