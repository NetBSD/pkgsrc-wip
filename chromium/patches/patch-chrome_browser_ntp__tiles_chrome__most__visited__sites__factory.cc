$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc
@@ -56,7 +56,7 @@ bool ShouldCreateCustomLinksManager() {
 
 bool ShouldCreateEnterpriseShortcutsManager() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(ntp_tiles::kNtpEnterpriseShortcuts);
 #else
   return false;
