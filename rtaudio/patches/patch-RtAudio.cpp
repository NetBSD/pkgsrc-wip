$NetBSD$

* Support older OSS implementations (NetBSD)

--- RtAudio.cpp.orig	2021-12-30 20:21:17.238879764 +0000
+++ RtAudio.cpp
@@ -9338,6 +9338,15 @@ bool RtApiPulse::probeDeviceOpen( unsign
 #include <errno.h>
 #include <math.h>
 
+//older defines
+#if !defined(SNDCTL_DSP_HALT) && defined(SNDCTL_DSP_RESET)
+#define SNDCTL_DSP_HALT SNDCTL_DSP_RESET
+#endif
+
+#if !defined(PCM_CAP_DUPLEX) && defined(DSP_CAP_DUPLEX)
+#define PCM_CAP_DUPLEX DSP_CAP_DUPLEX
+#endif
+
 static void *ossCallbackHandler(void * ptr);
 
 // A structure to hold various information related to the OSS API
