$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/app/content_main_runner_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/app/content_main_runner_impl.cc
@@ -147,18 +147,20 @@
 #include "content/browser/posix_file_descriptor_info_impl.h"
 #include "content/public/common/content_descriptors.h"
 
-#if !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 #include "content/public/common/zygote/zygote_fork_delegate_linux.h"
 #endif
 
 #endif  // BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_path_watcher_inotify.h"
 #include "base/native_library.h"
 #include "base/rand_util.h"
 #include "content/public/common/zygote/sandbox_support_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "third_party/boringssl/src/include/openssl/crypto.h"
 #include "third_party/webrtc_overrides/init_webrtc.h"  // nogncheck
 
@@ -192,6 +194,10 @@
 #include "media/base/media_switches.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "base/system/sys_info.h"
+#endif
+
 #if BUILDFLAG(IS_ANDROID)
 #include "base/system/sys_info.h"
 #include "content/browser/android/battery_metrics.h"
@@ -279,8 +285,13 @@ void AsanProcessInfoCB(const char*, bool
 }
 #endif  // defined(ADDRESS_SANITIZER)
 
-void LoadV8SnapshotFile(const base::CommandLine& command_line) {
+void LoadV8SnapshotFile(const raw_ptr<ContentMainDelegate> delegate, const base::CommandLine& command_line) {
   const gin::V8SnapshotFileType snapshot_type = GetSnapshotType(command_line);
+  std::string_view browser_v8_snapshot_file_name = delegate->GetBrowserV8SnapshotFilename();
+  if (!browser_v8_snapshot_file_name.empty()) {
+    gin::V8Initializer::LoadV8SnapshotFromFileName(browser_v8_snapshot_file_name, snapshot_type);
+    return;
+  }
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
   base::FileDescriptorStore& file_descriptor_store =
       base::FileDescriptorStore::GetInstance();
@@ -300,11 +311,8 @@ void LoadV8SnapshotFile(const base::Comm
 
 bool ShouldLoadV8Snapshot(const base::CommandLine& command_line,
                           const std::string& process_type) {
-  // The gpu does not need v8, and the browser only needs v8 when in single
-  // process mode.
-  if (process_type == switches::kGpuProcess ||
-      (process_type.empty() &&
-       !command_line.HasSwitch(switches::kSingleProcess))) {
+  // The gpu does not need v8
+  if (process_type == switches::kGpuProcess) {
     return false;
   }
   return true;
@@ -312,11 +320,12 @@ bool ShouldLoadV8Snapshot(const base::Co
 
 #endif  // V8_USE_EXTERNAL_STARTUP_DATA
 
-void LoadV8SnapshotIfNeeded(const base::CommandLine& command_line,
+void LoadV8SnapshotIfNeeded(const raw_ptr<ContentMainDelegate> delegate,
+                            const base::CommandLine& command_line,
                             const std::string& process_type) {
 #if defined(V8_USE_EXTERNAL_STARTUP_DATA)
   if (ShouldLoadV8Snapshot(command_line, process_type))
-    LoadV8SnapshotFile(command_line);
+    LoadV8SnapshotFile(delegate, command_line);
 #endif  // V8_USE_EXTERNAL_STARTUP_DATA
 }
 
@@ -399,7 +408,7 @@ void InitializeZygoteSandboxForBrowserPr
 }
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 #if BUILDFLAG(ENABLE_PPAPI)
 // Loads the (native) libraries but does not initialize them (i.e., does not
@@ -437,7 +446,10 @@ void PreloadLibraryCdms() {
 
 void PreSandboxInit() {
   // Ensure the /dev/urandom is opened.
+  // we use arc4random
+#if !BUILDFLAG(IS_BSD)
   base::GetUrandomFD();
+#endif
 
   // May use sysinfo(), sched_getaffinity(), and open various /sys/ and /proc/
   // files.
@@ -449,9 +461,16 @@ void PreSandboxInit() {
   // https://boringssl.googlesource.com/boringssl/+/HEAD/SANDBOXING.md
   CRYPTO_pre_sandbox_init();
 
+#if BUILDFLAG(IS_BSD)
+  // "cache" the amount of physical memory before pledge(2)
+  base::SysInfo::AmountOfPhysicalMemoryMB();
+#endif
+
+#if !BUILDFLAG(IS_BSD)
   // Pre-read /proc/sys/fs/inotify/max_user_watches so it doesn't have to be
   // allowed by the sandbox.
   base::GetMaxNumberOfInotifyWatches();
+#endif
 
 #if BUILDFLAG(ENABLE_PPAPI)
   // Ensure access to the Pepper plugins before the sandbox is turned on.
@@ -762,7 +781,7 @@ NO_STACK_PROTECTOR int RunOtherNamedProc
     unregister_thread_closure = base::HangWatcher::RegisterThread(
         base::HangWatcher::ThreadType::kMainThread);
     bool start_hang_watcher_now;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // On Linux/ChromeOS, the HangWatcher can't start until after the sandbox is
     // initialized, because the sandbox can't be started with multiple threads.
     // TODO(mpdenton): start the HangWatcher after the sandbox is initialized.
@@ -872,11 +891,10 @@ int ContentMainRunnerImpl::Initialize(Co
                  base::GlobalDescriptors::kBaseDescriptor);
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
   g_fds->Set(kCrashDumpSignal,
              kCrashDumpSignal + base::GlobalDescriptors::kBaseDescriptor);
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_OPENBSD)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 #endif  // !BUILDFLAG(IS_WIN)
 
@@ -992,7 +1010,7 @@ int ContentMainRunnerImpl::Initialize(Co
     return TerminateForFatalInitializationError();
 #endif  // BUILDFLAG(IS_ANDROID) && (ICU_UTIL_DATA_IMPL == ICU_UTIL_DATA_FILE)
 
-  LoadV8SnapshotIfNeeded(command_line, process_type);
+  LoadV8SnapshotIfNeeded(delegate_, command_line, process_type);
 
   blink::TrialTokenValidator::SetOriginTrialPolicyGetter(
       base::BindRepeating([]() -> blink::OriginTrialPolicy* {
@@ -1057,6 +1075,18 @@ int ContentMainRunnerImpl::Initialize(Co
       process_type == switches::kZygoteProcess) {
     PreSandboxInit();
   }
+#elif BUILDFLAG(IS_BSD)
+  PreSandboxInit();
+#endif
+
+#if BUILDFLAG(IS_BSD)
+  if (process_type.empty()) {
+    sandbox::policy::SandboxLinux::Options sandbox_options;
+    sandbox::policy::SandboxLinux::GetInstance()->InitializeSandbox(
+        sandbox::policy::SandboxTypeFromCommandLine(
+            *base::CommandLine::ForCurrentProcess()),
+        sandbox::policy::SandboxLinux::PreSandboxHook(), sandbox_options);
+  }
 #endif
 
   delegate_->SandboxInitialized(process_type);
@@ -1156,6 +1186,11 @@ NO_STACK_PROTECTOR int ContentMainRunner
 
   RegisterMainThreadFactories();
 
+#if BUILDFLAG(IS_BSD)
+  if (!process_type.empty())
+    PreSandboxInit();
+#endif 
+
   if (process_type.empty())
     return RunBrowser(std::move(main_params), start_minimal_browser);
 
