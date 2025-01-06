$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/utility_sandbox_delegate.cc.orig	2024-10-18 12:34:14.010591500 +0000
+++ content/browser/utility_sandbox_delegate.cc
@@ -34,17 +34,19 @@ UtilitySandboxedProcessLauncherDelegate:
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
@@ -76,10 +78,10 @@ UtilitySandboxedProcessLauncherDelegate:
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
@@ -107,11 +109,17 @@ UtilitySandboxedProcessLauncherDelegate:
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
 
 #if BUILDFLAG(USE_ZYGOTE)
 ZygoteCommunication* UtilitySandboxedProcessLauncherDelegate::GetZygote() {
@@ -136,10 +144,10 @@ ZygoteCommunication* UtilitySandboxedPro
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
