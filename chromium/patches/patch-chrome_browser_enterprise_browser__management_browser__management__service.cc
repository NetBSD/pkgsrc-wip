$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/browser_management/browser_management_service.cc.orig	2024-07-24 02:44:27.087856500 +0000
+++ chrome/browser/enterprise/browser_management/browser_management_service.cc
@@ -21,7 +21,7 @@ namespace policy {
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void UpdateEnterpriseLogo(
     Profile* profile,
     base::OnceCallback<void(const gfx::Image&,
@@ -98,7 +98,7 @@ GetManagementStatusProviders(Profile* pr
 }  // namespace
 
 BrowserManagementMetadata::BrowserManagementMetadata(Profile* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   UpdateManagementLogo(profile);
   pref_change_registrar_.Init(profile->GetPrefs());
   pref_change_registrar_.Add(
@@ -114,7 +114,7 @@ const gfx::Image& BrowserManagementMetad
   return management_logo_;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BrowserManagementMetadata::UpdateManagementLogo(Profile* profile) {
   UpdateEnterpriseLogo(
       profile, base::BindOnce(&BrowserManagementMetadata::SetManagementLogo,
