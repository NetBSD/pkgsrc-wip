$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/utility_sandbox_delegate.h.orig	2024-10-18 12:34:14.010591500 +0000
+++ content/browser/utility_sandbox_delegate.h
@@ -30,7 +30,9 @@ class CONTENT_EXPORT UtilitySandboxedPro
  public:
   UtilitySandboxedProcessLauncherDelegate(sandbox::mojom::Sandbox sandbox_type,
                                           const base::EnvironmentMap& env,
-                                          const base::CommandLine& cmd_line);
+                                          const base::FilePath& cwd,
+                                          const base::CommandLine& cmd_line,
+                                          bool inherit_environment);
   ~UtilitySandboxedProcessLauncherDelegate() override;
 
   sandbox::mojom::Sandbox GetSandboxType() override;
@@ -56,18 +58,16 @@ class CONTENT_EXPORT UtilitySandboxedPro
   ZygoteCommunication* GetZygote() override;
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
-#if BUILDFLAG(IS_POSIX)
   base::EnvironmentMap GetEnvironment() override;
-#endif  // BUILDFLAG(IS_POSIX)
+  bool ShouldInheritEnvironment() override;
+  base::FilePath GetCurrentDirectory() override;
 
 #if BUILDFLAG(USE_ZYGOTE)
   void SetZygote(ZygoteCommunication* handle);
 #endif  // BUILDFLAG(USE_ZYGOTE_HANDLE)
 
  private:
-#if BUILDFLAG(IS_POSIX)
   base::EnvironmentMap env_;
-#endif  // BUILDFLAG(IS_POSIX)
 
 #if BUILDFLAG(IS_WIN)
   std::vector<base::FilePath> preload_libraries_;
@@ -77,12 +77,14 @@ class CONTENT_EXPORT UtilitySandboxedPro
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
 };
 }  // namespace content
 
