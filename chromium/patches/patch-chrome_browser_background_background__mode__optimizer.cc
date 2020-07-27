$NetBSD$

--- chrome/browser/background/background_mode_optimizer.cc.orig	2020-07-08 21:40:33.000000000 +0000
+++ chrome/browser/background/background_mode_optimizer.cc
@@ -30,7 +30,7 @@ std::unique_ptr<BackgroundModeOptimizer>
           switches::kKeepAliveForTest))
     return nullptr;
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(features::kBackgroundModeAllowRestart))
     return base::WrapUnique(new BackgroundModeOptimizer());
 #endif  // defined(OS_WIN) || defined(OS_LINUX)
