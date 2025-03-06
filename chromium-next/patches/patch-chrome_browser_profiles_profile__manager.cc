$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/profiles/profile_manager.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ chrome/browser/profiles/profile_manager.cc
@@ -1500,7 +1500,7 @@ void ProfileManager::DoFinalInitForServi
   // Ensure PreloadingModelKeyedService is started.
   PreloadingModelKeyedServiceFactory::GetForProfile(profile);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   contextual_cueing::ContextualCueingServiceFactory::GetForProfile(profile);
 #endif
 
