$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/searchbox/searchbox_handler.cc.orig	2025-05-30 19:50:32.000000000 +0000
+++ chrome/browser/ui/webui/searchbox/searchbox_handler.cc
@@ -118,7 +118,7 @@ const char* kMacShareIconResourceName =
 #elif BUILDFLAG(IS_WIN)
 const char* kWinShareIconResourceName =
     "//resources/cr_components/searchbox/icons/win_share.svg";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char* kLinuxShareIconResourceName =
     "//resources/cr_components/searchbox/icons/share.svg";
 #else
@@ -178,7 +178,7 @@ static void DefineChromeRefreshRealboxIc
 #elif BUILDFLAG(IS_WIN)
   kWinShareIconResourceName =
       "//resources/cr_components/searchbox/icons/win_share_cr23.svg";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   kLinuxShareIconResourceName =
       "//resources/cr_components/searchbox/icons/share_cr23.svg";
 #else
@@ -622,7 +622,7 @@ std::string SearchboxHandler::ActionVect
       icon.name == omnibox::kShareWinChromeRefreshIcon.name) {
     return kWinShareIconResourceName;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (icon.name == omnibox::kShareIcon.name ||
       icon.name == omnibox::kShareLinuxChromeRefreshIcon.name) {
     return kLinuxShareIconResourceName;
