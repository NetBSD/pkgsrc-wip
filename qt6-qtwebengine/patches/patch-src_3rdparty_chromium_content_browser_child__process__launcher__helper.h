$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/child_process_launcher_helper.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/content/browser/child_process_launcher_helper.h
@@ -269,7 +269,7 @@ class ChildProcessLauncherHelper
   std::unique_ptr<SandboxedProcessLauncherDelegate> delegate_;
   base::WeakPtr<ChildProcessLauncher> child_process_launcher_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The priority of the process. The state is stored to avoid changing the
   // setting repeatedly.
   std::optional<base::Process::Priority> priority_;
