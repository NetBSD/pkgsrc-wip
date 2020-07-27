$NetBSD$

--- chromecast/browser/tts/tts_controller_impl.cc.orig	2020-07-08 21:40:38.000000000 +0000
+++ chromecast/browser/tts/tts_controller_impl.cc
@@ -390,7 +390,11 @@ int TtsControllerImpl::QueueSize() {
 }
 
 TtsPlatformImpl* TtsControllerImpl::GetPlatformImpl() {
+#if defined(OS_BSD)
+  return NULL;
+#else
   return platform_impl_.get();
+#endif
 }
 
 std::string TtsControllerImpl::GetApplicationLocale() const {
