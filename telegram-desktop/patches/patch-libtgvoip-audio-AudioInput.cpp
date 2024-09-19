$NetBSD$

--- Telegram/ThirdParty/libtgvoip/audio/AudioInput.cpp.orig	2021-01-01 14:29:15.000000000 +0000
+++ Telegram/ThirdParty/libtgvoip/audio/AudioInput.cpp
@@ -26,7 +26,7 @@
 #include "../os/windows/AudioInputWave.h"
 #endif
 #include "../os/windows/AudioInputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__) || !defined(__NetBSD__)
 #ifndef WITHOUT_ALSA
 #include "../os/linux/AudioInputALSA.h"
 #endif
