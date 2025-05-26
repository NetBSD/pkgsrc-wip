$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/utility_sandbox_delegate.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/utility_sandbox_delegate.cc
@@ -41,17 +41,19 @@ UtilitySandboxedProcessLauncherDelegate:
     UtilitySandboxedProcessLauncherDelegate(
         sandbox::mojom::Sandbox sandbox_type,
         const base::EnvironmentMap& env,
-        const base::CommandLine& cmd_line)
+        const base::FilePath& cwd,
+        const base::CommandLine& cmd_line,
+        bool inherit_environment)
     :
-#if BUILDFLAG(IS_POSIX)
       env_(env),
-#endif
+      current_directory_(cwd),
       sandbox_type_(sandbox_type),
 #if BUILDFLAG(IS_WIN)
       app_container_disabled_(
           GetContentClient()->browser()->IsAppContainerDisabled(sandbox_type)),
 #endif
-      cmd_line_(cmd_line) {
+      cmd_line_(cmd_line),
+      inherit_environment_(inherit_environment) {
 #if DCHECK_IS_ON()
   bool supported_sandbox_type =
       sandbox_type_ == sandbox::mojom::Sandbox::kNoSandbox ||
@@ -83,10 +85,10 @@ UtilitySandboxedProcessLauncherDelegate:
 #if BUILDFLAG(IS_FUCHSIA)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoCapture ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoEncoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -100,10 +102,10 @@ UtilitySandboxedProcessLauncherDelegate:
 #if BUILDFLAG(ENABLE_SCREEN_AI_SERVICE)
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoEffects ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceTranslation ||
 #endif
       sandbox_type_ == sandbox::mojom::Sandbox::kAudio ||
@@ -120,11 +122,28 @@ UtilitySandboxedProcessLauncherDelegate:
   return sandbox_type_;
 }
 
-#if BUILDFLAG(IS_POSIX)
 base::EnvironmentMap UtilitySandboxedProcessLauncherDelegate::GetEnvironment() {
   return env_;
 }
-#endif  // BUILDFLAG(IS_POSIX)
+
+bool UtilitySandboxedProcessLauncherDelegate::ShouldInheritEnvironment() {
+  return inherit_environment_;
+}
+
+base::FilePath UtilitySandboxedProcessLauncherDelegate::GetCurrentDirectory() {
+  return current_directory_;
+}
+
+#if BUILDFLAG(IS_WIN)
+void UtilitySandboxedProcessLauncherDelegate::SetFeedbackCursorOff(
+    bool feedback_cursor_off) {
+  feedback_cursor_off_ = feedback_cursor_off;
+}
+
+bool UtilitySandboxedProcessLauncherDelegate::ShouldShowFeedbackCursor() {
+  return !feedback_cursor_off_;
+}
+#endif  // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(USE_ZYGOTE)
 ZygoteCommunication* UtilitySandboxedProcessLauncherDelegate::GetZygote() {
@@ -149,10 +168,10 @@ ZygoteCommunication* UtilitySandboxedPro
   // process upon startup.
   if (sandbox_type_ == sandbox::mojom::Sandbox::kNetwork ||
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceModelExecution ||
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoEncoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -170,7 +189,7 @@ ZygoteCommunication* UtilitySandboxedPro
 #if BUILDFLAG(ENABLE_SCREEN_AI_SERVICE)
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoEffects ||
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceTranslation ||
 #endif  // BUILDFLAG(IS_LINUX)
