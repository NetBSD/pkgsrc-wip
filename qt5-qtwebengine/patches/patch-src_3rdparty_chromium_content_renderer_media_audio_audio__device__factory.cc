$NetBSD$

--- src/3rdparty/chromium/content/renderer/media/audio/audio_device_factory.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/renderer/media/audio/audio_device_factory.cc
@@ -37,7 +37,7 @@ AudioDeviceFactory* AudioDeviceFactory::
 namespace {
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 // Due to driver deadlock issues on Windows (http://crbug/422522) there is a
 // chance device authorization response is never received from the browser side.
 // In this case we will time out, to avoid renderer hang forever waiting for
