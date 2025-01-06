$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/web_applications/os_integration/os_integration_test_override.h.orig	2024-10-18 12:34:03.740060000 +0000
+++ chrome/browser/web_applications/os_integration/os_integration_test_override.h
@@ -99,7 +99,7 @@ class OsIntegrationTestOverride
   virtual base::FilePath chrome_apps_folder() = 0;
   virtual void EnableOrDisablePathOnLogin(const base::FilePath& file_path,
                                           bool enable_on_login) = 0;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual base::Environment* environment() = 0;
 #endif
 
