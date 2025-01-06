$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/utility_process_host.h.orig	2024-10-18 12:34:14.010591500 +0000
+++ content/browser/utility_process_host.h
@@ -29,11 +29,15 @@
 #include "content/public/common/zygote/zygote_handle.h"
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
+#if BUILDFLAG(IS_WIN)
+#include "base/win/scoped_handle.h"
+#endif
+
 namespace base {
 class Thread;
 }  // namespace base
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 namespace viz {
 class GpuClient;
 }  // namespace viz
@@ -74,7 +78,7 @@ class CONTENT_EXPORT UtilityProcessHost
 
     virtual void OnProcessLaunched(const base::Process& process) {}
     virtual void OnProcessTerminatedNormally() {}
-    virtual void OnProcessCrashed() {}
+    virtual void OnProcessCrashed(int exit_code) {}
   };
 
   // This class is self-owned. It must be instantiated using new, and shouldn't
@@ -98,9 +102,13 @@ class CONTENT_EXPORT UtilityProcessHost
 
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
@@ -138,6 +146,16 @@ class CONTENT_EXPORT UtilityProcessHost
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
   // Returns a control interface for the running child process.
   mojom::ChildProcess* GetChildProcess();
 
@@ -191,6 +209,22 @@ class CONTENT_EXPORT UtilityProcessHost
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
   // Indicates whether the process has been successfully launched yet, or if
   // launch failed.
   enum class LaunchState {
@@ -200,7 +234,7 @@ class CONTENT_EXPORT UtilityProcessHost
   };
   LaunchState launch_state_ = LaunchState::kLaunchInProgress;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   bool allowed_gpu_;
   std::unique_ptr<viz::GpuClient, base::OnTaskRunnerDeleter> gpu_client_;
 #endif
