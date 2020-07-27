$NetBSD$

--- content/gpu/gpu_main.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ content/gpu/gpu_main.cc
@@ -85,7 +85,7 @@
 #include "ui/gfx/x/x11_types.h"                          // nogncheck
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/gpu/gpu_sandbox_hook_linux.h"
 #include "content/public/common/sandbox_init.h"
 #include "services/service_manager/sandbox/linux/sandbox_linux.h"
@@ -109,7 +109,7 @@ namespace content {
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*,
                        const gpu::GPUInfo*,
                        const gpu::GpuPreferences&);
@@ -162,7 +162,7 @@ class ContentSandboxHelper : public gpu:
   bool EnsureSandboxInitialized(gpu::GpuWatchdogThread* watchdog_thread,
                                 const gpu::GPUInfo* gpu_info,
                                 const gpu::GpuPreferences& gpu_prefs) override {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     return StartSandboxLinux(watchdog_thread, gpu_info, gpu_prefs);
 #elif defined(OS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -297,7 +297,7 @@ int GpuMain(const MainFunctionParams& pa
               gpu_preferences.message_pump_type);
     }
 #endif
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #error "Unsupported Linux platform."
 #elif defined(OS_MACOSX)
     // Cross-process CoreAnimation requires a CFRunLoop to function at all, and
@@ -450,7 +450,7 @@ int GpuMain(const MainFunctionParams& pa
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread,
                        const gpu::GPUInfo* gpu_info,
                        const gpu::GpuPreferences& gpu_prefs) {
