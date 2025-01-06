$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/common/sandbox_init_win.cc.orig	2024-10-18 12:34:14.242472200 +0000
+++ content/common/sandbox_init_win.cc
@@ -23,7 +23,7 @@ namespace content {
 sandbox::ResultCode StartSandboxedProcess(
     SandboxedProcessLauncherDelegate* delegate,
     const base::CommandLine& target_command_line,
-    const base::HandlesToInheritVector& handles_to_inherit,
+    const base::LaunchOptions* options,
     base::Process* process) {
   std::string type_str =
       target_command_line.GetSwitchValueASCII(switches::kProcessType);
@@ -45,7 +45,7 @@ sandbox::ResultCode StartSandboxedProces
   }
 
   return sandbox::policy::SandboxWin::StartSandboxedProcess(
-      full_command_line, handles_to_inherit, delegate, process);
+      full_command_line, options, delegate, process);
 }
 
 }  // namespace content
