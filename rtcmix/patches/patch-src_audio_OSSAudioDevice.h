$NetBSD$

--- src/audio/OSSAudioDevice.h.orig	2015-10-03 21:09:58.000000000 +0000
+++ src/audio/OSSAudioDevice.h
@@ -3,7 +3,7 @@
 #ifndef _OSS_AUDIO_DEVICE_H_
 #define _OSS_AUDIO_DEVICE_H_
 
-#ifdef LINUX
+#if defined(LINUX) || defined(NETBSD)
 
 #include "ThreadedAudioDevice.h"
 
@@ -25,7 +25,6 @@ protected:
 	virtual int	doGetFrames(void *frameBuffer, int frameCount)=0;
 	virtual int	doSendFrames(void *frameBuffer, int frameCount)=0;
 	// Local methods
-	int			ioctl(int req, void *argp);
 	int			bufferSize() const { return _bufferSize; }
 protected:
 	// OSS device-level virtual implementation
@@ -40,6 +39,6 @@ protected:
 	int		_bufferSize;
 };
 
-#endif	// LINUX
+#endif	// LINUX || NETBSD
 
 #endif	// _OSS_AUDIO_DEVICE_H_
