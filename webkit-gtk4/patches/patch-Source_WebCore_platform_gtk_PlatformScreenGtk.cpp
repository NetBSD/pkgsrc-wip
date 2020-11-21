$NetBSD$

--- Source/WebCore/platform/gtk/PlatformScreenGtk.cpp.orig	2020-08-12 09:17:55.000000000 +0000
+++ Source/WebCore/platform/gtk/PlatformScreenGtk.cpp
@@ -38,6 +38,11 @@
 #include "Widget.h"
 
 #include <cmath>
+#ifdef GDK_WINDOWING_MACOS
+#define __GDKMACOS_H_INSIDE__
+#include <gdk/macos/gdkmacos.h>
+#undef __GDKMACOS_H_INSIDE__
+#endif
 #include <gtk/gtk.h>
 #include <wtf/HashMap.h>
 #include <wtf/HashSet.h>
@@ -206,7 +211,15 @@ FloatRect screenAvailableRect(Widget*)
         return { };
 
     GdkRectangle workArea;
+#if USE(GTK4)
+# if ENABLE_QUARTZ_TARGET
+    gdk_macos_monitor_get_workarea(monitor.get(), &workArea);
+# elif ENABLE_X11_TARGET
+    gdk_x11_monitor_get_workarea(monitor.get(), &workArea);
+# endif
+#else
     gdk_monitor_get_workarea(monitor.get(), &workArea);
+#endif
 
     return FloatRect(workArea.x, workArea.y, workArea.width, workArea.height);
 }
