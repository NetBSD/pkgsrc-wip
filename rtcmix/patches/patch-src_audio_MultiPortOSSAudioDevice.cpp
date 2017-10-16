$NetBSD$

--- src/audio/MultiPortOSSAudioDevice.cpp.orig	2015-10-03 21:09:58.000000000 +0000
+++ src/audio/MultiPortOSSAudioDevice.cpp
@@ -1,6 +1,6 @@
 // MultiPortOSSAudioDevice.cpp
 
-#if defined(LINUX)
+#if defined(LINUX) || defined(NETBSD)
 
 #include "MultiPortOSSAudioDevice.h"
 #include <sys/soundcard.h>
@@ -161,11 +161,11 @@ MultiPortOSSAudioDevice::doSetQueueSize(
 	int fragSize = 0;
 	for (int dev = 0; dev < _devCount; ++dev) {
 		int fd = _devices[dev];
-		if (::ioctl(fd, SNDCTL_DSP_SETFRAGMENT, &sizeCode) == -1) {
+		if (ioctl(fd, SNDCTL_DSP_SETFRAGMENT, &sizeCode) == -1) {
 			printf("ioctl(%d, SNDCTL_DSP_SETFRAGMENT, ...) returned -1\n",
 				   fd);
 		}
-		if (::ioctl(fd, SNDCTL_DSP_GETBLKSIZE, &fragSize) == -1) {
+		if (ioctl(fd, SNDCTL_DSP_GETBLKSIZE, &fragSize) == -1) {
 			return error("OSS error while retrieving fragment size: ",
 						 strerror(errno));
 		}
@@ -233,4 +233,4 @@ MultiPortOSSAudioDevice::closeDevice()
 	return status;
 }
 
-#endif	// LINUX
+#endif	// LINUX || NETBSD
