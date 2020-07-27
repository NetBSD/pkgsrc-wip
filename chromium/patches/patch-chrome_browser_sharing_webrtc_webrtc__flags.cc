$NetBSD$

--- chrome/browser/sharing/webrtc/webrtc_flags.cc.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/sharing/webrtc/webrtc_flags.cc
@@ -5,7 +5,7 @@
 #include "chrome/browser/sharing/webrtc/webrtc_flags.h"
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const base::Feature kSharingPeerConnectionReceiver{
     "SharingPeerConnectionReceiver", base::FEATURE_DISABLED_BY_DEFAULT};
 
