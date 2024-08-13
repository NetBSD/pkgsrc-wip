$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/browser_management/browser_management_service.h.orig	2024-08-06 19:52:14.873088600 +0000
+++ chrome/browser/enterprise/browser_management/browser_management_service.h
@@ -28,7 +28,7 @@ class BrowserManagementMetadata {
 
   const gfx::Image& GetManagementLogo() const;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
  private:
   void UpdateManagementLogo(Profile* profile);
   void SetManagementLogo(
