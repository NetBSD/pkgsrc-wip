$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/audio/pulse/pulse_util.cc.orig	2024-07-24 02:44:40.973201500 +0000
+++ media/audio/pulse/pulse_util.cc
@@ -45,8 +45,12 @@ constexpr char kBrowserDisplayName[] = "
 
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
