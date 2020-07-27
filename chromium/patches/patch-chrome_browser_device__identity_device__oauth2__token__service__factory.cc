$NetBSD$

--- chrome/browser/device_identity/device_oauth2_token_service_factory.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/device_identity/device_oauth2_token_service_factory.cc
@@ -28,7 +28,7 @@ std::unique_ptr<DeviceOAuth2TokenStore> 
 #if defined(OS_CHROMEOS)
   return std::make_unique<chromeos::DeviceOAuth2TokenStoreChromeOS>(
       local_state);
-#elif defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#elif defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   DCHECK(
       base::FeatureList::IsEnabled(policy::features::kCBCMPolicyInvalidations));
   return std::make_unique<DeviceOAuth2TokenStoreDesktop>(local_state);
