$NetBSD$

--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -310,7 +310,7 @@ void ChromeBrowserMainExtraPartsProfiles
   media_router::MediaRouterUIServiceFactory::GetInstance();
 #endif
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
   ModelTypeStoreServiceFactory::GetInstance();
