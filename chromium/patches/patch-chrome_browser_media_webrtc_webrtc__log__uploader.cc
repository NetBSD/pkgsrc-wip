$NetBSD$

--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2020-07-24 02:37:47.000000000 +0000
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -354,6 +354,8 @@ void WebRtcLogUploader::SetupMultipart(
 #else
   const char product[] = "Chrome_Linux_ASan";
 #endif
+#elif defined(OS_NETBSD)
+  const char product[] = "Chrome_NetBSD";
 #elif defined(OS_ANDROID)
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
