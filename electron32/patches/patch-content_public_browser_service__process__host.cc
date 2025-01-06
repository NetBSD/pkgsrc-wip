$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/service_process_host.cc.orig	2024-10-18 12:34:14.430375600 +0000
+++ content/public/browser/service_process_host.cc
@@ -52,12 +52,45 @@ ServiceProcessHost::Options::WithExtraCo
   return *this;
 }
 
+#if BUILDFLAG(IS_WIN)
+ServiceProcessHost::Options& ServiceProcessHost::Options::WithStdoutHandle(
+    base::win::ScopedHandle handle) {
+  stdout_handle = std::move(handle);
+  return *this;
+}
+
+ServiceProcessHost::Options& ServiceProcessHost::Options::WithStderrHandle(
+    base::win::ScopedHandle handle) {
+  stderr_handle = std::move(handle);
+  return *this;
+}
+#elif BUILDFLAG(IS_POSIX)
+ServiceProcessHost::Options& ServiceProcessHost::Options::WithAdditionalFds(
+    base::FileHandleMappingVector mapping) {
+  fds_to_remap = std::move(mapping);
+  return *this;
+}
+#endif
+
 ServiceProcessHost::Options& ServiceProcessHost::Options::WithProcessCallback(
     base::OnceCallback<void(const base::Process&)> callback) {
   process_callback = std::move(callback);
   return *this;
 }
 
+ServiceProcessHost::Options& ServiceProcessHost::Options::WithCurrentDirectory(
+    const base::FilePath& cwd) {
+  current_directory = cwd;
+  return *this;
+}
+
+ServiceProcessHost::Options& ServiceProcessHost::Options::WithEnvironment(
+    const base::EnvironmentMap& env, bool new_environment) {
+  environment = env;
+  clear_environment = new_environment;
+  return *this;
+}
+
 #if BUILDFLAG(IS_WIN)
 ServiceProcessHost::Options&
 ServiceProcessHost::Options::WithPreloadedLibraries(
@@ -70,7 +103,7 @@ ServiceProcessHost::Options::WithPreload
 
 ServiceProcessHost::Options& ServiceProcessHost::Options::WithGpuClient(
     base::PassKey<ServiceProcessHostGpuClient> passkey) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   allow_gpu_client = true;
 #endif
   return *this;
