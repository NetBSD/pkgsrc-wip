$NetBSD$

--- chrome/browser/media/webrtc_log_uploader.cc.orig	2016-11-10 20:02:10.000000000 +0000
+++ chrome/browser/media/webrtc_log_uploader.cc
@@ -344,6 +344,8 @@ void WebRtcLogUploader::SetupMultipart(
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
