$NetBSD$

--- gdk/macos/gdkmacostoplevelsurface.c.orig	2020-12-16 17:13:37.000000000 +0000
+++ gdk/macos/gdkmacostoplevelsurface.c
@@ -97,7 +97,7 @@ _gdk_macos_toplevel_surface_present (Gdk
   GdkSurfaceHints mask;
   NSWindowStyleMask style_mask;
   gboolean maximize;
-  gboolean fullscreen
+  gboolean fullscreen;
 
   g_assert (GDK_IS_MACOS_TOPLEVEL_SURFACE (self));
   g_assert (GDK_IS_MACOS_WINDOW (nswindow));
