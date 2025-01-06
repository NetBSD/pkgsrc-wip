$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/test/skia_gold_pixel_diff.cc.orig	2024-10-18 12:35:12.380407600 +0000
+++ ui/base/test/skia_gold_pixel_diff.cc
@@ -115,7 +115,7 @@ const char* GetPlatformName() {
   return "macOS";
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   return "lacros";
