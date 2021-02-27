$NetBSD$

--- src/modules/audio_device/audio_device_impl.cc.orig	2021-02-26 02:58:55.001895821 +0000
+++ src/modules/audio_device/audio_device_impl.cc
@@ -135,6 +135,9 @@ int32_t AudioDeviceModuleImpl::CheckPlat
 #elif defined(WEBRTC_LINUX)
   platform = kPlatformLinux;
   RTC_LOG(INFO) << "current platform is Linux";
+#elif defined(__NetBSD__)
+  platform = kPlatformNotSupported;
+  RTC_LOG(INFO) << "current platform is NetBSD";
 #elif defined(WEBRTC_IOS)
   platform = kPlatformIOS;
   RTC_LOG(INFO) << "current platform is IOS";
