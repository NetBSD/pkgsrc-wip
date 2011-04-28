$NetBSD: patch-chrome_browser_child__process__launcher.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/child_process_launcher.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/browser/child_process_launcher.cc
@@ -20,7 +20,7 @@
 #if defined(OS_WIN)
 #include "base/file_path.h"
 #include "chrome/common/sandbox_policy.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/singleton.h"
 #include "chrome/browser/crash_handler_host_linux.h"
 #include "chrome/browser/zygote_host_linux.h"
@@ -45,7 +45,7 @@ class ChildProcessLauncher::Context
       : client_(NULL),
         client_thread_id_(BrowserThread::UI),
         starting_(true)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         , zygote_(false)
 #endif
         {
@@ -110,7 +110,7 @@ class ChildProcessLauncher::Context
     handle = sandbox::StartProcessWithAccess(cmd_line, exposed_dir);
 #elif defined(OS_POSIX)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     if (use_zygote) {
       base::GlobalDescriptors::Mapping mapping;
       mapping.push_back(std::pair<uint32_t, int>(kPrimaryIPCChannel, ipcfd));
@@ -131,7 +131,7 @@ class ChildProcessLauncher::Context
           ipcfd,
           kPrimaryIPCChannel + base::GlobalDescriptors::kBaseDescriptor));
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // On Linux, we need to add some extra file descriptors for crash handling
       // and the sandbox.
       bool is_renderer =
@@ -205,20 +205,20 @@ class ChildProcessLauncher::Context
         NewRunnableMethod(
             this,
             &ChildProcessLauncher::Context::Notify,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
             use_zygote,
 #endif
             handle));
   }
 
   void Notify(
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
     starting_ = false;
     process_.set_handle(handle);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     zygote_ = zygote;
 #endif
     if (client_) {
@@ -238,7 +238,7 @@ class ChildProcessLauncher::Context
         BrowserThread::PROCESS_LAUNCHER, FROM_HERE,
         NewRunnableFunction(
             &ChildProcessLauncher::Context::TerminateInternal,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
             zygote_,
 #endif
             process_.handle()));
@@ -246,7 +246,7 @@ class ChildProcessLauncher::Context
   }
 
   static void TerminateInternal(
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       bool zygote,
 #endif
       base::ProcessHandle handle) {
@@ -256,7 +256,7 @@ class ChildProcessLauncher::Context
     process.Terminate(ResultCodes::NORMAL_EXIT);
     // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     if (zygote) {
       // If the renderer was created via a zygote, we have to proxy the reaping
       // through the zygote process.
@@ -275,7 +275,7 @@ class ChildProcessLauncher::Context
   base::Process process_;
   bool starting_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   bool zygote_;
 #endif
 };
@@ -321,7 +321,7 @@ base::TerminationStatus ChildProcessLaun
     int* exit_code) {
   base::TerminationStatus status;
   base::ProcessHandle handle = context_->process_.handle();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (context_->zygote_) {
     status = ZygoteHost::GetInstance()->GetTerminationStatus(handle, exit_code);
   } else
