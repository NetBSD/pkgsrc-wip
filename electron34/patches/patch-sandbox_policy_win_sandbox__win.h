$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/policy/win/sandbox_win.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ sandbox/policy/win/sandbox_win.h
@@ -92,7 +92,7 @@ class SANDBOX_POLICY_EXPORT SandboxWin {
   // any other error.
   static ResultCode StartSandboxedProcess(
       const base::CommandLine& cmd_line,
-      const base::HandlesToInheritVector& handles_to_inherit,
+      const base::LaunchOptions* options,
       SandboxDelegate* delegate,
       StartSandboxedProcessCallback result_callback);
 
@@ -105,7 +105,7 @@ class SANDBOX_POLICY_EXPORT SandboxWin {
   // of sandbox::ResultCode for any other error while constructing the policy.
   static ResultCode GeneratePolicyForSandboxedProcess(
       const base::CommandLine& cmd_line,
-      const base::HandlesToInheritVector& handles_to_inherit,
+      const base::LaunchOptions* options,
       SandboxDelegate* delegate,
       TargetPolicy* policy);
 
