$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/visited_url_ranking/public/url_visit_util.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ components/visited_url_ranking/public/url_visit_util.cc
@@ -68,7 +68,7 @@ PlatformType GetPlatformInput() {
   return PlatformType::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return PlatformType::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return PlatformType::kLinux;
 #elif BUILDFLAG(IS_IOS)
   return PlatformType::kIos;
