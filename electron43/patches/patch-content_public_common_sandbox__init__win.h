$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/common/sandbox_init_win.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/common/sandbox_init_win.h
@@ -29,7 +29,7 @@ class SandboxedProcessLauncherDelegate;
 CONTENT_EXPORT sandbox::ResultCode StartSandboxedProcess(
     SandboxedProcessLauncherDelegate* delegate,
     const base::CommandLine& target_command_line,
-    const base::HandlesToInheritVector& handles_to_inherit,
+    const base::LaunchOptions* options,
     sandbox::StartSandboxedProcessCallback result_callback);
 
 }  // namespace content
