$NetBSD$

--- src/audio/audio_dev_creator.cpp.orig	2015-10-03 21:09:58.000000000 +0000
+++ src/audio/audio_dev_creator.cpp
@@ -8,7 +8,7 @@
 #include <ugens.h>
 #include <stdio.h>
 
-#ifdef LINUX
+#if defined(LINUX) || defined(NETBSD)
 #include "SinglePortOSSAudioDevice.h"
 #include "MultiPortOSSAudioDevice.h"
 #include "TestAudioDevice.h"
@@ -59,7 +59,7 @@ static const AudioDevEntry s_AudioDevEnt
 #ifdef ALSA
 	{ &ALSAAudioDevice::recognize, &ALSAAudioDevice::create },
 #endif
-#ifdef LINUX
+#if defined(LINUX) || defined(NETBSD)
 #ifdef TEST_AUDIO_DEVICE
 	{ &TestAudioDevice::recognize, &TestAudioDevice::create },
 #endif
