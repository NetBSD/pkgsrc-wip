$NetBSD$

--- chrome/browser/sharing/webrtc/webrtc_flags.h.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/sharing/webrtc/webrtc_flags.h
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 // Feature flag to enable receiving PeerConnection requests.
 extern const base::Feature kSharingPeerConnectionReceiver;
 
