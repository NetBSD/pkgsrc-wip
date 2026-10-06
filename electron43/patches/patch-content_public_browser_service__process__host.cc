$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/service_process_host.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/browser/service_process_host.cc
@@ -53,12 +53,53 @@ ServiceProcessHost::Options::WithExtraCo
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
+#if BUILDFLAG(IS_WIN)
+ServiceProcessHost::Options& ServiceProcessHost::Options::WithFeedbackCursorOff(
+    bool turn_feedback_cursor_off) {
+  feedback_cursor_off = turn_feedback_cursor_off;
+  return *this;
+}
+#endif  // #if BUILDFLAG(IS_WIN)
+
 #if BUILDFLAG(IS_WIN)
 ServiceProcessHost::Options&
 ServiceProcessHost::Options::WithPreloadedLibraries(
