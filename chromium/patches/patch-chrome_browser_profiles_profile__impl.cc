$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/profiles/profile_impl.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/profiles/profile_impl.cc
@@ -269,6 +269,10 @@
 #include "chrome/browser/safe_browsing/safe_browsing_service.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif
+
 using bookmarks::BookmarkModel;
 using content::BrowserThread;
 using content::DownloadManagerDelegate;
@@ -593,7 +597,7 @@ void ProfileImpl::LoadPrefsForNormalStar
   policy_provider = GetUserCloudPolicyManagerAsh();
 #else  // !BUILDFLAG(IS_CHROMEOS)
   {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     ProfileManager* profile_manager = g_browser_process->profile_manager();
     ProfileAttributesEntry* entry =
         profile_manager->GetProfileAttributesStorage()
@@ -889,7 +893,17 @@ void ProfileImpl::DoFinalInit(CreateMode
 }
 
 base::FilePath ProfileImpl::last_selected_directory() {
+#if BUILDFLAG(IS_OPENBSD)
+  // If unveil(2) is used, force the file dialog directory to something we
+  // know is available.
+  auto* sandbox = sandbox::policy::SandboxLinux::GetInstance();
+  if (sandbox->unveil_initialized())
+    return GetPrefs()->GetFilePath(prefs::kDownloadDefaultDirectory);
+  else
+    return GetPrefs()->GetFilePath(prefs::kSelectFileLastDirectory);
+#else
   return GetPrefs()->GetFilePath(prefs::kSelectFileLastDirectory);
+#endif
 }
 
 void ProfileImpl::set_last_selected_directory(const base::FilePath& path) {
