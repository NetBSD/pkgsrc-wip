$NetBSD$

--- third_party/webrtc/voice_engine/voice_engine_defines.h.orig	2016-06-24 01:04:15.000000000 +0000
+++ third_party/webrtc/voice_engine/voice_engine_defines.h
@@ -210,7 +210,7 @@ inline int VoEChannelId(int moduleId) {
 #include <pthread.h>
 #include <sys/socket.h>
 #include <sys/types.h>
-#ifndef QNX
+#if !defined(QNX) && !defined(WEBRTC_BSD)
 #include <linux/net.h>
 #ifndef ANDROID
 #include <sys/soundcard.h>
