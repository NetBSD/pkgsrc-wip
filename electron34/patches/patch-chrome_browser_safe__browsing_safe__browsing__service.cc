$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/safe_browsing/safe_browsing_service.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/safe_browsing/safe_browsing_service.cc
@@ -83,7 +83,7 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/browser_window/public/browser_window_features.h"
 #include "chrome/browser/ui/toasts/api/toast_id.h"
@@ -554,7 +554,7 @@ base::CallbackListSubscription SafeBrows
 void SafeBrowsingServiceImpl::EnhancedProtectionPrefChange(Profile* profile) {
   RefreshState();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(safe_browsing::kEsbAsASyncedSetting) ||
       !profile) {
     return;
