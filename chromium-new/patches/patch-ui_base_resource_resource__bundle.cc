$NetBSD$

--- ui/base/resource/resource_bundle.cc.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/base/resource/resource_bundle.cc
@@ -638,7 +638,7 @@ void ResourceBundle::ReloadFonts() {
 }
 
 ScaleFactor ResourceBundle::GetMaxScaleFactor() const {
-#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   return max_scale_factor_;
 #else
   return GetSupportedScaleFactors().back();
@@ -698,7 +698,7 @@ void ResourceBundle::InitSharedInstance(
     supported_scale_factors.push_back(SCALE_FACTOR_100P);
   }
 #elif defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   supported_scale_factors.push_back(SCALE_FACTOR_200P);
 #endif
   ui::SetSupportedScaleFactors(supported_scale_factors);
