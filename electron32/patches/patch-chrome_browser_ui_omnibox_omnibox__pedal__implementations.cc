$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2024-10-18 12:34:03.180368400 +0000
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -1976,7 +1976,7 @@ const gfx::VectorIcon& GetSharingHubVect
   return omnibox::kShareMacChromeRefreshIcon;
 #elif BUILDFLAG(IS_WIN)
   return omnibox::kShareWinChromeRefreshIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return omnibox::kShareLinuxChromeRefreshIcon;
 #else
   return omnibox::kShareChromeRefreshIcon;
