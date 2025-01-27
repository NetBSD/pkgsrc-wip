$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/permissions/prediction_service/prediction_common.cc.orig	2025-01-07 19:49:01.000000000 +0000
+++ components/permissions/prediction_service/prediction_common.cc
@@ -33,7 +33,7 @@ int BucketizeValue(int count) {
 
 ClientFeatures_Platform GetCurrentPlatformProto() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return permissions::ClientFeatures_Platform_PLATFORM_DESKTOP;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
   return permissions::ClientFeatures_Platform_PLATFORM_MOBILE;
@@ -44,7 +44,7 @@ ClientFeatures_Platform GetCurrentPlatfo
 
 ClientFeatures_PlatformEnum GetCurrentPlatformEnumProto() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return permissions::ClientFeatures_PlatformEnum_PLATFORM_DESKTOP_V2;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
   return permissions::ClientFeatures_PlatformEnum_PLATFORM_MOBILE_V2;
