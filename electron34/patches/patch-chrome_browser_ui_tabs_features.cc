$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/tabs/features.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/tabs/features.cc
@@ -48,7 +48,7 @@ BASE_FEATURE(kTabStripCollectionStorage,
 bool CanShowTabSearchPositionSetting() {
 // Mac and other platforms will always have the tab search position in the
 // correct location, cros/linux/win git the user the option to change.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(kTabSearchPositionSetting);
 #else
   return false;
