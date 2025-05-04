$NetBSD$

Permit to disable appindicator3 support to avoid dbus dependency.
Inspired by OpenBSD ports.

--- src/main.h.orig	2024-09-09 18:39:05.000000000 +0000
+++ src/main.h
@@ -29,11 +29,13 @@
 #include <glib/gi18n.h>
 #include <gdk/gdk.h>
 #include <gtk/gtk.h>
+#ifdef ENABLE_APPINDICATOR
 #ifdef APPINDICATOR_IS_LEGACY
 #include <libappindicator/app-indicator.h>
 #else
 #include <libayatana-appindicator/app-indicator.h>
 #endif
+#endif
 
 #define GROMIT_MOUSE_EVENTS ( GDK_BUTTON_MOTION_MASK | \
                               GDK_BUTTON_PRESS_MASK | \
@@ -116,7 +118,9 @@ typedef struct
 typedef struct
 {
   GtkWidget   *win;
+#ifdef ENABLE_APPINDICATOR
   AppIndicator *trayicon;
+#endif
 
   GdkCursor   *paint_cursor;
   GdkCursor   *erase_cursor;
