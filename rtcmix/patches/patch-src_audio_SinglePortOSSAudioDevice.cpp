$NetBSD$

--- src/audio/SinglePortOSSAudioDevice.cpp.orig	2015-10-03 21:09:58.000000000 +0000
+++ src/audio/SinglePortOSSAudioDevice.cpp
@@ -1,6 +1,6 @@
 // SinglePortOSSAudioDevice.cpp
 
-#if defined(LINUX)
+#if defined(LINUX) || defined(NETBSD)
 
 #include "SinglePortOSSAudioDevice.h"
 #include <sys/soundcard.h>
@@ -124,11 +124,11 @@ SinglePortOSSAudioDevice::doSetQueueSize
 		   reqCount, reqQueueBytes);
 	int queuecode = ((int) (log(reqQueueBytes) / log(2.0)));
 	int sizeCode = (reqCount << 16) | (queuecode & 0x0000ffff);
-	if (ioctl(SNDCTL_DSP_SETFRAGMENT, &sizeCode) == -1) {
-		printf("ioctl(SNDCTL_DSP_SETFRAGMENT, ...) returned -1\n");
+	if (ioctl(device(), SNDCTL_DSP_SETFRAGMENT, &sizeCode) == -1) {
+		printf("ioctl(device(), SNDCTL_DSP_SETFRAGMENT, ...) returned -1\n");
 	}
 	int fragSize = 0;
-	if (ioctl(SNDCTL_DSP_GETBLKSIZE, &fragSize) == -1) {
+	if (ioctl(device(), SNDCTL_DSP_GETBLKSIZE, &fragSize) == -1) {
 		return error("OSS error while retrieving fragment size: ", strerror(errno));
 	}
 	PRINT0("SinglePortOSSAudioDevice::doSetQueueSize: OSS returned fragment size of %d bytes\n",
@@ -184,4 +184,4 @@ SinglePortOSSAudioDevice::closeDevice()
 	return status;
 }
 
-#endif	// LINUX
+#endif	// LINUX || NETBSD
