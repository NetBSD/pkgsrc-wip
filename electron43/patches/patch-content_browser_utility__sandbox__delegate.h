$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/utility_sandbox_delegate.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/utility_sandbox_delegate.h
@@ -34,7 +34,9 @@ class CONTENT_EXPORT UtilitySandboxedPro
  public:
   UtilitySandboxedProcessLauncherDelegate(sandbox::mojom::Sandbox sandbox_type,
                                           const base::EnvironmentMap& env,
-                                          const base::CommandLine& cmd_line);
+                                          const base::FilePath& cwd,
+                                          const base::CommandLine& cmd_line,
+                                          bool inherit_environment);
   ~UtilitySandboxedProcessLauncherDelegate() override;
 
   sandbox::mojom::Sandbox GetSandboxType() override;
@@ -59,9 +61,14 @@ class CONTENT_EXPORT UtilitySandboxedPro
   ZygoteCommunication* GetZygote() override;
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
-#if BUILDFLAG(IS_POSIX)
   base::EnvironmentMap GetEnvironment() override;
-#endif  // BUILDFLAG(IS_POSIX)
+  bool ShouldInheritEnvironment() override;
+  base::FilePath GetCurrentDirectory() override;
+
+#if BUILDFLAG(IS_WIN)
+  void SetFeedbackCursorOff(bool feedback_cursor_off);
+  bool ShouldShowFeedbackCursor() override;
+#endif  // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(USE_ZYGOTE)
   void SetZygote(ZygoteCommunication* handle);
@@ -72,9 +79,7 @@ class CONTENT_EXPORT UtilitySandboxedPro
 #endif  // BUILDFLAG(IS_MAC)
 
  private:
-#if BUILDFLAG(IS_POSIX)
   base::EnvironmentMap env_;
-#endif  // BUILDFLAG(IS_POSIX)
 
 #if BUILDFLAG(IS_WIN)
   std::vector<base::FilePath> preload_libraries_;
@@ -84,12 +89,17 @@ class CONTENT_EXPORT UtilitySandboxedPro
   std::optional<raw_ptr<ZygoteCommunication>> zygote_;
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
+  base::FilePath current_directory_;
   const sandbox::mojom::Sandbox sandbox_type_;
 #if BUILDFLAG(IS_WIN)
   // If true then App Container will not be used for this utility process.
   const bool app_container_disabled_;
 #endif  // BUILDFLAG(IS_WIN)
   base::CommandLine cmd_line_;
+  bool inherit_environment_;
+#if BUILDFLAG(IS_WIN)
+  bool feedback_cursor_off_ = false;
+#endif  // BUILDFLAG(IS_WIN)
 };
 }  // namespace content
 
