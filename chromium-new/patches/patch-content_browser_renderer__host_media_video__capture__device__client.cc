$NetBSD$

--- content/browser/renderer_host/media/video_capture_device_client.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/renderer_host/media/video_capture_device_client.cc
@@ -186,7 +186,7 @@ void VideoCaptureDeviceClient::OnIncomin
       // see http://linuxtv.org/downloads/v4l-dvb-apis/packed-rgb.html.
       // Windows RGB24 defines blue at lowest byte,
       // see https://msdn.microsoft.com/en-us/library/windows/desktop/dd407253
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       origin_colorspace = libyuv::FOURCC_RAW;
 #elif defined(OS_WIN)
       origin_colorspace = libyuv::FOURCC_24BG;
