$NetBSD: patch-src_view.c,v 1.1 2014/06/26 11:22:14 khorben Exp $

Fix build with Gtk+ >= 3.0

--- src/view.c.orig	2013-10-05 02:01:48.000000000 +0000
+++ src/view.c
@@ -155,9 +155,9 @@ static DesktopAccel _view_accel[] =
 static DesktopToolbar _view_toolbar[] =
 {
 	{ N_("Open with..."), G_CALLBACK(_on_open_with), GTK_STOCK_OPEN,
-		GDK_CONTROL_MASK, GDK_O, NULL },
+		GDK_CONTROL_MASK, GDK_KEY_O, NULL },
 	{ N_("Edit"), G_CALLBACK(_on_edit), GTK_STOCK_EDIT, GDK_CONTROL_MASK,
-		GDK_E, NULL },
+		GDK_KEY_E, NULL },
 	{ NULL, NULL, NULL, 0, 0, NULL }
 };
 #endif /* EMBEDDED */
