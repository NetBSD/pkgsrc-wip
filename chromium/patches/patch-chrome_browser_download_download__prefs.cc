$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/download/download_prefs.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/download/download_prefs.cc
@@ -11,6 +11,7 @@
 #include <vector>
 
 #include "base/check.h"
+#include "base/command_line.h"
 #include "base/feature_list.h"
 #include "base/files/file_util.h"
 #include "base/functional/bind.h"
@@ -61,6 +62,10 @@
 #include "components/safe_browsing/content/common/file_type_policies.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif
+
 using content::BrowserContext;
 using content::BrowserThread;
 using content::DownloadManager;
@@ -74,7 +79,7 @@ namespace {
 // Consider downloads 'dangerous' if they go to the home directory on Linux and
 // to the desktop on any platform.
 bool DownloadPathIsDangerous(const base::FilePath& download_path) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::FilePath home_dir = base::GetHomeDir();
   if (download_path == home_dir) {
     return true;
@@ -180,7 +185,7 @@ DownloadPrefs::DownloadPrefs(Profile* pr
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   should_open_pdf_in_system_reader_ =
       prefs->GetBoolean(prefs::kOpenPdfDownloadInSystemReader);
 #endif
@@ -307,7 +312,7 @@ void DownloadPrefs::RegisterProfilePrefs
   registry->RegisterFilePathPref(prefs::kSaveFileDefaultDirectory,
                                  default_download_path);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kOpenPdfDownloadInSystemReader, false);
 #endif
 #if BUILDFLAG(IS_ANDROID)
@@ -480,7 +485,7 @@ void DownloadPrefs::DisableAutoOpenByUse
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 void DownloadPrefs::SetShouldOpenPdfInSystemReader(bool should_open) {
   if (should_open_pdf_in_system_reader_ == should_open)
     return;
@@ -506,7 +511,7 @@ bool DownloadPrefs::ShouldOpenPdfInSyste
 
 void DownloadPrefs::ResetAutoOpenByUser() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   SetShouldOpenPdfInSystemReader(false);
 #endif
   auto_open_by_user_.clear();
@@ -543,7 +548,7 @@ void DownloadPrefs::SaveAutoOpenState() 
 bool DownloadPrefs::CanPlatformEnableAutoOpenForPdf() const {
 #if BUILDFLAG(IS_CHROMEOS)
   return false;  // There is no UI for auto-open on ChromeOS.
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return ShouldOpenPdfInSystemReader();
 #else
   return false;
@@ -625,7 +630,14 @@ base::FilePath DownloadPrefs::SanitizeDo
 #else
   // If the stored download directory is an absolute path, we presume it's
   // correct; there's not really much more validation we can do here.
+#if BUILDFLAG(IS_OPENBSD)
+  // If unveil(2) is used, force the file dialog directory to something we
+  // know is available.
+  auto* sandbox = sandbox::policy::SandboxLinux::GetInstance();
+  if (!sandbox->unveil_initialized() && path.IsAbsolute())
+#else
   if (path.IsAbsolute())
+#endif
     return path;
 
   // When the default download directory is *not* an absolute path, we use the
