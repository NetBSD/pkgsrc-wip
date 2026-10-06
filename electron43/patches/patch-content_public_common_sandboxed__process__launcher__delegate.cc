$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/common/sandboxed_process_launcher_delegate.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/common/sandboxed_process_launcher_delegate.cc
@@ -70,11 +70,23 @@ ZygoteCommunication* SandboxedProcessLau
 }
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
-#if BUILDFLAG(IS_POSIX)
 base::EnvironmentMap SandboxedProcessLauncherDelegate::GetEnvironment() {
   return base::EnvironmentMap();
 }
-#endif  // BUILDFLAG(IS_POSIX)
+
+bool SandboxedProcessLauncherDelegate::ShouldInheritEnvironment() {
+  return true;
+}
+
+base::FilePath SandboxedProcessLauncherDelegate::GetCurrentDirectory() {
+  return base::FilePath();
+}
+
+#if BUILDFLAG(IS_WIN)
+bool SandboxedProcessLauncherDelegate::ShouldShowFeedbackCursor() {
+  return true;
+}
+#endif  // #if BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_MAC)
 
