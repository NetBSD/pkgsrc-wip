$NetBSD$

--- content/browser/child_process_launcher.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/child_process_launcher.cc
@@ -258,7 +258,7 @@ void LaunchOnLauncherThread(const Notify
   // We need to close the client end of the IPC channel to reliably detect
   // child termination.
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   ZygoteHandle* zygote_handle = delegate->GetZygote();
   // If |zygote_handle| is null, a zygote should not be used.
   if (zygote_handle) {
@@ -364,7 +364,7 @@ void TerminateOnLauncherThread(ZygoteHan
   process.Terminate(RESULT_CODE_NORMAL_EXIT, false);
   // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   if (zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
@@ -485,7 +485,7 @@ void ChildProcessLauncher::Launch(
 
 void ChildProcessLauncher::UpdateTerminationStatus(bool known_dead) {
   DCHECK(CalledOnValidThread());
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (zygote_) {
     termination_status_ = zygote_->GetTerminationStatus(
         process_.Handle(), known_dead, &exit_code_);
@@ -566,7 +566,7 @@ void ChildProcessLauncher::Notify(Zygote
                                     mojo_child_token_, process_error_callback_);
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   zygote_ = zygote;
 #endif
   if (process_.IsValid()) {
