$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/gpu/gpu_main.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/gpu/gpu_main.cc
@@ -95,10 +95,14 @@
 #include "sandbox/win/src/sandbox.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #include "content/common/gpu_pre_sandbox_hook_linux.h"
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "sandbox/policy/sandbox_type.h"
 #endif
 
@@ -117,7 +121,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*,
                        const gpu::GPUInfo*,
                        const gpu::GpuPreferences&);
@@ -175,7 +179,7 @@ class ContentSandboxHelper : public gpu:
   bool EnsureSandboxInitialized(gpu::GpuWatchdogThread* watchdog_thread,
                                 const gpu::GPUInfo* gpu_info,
                                 const gpu::GpuPreferences& gpu_prefs) override {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     return StartSandboxLinux(watchdog_thread, gpu_info, gpu_prefs);
 #elif BUILDFLAG(IS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -258,6 +262,10 @@ int GpuMain(MainFunctionParams parameter
   // to the GpuProcessHost once the GpuServiceImpl has started.
   viz::GpuServiceImpl::InstallPreInitializeLogHandler();
 
+  auto* client = GetContentClient()->gpu();
+  if (client)
+    client->PreCreateMessageLoop();
+
   // We are experiencing what appear to be memory-stomp issues in the GPU
   // process. These issues seem to be impacting the task executor and listeners
   // registered to it. Create the task executor on the heap to guard against
@@ -293,7 +301,7 @@ int GpuMain(MainFunctionParams parameter
           std::make_unique<base::SingleThreadTaskExecutor>(
               gpu_preferences.message_pump_type);
     }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #error "Unsupported Linux platform."
 #elif BUILDFLAG(IS_MAC)
     // Cross-process CoreAnimation requires a CFRunLoop to function at all, and
@@ -318,7 +326,8 @@ int GpuMain(MainFunctionParams parameter
   base::PlatformThread::SetName("CrGpuMain");
   mojo::InterfaceEndpointClient::SetThreadNameSuffixForMetrics("GpuMain");
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+// XXX BSD
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   // Thread type delegate of the process should be registered before
   // thread type change below for the main thread and for thread pool in
   // ChildProcess constructor.
@@ -368,7 +377,6 @@ int GpuMain(MainFunctionParams parameter
 #endif
   const bool dead_on_arrival = !init_success;
 
-  auto* client = GetContentClient()->gpu();
   if (client) {
     client->PostSandboxInitialized();
   }
@@ -449,7 +457,7 @@ int GpuMain(MainFunctionParams parameter
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread,
                        const gpu::GPUInfo* gpu_info,
                        const gpu::GpuPreferences& gpu_prefs) {
@@ -489,7 +497,7 @@ bool StartSandboxLinux(gpu::GpuWatchdogT
   sandbox_options.accelerated_video_encode_enabled =
       !gpu_prefs.disable_accelerated_video_encode;
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Video decoding of many video streams can use thousands of FDs as well as
   // Exo clients like Lacros.
   // See https://crbug.com/1417237
