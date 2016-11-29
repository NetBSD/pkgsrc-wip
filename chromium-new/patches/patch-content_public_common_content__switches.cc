$NetBSD$

--- content/public/common/content_switches.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/public/common/content_switches.cc
@@ -1007,7 +1007,7 @@ const char kDisableVaapiAcceleratedVideo
     "disable-vaapi-accelerated-video-encode";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
