$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/common/sandbox_init_win.h.orig	2024-10-18 12:34:14.466357000 +0000
+++ content/public/common/sandbox_init_win.h
@@ -29,7 +29,7 @@ class SandboxedProcessLauncherDelegate;
 CONTENT_EXPORT sandbox::ResultCode StartSandboxedProcess(
     SandboxedProcessLauncherDelegate* delegate,
     const base::CommandLine& target_command_line,
-    const base::HandlesToInheritVector& handles_to_inherit,
+    const base::LaunchOptions* options,
     base::Process* process);
 
 }  // namespace content
