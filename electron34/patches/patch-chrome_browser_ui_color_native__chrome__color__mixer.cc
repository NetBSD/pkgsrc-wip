$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/color/native_chrome_color_mixer.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/color/native_chrome_color_mixer.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 
 #if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && \
-    !BUILDFLAG(IS_WIN)
+    !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
 void AddNativeChromeColorMixer(ui::ColorProvider* provider,
                                const ui::ColorProviderKey& key) {}
 #endif
