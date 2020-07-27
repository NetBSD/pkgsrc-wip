$NetBSD$

--- ui/views/window/frame_background.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ ui/views/window/frame_background.cc
@@ -99,7 +99,7 @@ void FrameBackground::PaintMaximized(gfx
                                      const View* view) const {
 // Fill the top with the frame color first so we have a constant background
 // for areas not covered by the theme image.
-#if defined(OS_LINUX) && BUILDFLAG(ENABLE_DESKTOP_AURA)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(ENABLE_DESKTOP_AURA)
   auto* native_theme = view->GetNativeTheme();
   ui::NativeTheme::ExtraParams params;
   params.frame_top_area.use_custom_frame = use_custom_frame_;
