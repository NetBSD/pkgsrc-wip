$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/service_process_host.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/browser/service_process_host.h
@@ -14,6 +14,7 @@
 #include "base/command_line.h"
 #include "base/functional/callback.h"
 #include "base/observer_list_types.h"
+#include "base/process/launch.h"
 #include "base/process/process_handle.h"
 #include "content/common/content_export.h"
 #include "content/public/browser/service_process_info.h"
@@ -28,6 +29,10 @@
 #include "base/types/pass_key.h"
 #endif  // BUILDFLAG(IS_WIN)
 
+#if BUILDFLAG(IS_WIN)
+#include "base/win/scoped_handle.h"
+#endif
+
 namespace base {
 class Process;
 }  // namespace base
@@ -94,11 +99,35 @@ class CONTENT_EXPORT ServiceProcessHost 
     // Specifies extra command line switches to append before launch.
     Options& WithExtraCommandLineSwitches(std::vector<std::string> switches);
 
+#if BUILDFLAG(IS_WIN)
+    // Specifies the handles for redirection of stdout and stderr.
+    Options& WithStdoutHandle(base::win::ScopedHandle stdout_handle);
+    Options& WithStderrHandle(base::win::ScopedHandle stderr_handle);
+#elif BUILDFLAG(IS_POSIX)
+    // Specifies file descriptors to propagate into the child process
+    // based on the mapping.
+    Options& WithAdditionalFds(base::FileHandleMappingVector mapping);
+#endif
+
     // Specifies a callback to be invoked with service process once it's
     // launched. Will be on UI thread.
     Options& WithProcessCallback(
         base::OnceCallback<void(const base::Process&)>);
 
+    // Specifies the working directory for the launched process.
+    Options& WithCurrentDirectory(const base::FilePath& cwd);
+
+    // Specifies the environment that should be applied to the process.
+    // |new_environment| controls whether the process should inherit
+    // environment from the parent process.
+    Options& WithEnvironment(const base::EnvironmentMap& environment,
+                             bool new_environment);
+
+#if BUILDFLAG(IS_WIN)
+    // Specifies if the process should trigger mouse cursor feedback.
+    Options& WithFeedbackCursorOff(bool feedback_cursor_off);
+#endif  // #if BUILDFLAG(IS_WIN)
+
 #if BUILDFLAG(IS_WIN)
     // Specifies libraries to preload before the sandbox is locked down. Paths
     // should be absolute paths. Libraries will be preloaded before sandbox
@@ -127,11 +156,23 @@ class CONTENT_EXPORT ServiceProcessHost 
     std::optional<GURL> site;
     std::optional<int> child_flags;
     std::vector<std::string> extra_switches;
+#if BUILDFLAG(IS_WIN)
+    base::win::ScopedHandle stdout_handle;
+    base::win::ScopedHandle stderr_handle;
+#elif BUILDFLAG(IS_POSIX)
+    base::FileHandleMappingVector fds_to_remap;
+#endif
     base::OnceCallback<void(const base::Process&)> process_callback;
 #if BUILDFLAG(IS_WIN)
     std::vector<base::FilePath> preload_libraries;
 #endif  // BUILDFLAG(IS_WIN)
     std::optional<bool> allow_gpu_client;
+    base::FilePath current_directory;
+    base::EnvironmentMap environment;
+    bool clear_environment = false;
+#if BUILDFLAG(IS_WIN)
+    bool feedback_cursor_off = false;
+#endif  // BUILDFLAG(IS_WIN)
   };
 
   // An interface which can be implemented and registered/unregistered with
