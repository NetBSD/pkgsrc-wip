$NetBSD$

--- chrome/browser/ui/views/frame/browser_view.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -1766,7 +1766,7 @@ void BrowserView::UserChangedTheme(Brows
   const bool should_use_native_frame = frame_->ShouldUseNativeFrame();
 
   bool must_regenerate_frame;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // GTK and user theme changes can both change frame buttons, so the frame
   // always needs to be regenerated on Linux.
   must_regenerate_frame = true;
