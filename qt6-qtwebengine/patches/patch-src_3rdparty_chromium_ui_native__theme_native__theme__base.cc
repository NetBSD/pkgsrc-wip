$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/native_theme/native_theme_base.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/ui/native_theme/native_theme_base.cc
@@ -235,7 +235,7 @@ void NativeThemeBase::Paint(cc::PaintCan
       break;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect,
                         absl::get<FrameTopAreaExtraParams>(extra),
