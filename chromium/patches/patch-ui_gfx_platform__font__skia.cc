$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/platform_font_skia.cc.orig	2024-07-24 02:45:10.632074400 +0000
+++ ui/gfx/platform_font_skia.cc
@@ -30,7 +30,7 @@
 #include "ui/gfx/system_fonts_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -168,7 +168,7 @@ void PlatformFontSkia::EnsuresDefaultFon
   weight = system_font.GetWeight();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, LinuxUi is used to query the native toolkit (e.g.
   // GTK) for the default UI font.
   if (auto* linux_ui = ui::LinuxUi::instance()) {
