$NetBSD$

--- src/audio/SinglePortOSSAudioDevice.h.orig	2015-10-03 21:09:58.000000000 +0000
+++ src/audio/SinglePortOSSAudioDevice.h
@@ -3,7 +3,7 @@
 #ifndef _SINGLE_PORT_OSS_AUDIO_DEVICE_H_
 #define _SINGLE_PORT_OSS_AUDIO_DEVICE_H_
 
-#ifdef LINUX
+#if defined(LINUX) || defined(NETBSD)
 
 #include "OSSAudioDevice.h"
 
@@ -28,6 +28,6 @@ protected:
 	virtual int closeDevice();
 };
 
-#endif	// LINUX
+#endif	// LINUX || NETBSD
 
 #endif	// _SINGLE_PORT_OSS_AUDIO_DEVICE_H_
