$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/utility_process_host.cc.orig	2025-01-07 19:49:01.000000000 +0000
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
@@ -347,7 +347,7 @@ bool UtilityProcessHost::StartProcess() 
         switches::kMuteAudio,
         switches::kUseFileForFakeAudioCapture,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD) || \
-    BUILDFLAG(IS_SOLARIS)
+    BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_NETBSD)
         switches::kAlsaInputDevice,
         switches::kAlsaOutputDevice,
 #endif
@@ -403,7 +403,7 @@ bool UtilityProcessHost::StartProcess() 
     file_data_->files_to_preload.merge(GetV8SnapshotFilesToPreload(*cmd_line));
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The network service should have access to the parent directories
     // necessary for its usage.
     if (sandbox_type_ == sandbox::mojom::Sandbox::kNetwork) {
@@ -420,7 +420,7 @@ bool UtilityProcessHost::StartProcess() 
     if (metrics_name_ == video_capture::mojom::VideoCaptureService::Name_) {
       bool pass_gpu_buffer_flag =
           switches::IsVideoCaptureUseGpuMemoryBufferEnabled();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Check if NV12 GPU memory buffer supported at the same time.
       pass_gpu_buffer_flag =
           pass_gpu_buffer_flag &&
