$NetBSD$

--- content/gpu/gpu_main.cc.orig	2017-02-02 02:02:53.000000000 +0000
+++ content/gpu/gpu_main.cc
@@ -92,7 +92,7 @@ namespace content {
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*);
 #elif defined(OS_WIN)
 bool StartSandboxWindows(const sandbox::SandboxInterfaceInfo*);
@@ -145,7 +145,7 @@ class ContentSandboxHelper : public gpu:
 
   bool EnsureSandboxInitialized(
       gpu::GpuWatchdogThread* watchdog_thread) override {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     return StartSandboxLinux(watchdog_thread);
 #elif defined(OS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -292,12 +292,13 @@ int GpuMain(const MainFunctionParams& pa
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread) {
   TRACE_EVENT0("gpu,startup", "Initialize sandbox");
 
   bool res = false;
 
+#if !defined(OS_BSD)
   if (watchdog_thread) {
     // LinuxSandbox needs to be able to ensure that the thread
     // has really been stopped.
@@ -322,6 +323,7 @@ bool StartSandboxLinux(gpu::GpuWatchdogT
     options.timer_slack = base::TIMER_SLACK_MAXIMUM;
     watchdog_thread->StartWithOptions(options);
   }
+#endif
 
   return res;
 }
