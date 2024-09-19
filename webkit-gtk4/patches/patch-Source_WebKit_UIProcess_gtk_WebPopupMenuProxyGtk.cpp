$NetBSD$

--- Source/WebKit/UIProcess/gtk/WebPopupMenuProxyGtk.cpp.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/UIProcess/gtk/WebPopupMenuProxyGtk.cpp
@@ -34,6 +34,10 @@
 #include <gtk/gtk.h>
 #include <wtf/glib/GUniquePtr.h>
 #include <wtf/text/CString.h>
+#if USE(GTK4) && PLATFORM(QUARTZ)
+#define __GDKMACOS_H_INSIDE__
+#include <gdk/macos/gdkmacos.h>
+#endif
 
 namespace WebKit {
 using namespace WebCore;
@@ -259,7 +263,7 @@ void WebPopupMenuProxyGtk::createPopupMe
         auto* event = gtk_event_controller_get_current_event(controller);
         if (popupMenu->typeAheadFind(keyval, gdk_event_get_time(event)))
             return GDK_EVENT_STOP;
-        return gtk_event_controller_key_forward(GTK_EVENT_CONTROLLER_KEY(controller), popupMenu->m_treeView);
+        return (bool)gtk_event_controller_key_forward(GTK_EVENT_CONTROLLER_KEY(controller), popupMenu->m_treeView);
     }), this);
     gtk_widget_add_controller(m_popup, controller);
 #else
@@ -320,7 +324,11 @@ void WebPopupMenuProxyGtk::showPopupMenu
     auto* monitor = gdk_display_get_monitor_at_window(display, gtk_widget_get_window(m_webView));
 #endif
     GdkRectangle area;
+#if USE(GTK4) && PLATFORM(QUARTZ)
+    gdk_macos_monitor_get_workarea(monitor, &area);
+#else
     gdk_monitor_get_workarea(monitor, &area);
+#endif
     int width = std::min(rect.width(), area.width);
     size_t itemCount = std::min<size_t>(items.size(), (area.height / 3) / itemHeight);
 
