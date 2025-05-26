$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/policy/win/sandbox_win.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ sandbox/policy/win/sandbox_win.cc
@@ -619,11 +619,9 @@ base::win::ScopedHandle CreateUnsandboxe
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
@@ -920,7 +918,7 @@ bool SandboxWin::InitTargetServices(Targ
 // static
 ResultCode SandboxWin::GeneratePolicyForSandboxedProcess(
     const base::CommandLine& cmd_line,
-    const base::HandlesToInheritVector& handles_to_inherit,
+    const base::LaunchOptions* options,
     SandboxDelegate* delegate,
     TargetPolicy* policy) {
   const base::CommandLine& launcher_process_command_line =
@@ -934,7 +932,7 @@ ResultCode SandboxWin::GeneratePolicyFor
   }
 
   // Add any handles to be inherited to the policy.
-  for (HANDLE handle : handles_to_inherit)
+  for (HANDLE handle : options->handles_to_inherit)
     policy->AddHandleToShare(handle);
 
   if (!policy->GetConfig()->IsConfigured()) {
@@ -949,6 +947,13 @@ ResultCode SandboxWin::GeneratePolicyFor
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
@@ -960,7 +965,7 @@ ResultCode SandboxWin::GeneratePolicyFor
 // static
 ResultCode SandboxWin::StartSandboxedProcess(
     const base::CommandLine& cmd_line,
-    const base::HandlesToInheritVector& handles_to_inherit,
+    const base::LaunchOptions* options,
     SandboxDelegate* delegate,
     StartSandboxedProcessCallback result_callback) {
   SandboxLaunchTimer timer;
@@ -970,7 +975,7 @@ ResultCode SandboxWin::StartSandboxedPro
                            *base::CommandLine::ForCurrentProcess())) {
     base::Process process;
     ResultCode result =
-        LaunchWithoutSandbox(cmd_line, handles_to_inherit, delegate, &process);
+        LaunchWithoutSandbox(cmd_line, *options, delegate, &process);
     DWORD last_error = GetLastError();
     std::move(result_callback).Run(std::move(process), last_error, result);
     return SBOX_ALL_OK;
@@ -980,7 +985,7 @@ ResultCode SandboxWin::StartSandboxedPro
   timer.OnPolicyCreated();
 
   ResultCode result = GeneratePolicyForSandboxedProcess(
-      cmd_line, handles_to_inherit, delegate, policy.get());
+      cmd_line, options, delegate, policy.get());
   if (SBOX_ALL_OK != result) {
     DWORD last_error = GetLastError();
     std::move(result_callback).Run(base::Process(), last_error, result);
