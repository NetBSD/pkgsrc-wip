$NetBSD$

--- src/audio/OSSAudioDevice.cpp.orig	2015-10-03 21:09:58.000000000 +0000
+++ src/audio/OSSAudioDevice.cpp
@@ -1,6 +1,6 @@
 // OSSAudioDevice.cpp
 
-#if defined(LINUX)
+#if defined(LINUX) || defined(NETBSD)
 
 #include <math.h>
 #include "OSSAudioDevice.h"
@@ -72,7 +72,7 @@ int OSSAudioDevice::doStart()
 {
 	// Get this now if user never set it.
 	if (_bufferSize == 0) {
-		if (ioctl(SNDCTL_DSP_GETBLKSIZE, &_bufferSize) == -1) {
+		if (ioctl(device(), SNDCTL_DSP_GETBLKSIZE, &_bufferSize) == -1) {
 			return error("Error while retrieving block size.");
 		}
 	}
@@ -90,7 +90,7 @@ OSSAudioDevice::setDeviceFormat(int dev,
 								int *chans, int srate)
 {
 	int confirmedFormat = sampleFormat;
-	if (::ioctl(dev, SNDCTL_DSP_SETFMT, &confirmedFormat))
+	if (ioctl(dev, SNDCTL_DSP_SETFMT, &confirmedFormat))
 		return error("OSS error while setting sample format: ", strerror(errno));
 	else if (confirmedFormat != sampleFormat)
 		return error("This sample format not supported by device.");
@@ -101,7 +101,7 @@ OSSAudioDevice::setDeviceFormat(int dev,
 		return error("This device supports only mono and stereo");
 	}
 #else
-	if (::ioctl(dev, SOUND_PCM_WRITE_CHANNELS, &reqChans) == 0) {
+	if (ioctl(dev, SOUND_PCM_WRITE_CHANNELS, &reqChans) == 0) {
 		if (reqChans < *chans) {
 			PRINT0("OSSAudioDevice::setDeviceFormat:  Max device channel count is %d\n", reqChans);
 			return error("OSS device does not support this channel count");
@@ -116,7 +116,7 @@ OSSAudioDevice::setDeviceFormat(int dev,
 		 	   strerror(errno));
 		// Try opening device in 8-channel mode
 		reqChans = 8;
-		if (::ioctl(dev, SOUND_PCM_WRITE_CHANNELS, &reqChans) == 0) {
+		if (ioctl(dev, SOUND_PCM_WRITE_CHANNELS, &reqChans) == 0) {
 			PRINT0("OSSAudioDevice::setDeviceFormat:  Device forced channel count to %d\n", reqChans);
 			*chans = reqChans;
 		}
@@ -130,7 +130,7 @@ OSSAudioDevice::setDeviceFormat(int dev,
 #endif
 	{
 		int dsp_stereo = (reqChans == 2);
-		if (::ioctl(dev, SNDCTL_DSP_STEREO, &dsp_stereo)
+		if (ioctl(dev, SNDCTL_DSP_STEREO, &dsp_stereo)
 			|| dsp_stereo != (reqChans == 2))
 		{
 			return error("OSS error while setting channel count: ",
@@ -138,7 +138,7 @@ OSSAudioDevice::setDeviceFormat(int dev,
 		}
 	}
 	int dsp_speed = (int) srate;
-	if (::ioctl(dev, SNDCTL_DSP_SPEED, &dsp_speed))
+	if (ioctl(dev, SNDCTL_DSP_SPEED, &dsp_speed))
 		return error("OSS error while setting sample rate: ", strerror(errno));
 	if (dsp_speed != (int) srate)
 		return error("Device does not support this sample rate");
@@ -148,11 +148,6 @@ OSSAudioDevice::setDeviceFormat(int dev,
 	return 0;
 }
 
-int
-OSSAudioDevice::ioctl(int req, void *argp) {
-	return ::ioctl(device(), req, argp);
-}
-
 static char zeroBuffer[32768];
 
 void OSSAudioDevice::run()
@@ -162,7 +157,7 @@ void OSSAudioDevice::run()
 	int ret;
 	PRINT1("OSSAudioDevice::run: top of loop\n");
 	while ((ret = waitForDevice(0)) == 0) {
-		if (ioctl(playing ? SNDCTL_DSP_GETOSPACE : SNDCTL_DSP_GETISPACE,
+		if (ioctl(device(), playing ? SNDCTL_DSP_GETOSPACE : SNDCTL_DSP_GETISPACE,
 				  &info))
 		{
 			error("OSS error: ", strerror(errno));
@@ -184,7 +179,7 @@ void OSSAudioDevice::run()
 		}
 		// Spin if device is paused
 		if (paused()) {
-			ioctl(SNDCTL_DSP_POST, 0);
+			ioctl(device(), SNDCTL_DSP_POST, 0);
 			while (paused()) {
 				usleep(1000);
 			}
@@ -196,7 +191,7 @@ void OSSAudioDevice::run()
 	
 		PRINT1("OSSAudioDevice::run: flushing...\n");
 		// Flush device.
-		ioctl(SNDCTL_DSP_SYNC, 0);
+		ioctl(device(), SNDCTL_DSP_SYNC, 0);
 	}
 
 	// If we stopped due to callback being done, set the state so that the
@@ -216,5 +211,5 @@ void OSSAudioDevice::run()
 	PRINT1("OSSAudioDevice::run: thread exiting\n");
 }
 
-#endif	// LINUX
+#endif	// LINUX || NETBSD
 
