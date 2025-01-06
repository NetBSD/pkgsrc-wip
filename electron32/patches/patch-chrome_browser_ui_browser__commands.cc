$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/browser_commands.cc.orig	2024-10-18 12:34:03.144388200 +0000
+++ chrome/browser/ui/browser_commands.cc
@@ -2005,7 +2005,7 @@ void OpenUpdateChromeDialog(Browser* bro
   } else if (UpgradeDetector::GetInstance()->is_outdated_install_no_au()) {
     UpgradeDetector::GetInstance()->NotifyOutdatedInstallNoAutoUpdate();
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kFewerUpdateConfirmations)) {
       chrome::AttemptRelaunch();
       return;
