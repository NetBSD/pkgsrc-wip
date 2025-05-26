$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/common/sandbox_init_win.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/common/sandbox_init_win.cc
@@ -23,7 +23,7 @@ namespace content {
 sandbox::ResultCode StartSandboxedProcess(
     SandboxedProcessLauncherDelegate* delegate,
     const base::CommandLine& target_command_line,
-    const base::HandlesToInheritVector& handles_to_inherit,
+    const base::LaunchOptions* options,
     sandbox::StartSandboxedProcessCallback result_callback) {
   std::string type_str =
       target_command_line.GetSwitchValueASCII(switches::kProcessType);
@@ -45,7 +45,7 @@ sandbox::ResultCode StartSandboxedProces
   }
 
   return sandbox::policy::SandboxWin::StartSandboxedProcess(
-      full_command_line, handles_to_inherit, delegate,
+      full_command_line, options, delegate,
       std::move(result_callback));
 }
 
