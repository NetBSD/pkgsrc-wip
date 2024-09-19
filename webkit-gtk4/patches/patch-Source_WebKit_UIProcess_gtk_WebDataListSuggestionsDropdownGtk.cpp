$NetBSD$

--- Source/WebKit/UIProcess/gtk/WebDataListSuggestionsDropdownGtk.cpp.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/UIProcess/gtk/WebDataListSuggestionsDropdownGtk.cpp
@@ -35,6 +35,10 @@
 #include <WebCore/IntPoint.h>
 #include <wtf/glib/GRefPtr.h>
 #include <wtf/glib/GUniquePtr.h>
+#if USE(GTK4) && PLATFORM(QUARTZ)
+#define __GDKMACOS_H_INSIDE__
+#include <gdk/macos/gdkmacos.h>
+#endif
 
 namespace WebKit {
 
@@ -165,7 +169,13 @@ void WebDataListSuggestionsDropdownGtk::
     auto* monitor = gdk_display_get_monitor_at_window(display, gtk_widget_get_window(m_webView));
 #endif
     GdkRectangle area;
+#if USE(GTK4) && PLATFORM(QUARTZ)
+    gdk_macos_monitor_get_workarea(monitor, &area);
+#elif USE(GTK4) && PLATFORM(X11)
+    gdk_x11_monitor_get_workarea(monitor, &area);
+#else
     gdk_monitor_get_workarea(monitor, &area);
+#endif
     int width = std::min(information.elementRect.width(), area.width);
     size_t itemCount = std::min<size_t>(information.suggestions.size(), (area.height / 3) / itemHeight);
 
