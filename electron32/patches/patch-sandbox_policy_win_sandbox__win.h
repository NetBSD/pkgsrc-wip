$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/policy/win/sandbox_win.h.orig	2024-10-18 12:34:31.997764600 +0000
+++ sandbox/policy/win/sandbox_win.h
@@ -52,7 +52,7 @@ class SANDBOX_POLICY_EXPORT SandboxWin {
   // Otherwise, returns one of sandbox::ResultCode for any other error.
   static ResultCode StartSandboxedProcess(
       const base::CommandLine& cmd_line,
-      const base::HandlesToInheritVector& handles_to_inherit,
+      const base::LaunchOptions* options,
       SandboxDelegate* delegate,
       base::Process* process);
 
@@ -65,7 +65,7 @@ class SANDBOX_POLICY_EXPORT SandboxWin {
   // of sandbox::ResultCode for any other error while constructing the policy.
   static ResultCode GeneratePolicyForSandboxedProcess(
       const base::CommandLine& cmd_line,
-      const base::HandlesToInheritVector& handles_to_inherit,
+      const base::LaunchOptions* options,
       SandboxDelegate* delegate,
       TargetPolicy* policy);
 
