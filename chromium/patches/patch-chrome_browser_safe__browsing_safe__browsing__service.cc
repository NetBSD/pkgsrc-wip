$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/safe_browsing/safe_browsing_service.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/safe_browsing/safe_browsing_service.cc
@@ -80,7 +80,7 @@
 #include "services/preferences/public/mojom/tracked_preference_validation_delegate.mojom.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/safe_browsing/security_settings_bundle_toast_helper.h"
 #endif
 
@@ -186,7 +186,7 @@ void TriggerSecuritySettingsBundleToastI
   }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (GetSecurityBundleSetting(*profile->GetPrefs()) ==
       SecuritySettingsBundleSetting::ENHANCED) {
     SecuritySettingsBundleToastHelper::GetForProfile(profile.get())
