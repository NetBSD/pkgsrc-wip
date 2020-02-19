$NetBSD$

--- Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp.orig	2020-02-18 21:42:27.390221991 +0000
+++ Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp
@@ -29,7 +29,7 @@
 #include "../os/windows/AudioOutputWave.h"
 #endif
 #include "../os/windows/AudioOutputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__) || defined(__NetBSD__)
 #ifndef WITHOUT_ALSA
 #include "../os/linux/AudioOutputALSA.h"
 #endif
