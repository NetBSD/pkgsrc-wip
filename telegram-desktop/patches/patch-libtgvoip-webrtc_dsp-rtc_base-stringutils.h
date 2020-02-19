$NetBSD$

--- Telegram/ThirdParty/libtgvoip/webrtc_dsp/rtc_base/stringutils.h.orig	2020-02-18 22:22:41.565702834 +0000
+++ Telegram/ThirdParty/libtgvoip/webrtc_dsp/rtc_base/stringutils.h
@@ -25,7 +25,7 @@
 #endif  // WEBRTC_WIN
 
 #if defined(WEBRTC_POSIX)
-#ifdef BSD
+#if defined(BSD) || defined(__NetBSD__)
 #include <stdlib.h>
 #else  // BSD
 #include <alloca.h>
