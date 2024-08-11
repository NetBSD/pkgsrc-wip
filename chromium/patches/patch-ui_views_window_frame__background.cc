$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/window/frame_background.cc.orig	2024-07-24 02:45:10.980108000 +0000
+++ ui/views/window/frame_background.cc
@@ -110,7 +110,7 @@ void FrameBackground::PaintMaximized(gfx
                                      int width) const {
 // Fill the top with the frame color first so we have a constant background
 // for areas not covered by the theme image.
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENABLE_DESKTOP_AURA)
   ui::NativeTheme::FrameTopAreaExtraParams frame_top_area;
   frame_top_area.use_custom_frame = use_custom_frame_;
