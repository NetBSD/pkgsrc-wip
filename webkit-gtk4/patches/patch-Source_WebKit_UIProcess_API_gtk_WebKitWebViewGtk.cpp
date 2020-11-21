$NetBSD$

--- Source/WebKit/UIProcess/API/gtk/WebKitWebViewGtk.cpp.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/UIProcess/API/gtk/WebKitWebViewGtk.cpp
@@ -154,15 +154,15 @@ static void surfaceStateChangedCallback(
     bool eventCompleted = false;
     switch (state->type) {
     case WindowStateEvent::Type::Maximize:
-        if (surfaceState & GDK_SURFACE_STATE_MAXIMIZED)
+        if (surfaceState & GDK_TOPLEVEL_STATE_MAXIMIZED)
             eventCompleted = true;
         break;
     case WindowStateEvent::Type::Minimize:
-        if ((surfaceState & GDK_SURFACE_STATE_MINIMIZED) || !gdk_surface_get_mapped(surface))
+        if ((surfaceState & GDK_TOPLEVEL_STATE_MINIMIZED) || !gdk_surface_get_mapped(surface))
             eventCompleted = true;
         break;
     case WindowStateEvent::Type::Restore:
-        if (!(surfaceState & GDK_SURFACE_STATE_MAXIMIZED) && !(surfaceState & GDK_SURFACE_STATE_MINIMIZED))
+        if (!(surfaceState & GDK_TOPLEVEL_STATE_MAXIMIZED) && !(surfaceState & GDK_TOPLEVEL_STATE_MINIMIZED))
             eventCompleted = true;
         break;
     }
