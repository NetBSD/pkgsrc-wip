$NetBSD$

--- chromecast/browser/cast_content_browser_client.cc.orig	2020-07-08 21:40:38.000000000 +0000
+++ chromecast/browser/cast_content_browser_client.cc
@@ -475,7 +475,7 @@ void CastContentBrowserClient::AppendExt
                                           switches::kAudioOutputChannels));
     }
   } else if (process_type == switches::kGpuProcess) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Necessary for accelerated 2d canvas.  By default on Linux, Chromium
     // assumes GLES2 contexts can be lost to a power-save mode, which breaks GPU
     // canvas apps.
