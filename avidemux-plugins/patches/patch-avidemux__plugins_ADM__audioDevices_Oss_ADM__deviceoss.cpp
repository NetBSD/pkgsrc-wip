$NetBSD$

Add support for NetBSD.

--- avidemux_plugins/ADM_audioDevices/Oss/ADM_deviceoss.cpp.orig	2022-09-17 13:59:17.000000000 +0000
+++ avidemux_plugins/ADM_audioDevices/Oss/ADM_deviceoss.cpp
@@ -18,11 +18,11 @@
 #include "ADM_default.h"
 
 
-#if defined(ADM_BSD_FAMILY) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if defined(ADM_BSD_FAMILY) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 	#include <soundcard.h>
 	const char *dsp = DEVOSSAUDIO;;
 
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
 	#include <soundcard.h>
 	const char *dsp = "/dev/audio";
 	const char *device_mixer = "/dev/mixer";
