$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/native_window_views.h.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/browser/native_window_views.h
@@ -31,7 +31,7 @@ namespace gin {
 class Arguments;
 }  // namespace gin
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace views {
 class FrameViewLinux;
 }  // namespace views
@@ -39,7 +39,7 @@ class FrameViewLinux;
 
 namespace electron {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class GlobalMenuBarX11;
 #endif
 
@@ -183,7 +183,7 @@ class NativeWindowViews : public NativeW
                     LPARAM l_param,
                     LRESULT* result);
   void SetIcon(HICON small_icon, HICON app_icon);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetIcon(const gfx::ImageSkia& icon);
 #endif
 
@@ -205,7 +205,7 @@ class NativeWindowViews : public NativeW
     return overlay_symbol_color_;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   views::FrameViewLinux* GetFrameViewLinux() const;
   [[nodiscard]] bool ignore_mouse_events() const {
     return ignore_mouse_events_;
@@ -289,7 +289,7 @@ class NativeWindowViews : public NativeW
   // events from resizing the window.
   extensions::SizeConstraints old_size_constraints_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<GlobalMenuBarX11> global_menu_bar_;
 
   // Set while the window is disabled; running it re-enables event dispatch.
@@ -308,7 +308,7 @@ class NativeWindowViews : public NativeW
   // This value is determined when the window is created.
   bool rounded_corner_ = true;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool ignore_mouse_events_ = false;
 #endif
 
