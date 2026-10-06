$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/native_theme/native_theme_base.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/native_theme/native_theme_base.cc
@@ -237,7 +237,7 @@ void NativeThemeBase::Paint(cc::PaintCan
                     absl::get<ButtonExtraParams>(extra), color_scheme,
                     accent_color_opaque);
       break;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect,
                         absl::get<FrameTopAreaExtraParams>(extra),
