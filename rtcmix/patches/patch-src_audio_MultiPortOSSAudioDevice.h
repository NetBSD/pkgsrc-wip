$NetBSD$

--- src/audio/MultiPortOSSAudioDevice.h.orig	2015-10-03 21:09:58.000000000 +0000
+++ src/audio/MultiPortOSSAudioDevice.h
@@ -3,7 +3,7 @@
 #ifndef _MULTI_PORT_OSS_AUDIO_DEVICE_H_
 #define _MULTI_PORT_OSS_AUDIO_DEVICE_H_
 
-#ifdef LINUX
+#if defined(LINUX) || defined(NETBSD)
 
 #include "OSSAudioDevice.h"
 
@@ -32,6 +32,6 @@ private:
 	int *_devices;
 };
 
-#endif	// LINUX
+#endif	// LINUX || NETBSD
 
 #endif	// _MULTI_PORT_OSS_AUDIO_DEVICE_H_
