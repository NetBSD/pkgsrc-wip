$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/policy/win/sandbox_win.cc.orig	2024-10-18 12:34:31.997764600 +0000
+++ sandbox/policy/win/sandbox_win.cc
@@ -699,11 +699,9 @@ base::win::ScopedHandle CreateUnsandboxe
 // command line flag.
 ResultCode LaunchWithoutSandbox(
     const base::CommandLine& cmd_line,
-    const base::HandlesToInheritVector& handles_to_inherit,
+    base::LaunchOptions options,
     SandboxDelegate* delegate,
     base::Process* process) {
-  base::LaunchOptions options;
-  options.handles_to_inherit = handles_to_inherit;
   // Network process runs in a job even when unsandboxed. This is to ensure it
   // does not outlive the browser, which could happen if there is a lot of I/O
   // on process shutdown, in which case TerminateProcess can fail. See
@@ -938,7 +936,7 @@ bool SandboxWin::InitTargetServices(Targ
 // static
 ResultCode SandboxWin::GeneratePolicyForSandboxedProcess(
     const base::CommandLine& cmd_line,
-    const base::HandlesToInheritVector& handles_to_inherit,
+    const base::LaunchOptions* options,
     SandboxDelegate* delegate,
     TargetPolicy* policy) {
   const base::CommandLine& launcher_process_command_line =
@@ -952,7 +950,7 @@ ResultCode SandboxWin::GeneratePolicyFor
   }
 
   // Add any handles to be inherited to the policy.
-  for (HANDLE handle : handles_to_inherit)
+  for (HANDLE handle : options->handles_to_inherit)
     policy->AddHandleToShare(handle);
 
   if (!policy->GetConfig()->IsConfigured()) {
@@ -967,6 +965,13 @@ ResultCode SandboxWin::GeneratePolicyFor
   // have no effect. These calls can fail with SBOX_ERROR_BAD_PARAMS.
   policy->SetStdoutHandle(GetStdHandle(STD_OUTPUT_HANDLE));
   policy->SetStderrHandle(GetStdHandle(STD_ERROR_HANDLE));
+#else
+  if (options->stdout_handle != nullptr && options->stdout_handle != INVALID_HANDLE_VALUE) {
+    policy->SetStdoutHandle(options->stdout_handle);
+  }
+  if (options->stderr_handle != nullptr && options->stderr_handle != INVALID_HANDLE_VALUE) {
+    policy->SetStderrHandle(options->stderr_handle);
+  }
 #endif
 
   if (!delegate->PreSpawnTarget(policy))
@@ -978,7 +983,7 @@ ResultCode SandboxWin::GeneratePolicyFor
 // static
 ResultCode SandboxWin::StartSandboxedProcess(
     const base::CommandLine& cmd_line,
-    const base::HandlesToInheritVector& handles_to_inherit,
+    const base::LaunchOptions* options,
     SandboxDelegate* delegate,
     base::Process* process) {
   SandboxLaunchTimer timer;
@@ -986,7 +991,7 @@ ResultCode SandboxWin::StartSandboxedPro
   // Avoid making a policy if we won't use it.
   if (IsUnsandboxedProcess(delegate->GetSandboxType(), cmd_line,
                            *base::CommandLine::ForCurrentProcess())) {
-    return LaunchWithoutSandbox(cmd_line, handles_to_inherit, delegate,
+    return LaunchWithoutSandbox(cmd_line, *options, delegate,
                                 process);
   }
 
@@ -994,7 +999,7 @@ ResultCode SandboxWin::StartSandboxedPro
   timer.OnPolicyCreated();
 
   ResultCode result = GeneratePolicyForSandboxedProcess(
-      cmd_line, handles_to_inherit, delegate, policy.get());
+      cmd_line, options, delegate, policy.get());
   if (SBOX_ALL_OK != result)
     return result;
   timer.OnPolicyGenerated();
