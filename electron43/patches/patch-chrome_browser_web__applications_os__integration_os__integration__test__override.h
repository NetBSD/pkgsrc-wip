$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/web_applications/os_integration/os_integration_test_override.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/web_applications/os_integration/os_integration_test_override.h
@@ -99,7 +99,7 @@ class OsIntegrationTestOverride
   virtual base::FilePath chrome_apps_folder() = 0;
   virtual void EnableOrDisablePathOnLogin(const base::FilePath& file_path,
                                           bool enable_on_login) = 0;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual base::Environment* environment() = 0;
 #endif
 
