$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/background/background_mode_optimizer.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ chrome/browser/background/background_mode_optimizer.cc
@@ -31,7 +31,7 @@ std::unique_ptr<BackgroundModeOptimizer>
     return nullptr;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kBackgroundModeAllowRestart)) {
     // Private ctor.
     return base::WrapUnique(new BackgroundModeOptimizer());
