$NetBSD$

--- Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp.orig	2020-02-18 21:50:53.875728496 +0000
+++ Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp
@@ -31,7 +31,7 @@
 #endif
 #include "../os/windows/AudioInputWASAPI.h"
 #include "../os/windows/AudioOutputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__) || defined(__NetBSD__)
 #ifndef WITHOUT_ALSA
 #include "../os/linux/AudioInputALSA.h"
 #include "../os/linux/AudioOutputALSA.h"
