$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/utility_process_host.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/utility_process_host.h
@@ -30,6 +30,10 @@
 #include "content/public/common/zygote/zygote_handle.h"
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
+#if BUILDFLAG(IS_WIN)
+#include "base/win/scoped_handle.h"
+#endif
+
 namespace base {
 class Thread;
 }  // namespace base
@@ -75,7 +79,7 @@ class CONTENT_EXPORT UtilityProcessHost
 
     virtual void OnProcessLaunched(const base::Process& process) {}
     virtual void OnProcessTerminatedNormally() {}
-    virtual void OnProcessCrashed() {}
+    virtual void OnProcessCrashed(int exit_code) {}
   };
 
   // This class is self-owned. It must be instantiated using new, and shouldn't
@@ -99,9 +103,13 @@ class CONTENT_EXPORT UtilityProcessHost
 
   // Returns information about the utility child process.
   const ChildProcessData& GetData();
-#if BUILDFLAG(IS_POSIX)
+
+  // Set/Unset environment variables.
   void SetEnv(const base::EnvironmentMap& env);
-#endif
+
+  // Clear the environment for the new process before processing
+  // changes from SetEnv.
+  void ClearEnvironment();
 
   // Starts the utility process.
   bool Start();
@@ -139,6 +147,21 @@ class CONTENT_EXPORT UtilityProcessHost
   void SetZygoteForTesting(ZygoteCommunication* handle);
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
+#if BUILDFLAG(IS_WIN)
+  void SetStdioHandles(base::win::ScopedHandle stdout_handle,
+                       base::win::ScopedHandle stderr_handle);
+#elif BUILDFLAG(IS_POSIX)
+  void SetAdditionalFds(base::FileHandleMappingVector mapping);
+#endif
+
+  // Sets the working directory of the process.
+  void SetCurrentDirectory(const base::FilePath& cwd);
+
+#if BUILDFLAG(IS_WIN)
+  // Specifies if the process should trigger mouse cursor feedback.
+  void SetFeedbackCursorOff(bool feedback_cursor_off);
+#endif  // BUILDFLAG(IS_WIN)
+
   // Returns a control interface for the running child process.
   mojom::ChildProcess* GetChildProcess();
 
@@ -192,6 +215,27 @@ class CONTENT_EXPORT UtilityProcessHost
   std::optional<raw_ptr<ZygoteCommunication>> zygote_for_testing_;
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
+#if BUILDFLAG(IS_WIN)
+  // Specifies the handles for redirection of stdout and stderr.
+  base::win::ScopedHandle stdout_handle_;
+  base::win::ScopedHandle stderr_handle_;
+#elif BUILDFLAG(IS_POSIX)
+  // Specifies file descriptors to propagate into the child process
+  // based on the mapping.
+  base::FileHandleMappingVector fds_to_remap_;
+#endif
+
+  // If not empty, change to this directory before executing the new process.
+  base::FilePath current_directory_;
+
+  // Inherit enviroment from parent process.
+  bool inherit_environment_ = true;
+
+#if BUILDFLAG(IS_WIN)
+  // Specifies if the process should trigger mouse cursor feedback.
+  bool feedback_cursor_off_ = false;
+#endif  // BUILDFLAG(IS_WIN)
+
   // Indicates whether the process has been successfully launched yet, or if
   // launch failed.
   enum class LaunchState {
