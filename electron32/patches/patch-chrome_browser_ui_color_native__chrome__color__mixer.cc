$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/color/native_chrome_color_mixer.cc.orig	2024-10-18 12:34:03.156381600 +0000
+++ chrome/browser/ui/color/native_chrome_color_mixer.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 
 #if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && \
-    !BUILDFLAG(IS_WIN)
+    !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
 void AddNativeChromeColorMixer(ui::ColorProvider* provider,
                                const ui::ColorProviderKey& key) {}
 #endif
