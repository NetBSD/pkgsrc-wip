$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/ozone/platform/wayland/host/wayland_window.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/ui/ozone/platform/wayland/host/wayland_window.h
@@ -39,7 +39,7 @@
 #include "ui/platform_window/platform_window_init_properties.h"
 #include "ui/platform_window/wm/wm_drag_handler.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/platform/wayland/host/wayland_async_cursor.h"
 #endif
 
@@ -246,7 +246,7 @@ class WaylandWindow : public PlatformWin
     bool is_snapped_primary = false;
     bool is_snapped_secondary = false;
     bool is_floated = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     WindowTiledEdges tiled_edges;
 #endif
 
@@ -500,7 +500,7 @@ class WaylandWindow : public PlatformWin
 
   void UpdateCursorShape(scoped_refptr<BitmapCursor> cursor);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnCursorLoaded(scoped_refptr<WaylandAsyncCursor> cursor,
                       scoped_refptr<BitmapCursor> bitmap_cursor);
 #endif
@@ -559,7 +559,7 @@ class WaylandWindow : public PlatformWin
 
   wl::Object<zaura_surface> aura_surface_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The current asynchronously loaded cursor (Linux specific).
   scoped_refptr<WaylandAsyncCursor> async_cursor_;
 #else
