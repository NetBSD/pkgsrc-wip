$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/passwords/bubble_controllers/relaunch_chrome_bubble_controller.cc.orig	2024-07-24 02:44:29.608100700 +0000
+++ chrome/browser/ui/passwords/bubble_controllers/relaunch_chrome_bubble_controller.cc
@@ -44,7 +44,7 @@ std::u16string RelaunchChromeBubbleContr
 #if BUILDFLAG(IS_MAC)
           ? IDS_PASSWORD_MANAGER_RELAUNCH_CHROME_BUBBLE_TITLE_BRANDED
           : IDS_PASSWORD_MANAGER_RELAUNCH_CHROME_BUBBLE_TITLE_NON_BRANDED
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           ? IDS_PASSWORD_MANAGER_RELAUNCH_CHROME_BUBBLE_TITLE_LINUX_BRANDED
           : IDS_PASSWORD_MANAGER_RELAUNCH_CHROME_BUBBLE_TITLE_LINUX_NON_BRANDED
 #endif
@@ -57,7 +57,7 @@ std::u16string RelaunchChromeBubbleContr
 #if BUILDFLAG(IS_MAC)
           ? IDS_PASSWORD_MANAGER_RELAUNCH_CHROME_BUBBLE_DESCRIPTION_BRANDED
           : IDS_PASSWORD_MANAGER_RELAUNCH_CHROME_BUBBLE_DESCRIPTION_NON_BRANDED
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           ? IDS_PASSWORD_MANAGER_RELAUNCH_CHROME_BUBBLE_DESCRIPTION_LINUX_BRANDED
           : IDS_PASSWORD_MANAGER_RELAUNCH_CHROME_BUBBLE_DESCRIPTION_LINUX_NON_BRANDED
 #endif
