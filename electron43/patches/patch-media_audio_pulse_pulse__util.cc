$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/audio/pulse/pulse_util.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ media/audio/pulse/pulse_util.cc
@@ -50,8 +50,12 @@ constexpr char kBrowserDisplayName[] = "
 
 #if defined(DLOPEN_PULSEAUDIO)
 static const base::FilePath::CharType kPulseLib[] =
+#if BUILDFLAG(IS_BSD)
+    FILE_PATH_LITERAL("libpulse.so");
+#else
     FILE_PATH_LITERAL("libpulse.so.0");
 #endif
+#endif
 
 void DestroyMainloop(pa_threaded_mainloop* mainloop) {
   pa_threaded_mainloop_stop(mainloop);
