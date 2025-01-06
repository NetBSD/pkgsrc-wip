$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/global_desktop_features.cc.orig	2024-10-18 12:34:01.621233500 +0000
+++ chrome/browser/global_desktop_features.cc
@@ -45,14 +45,14 @@ void GlobalDesktopFeatures::ReplaceGloba
 }
 
 void GlobalDesktopFeatures::Init() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (user_education::features::IsWhatsNewV2()) {
     whats_new_registry_ = CreateWhatsNewRegistry();
   }
 #endif
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<whats_new::WhatsNewRegistry>
 GlobalDesktopFeatures::CreateWhatsNewRegistry() {
   return whats_new::CreateWhatsNewRegistry();
