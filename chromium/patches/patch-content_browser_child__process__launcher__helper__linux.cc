$NetBSD$

--- content/browser/child_process_launcher_helper_linux.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ content/browser/child_process_launcher_helper_linux.cc
@@ -19,7 +19,9 @@
 #include "content/public/common/result_codes.h"
 #include "content/public/common/sandboxed_process_launcher_delegate.h"
 #include "content/public/common/zygote/sandbox_support_linux.h"
+#if !defined(OS_BSD)
 #include "content/public/common/zygote/zygote_handle.h"
+#endif
 #include "services/service_manager/sandbox/linux/sandbox_linux.h"
 
 namespace content {
@@ -50,10 +52,12 @@ bool ChildProcessLauncherHelper::BeforeL
   options->fds_to_remap = files_to_register.GetMappingWithIDAdjustment(
       base::GlobalDescriptors::kBaseDescriptor);
 
+#if !defined(OS_BSD)
   if (GetProcessType() == switches::kRendererProcess) {
     const int sandbox_fd = SandboxHostLinux::GetInstance()->GetChildSocket();
     options->fds_to_remap.push_back(std::make_pair(sandbox_fd, GetSandboxFD()));
   }
+#endif
 
   options->environment = delegate_->GetEnvironment();
 
@@ -141,13 +145,17 @@ void ChildProcessLauncherHelper::ForceNo
   DCHECK(CurrentlyOnProcessLauncherTaskRunner());
   process.process.Terminate(service_manager::RESULT_CODE_NORMAL_EXIT, false);
   // On POSIX, we must additionally reap the child.
+#if !defined(OS_BSD)
   if (process.zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
     process.zygote->EnsureProcessTerminated(process.process.Handle());
   } else {
+#endif
     base::EnsureProcessTerminated(std::move(process.process));
+#if !defined(OS_BSD)
   }
+#endif
 }
 
 void ChildProcessLauncherHelper::SetProcessPriorityOnLauncherThread(
