$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/device_identity/device_oauth2_token_service_factory.cc.orig	2024-07-24 02:44:26.995847500 +0000
+++ chrome/browser/device_identity/device_oauth2_token_service_factory.cc
@@ -28,7 +28,7 @@ std::unique_ptr<DeviceOAuth2TokenStore> 
   return std::make_unique<chromeos::DeviceOAuth2TokenStoreChromeOS>(
       local_state);
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
   return std::make_unique<DeviceOAuth2TokenStoreDesktop>(local_state);
 #else
   NOTREACHED_IN_MIGRATION();
