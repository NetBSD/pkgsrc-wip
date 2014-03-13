$NetBSD: patch-src_configurator.c,v 1.1 2014/03/13 15:40:15 rsmarples Exp $

Can't inline this as it's used as a function reference.

--- src/configurator.c.orig	2014-03-13 14:58:24.000000000 +0000
+++ src/configurator.c
@@ -1272,7 +1272,7 @@ static void on_browse_btn_clicked(GtkBut
     gtk_widget_destroy(fc);
 }
 
-inline void generic_config_dlg_save(gpointer panel_gpointer,GObject *where_the_object_was)
+static void generic_config_dlg_save(gpointer panel_gpointer,GObject *where_the_object_was)
 {
     Panel *panel = (Panel *)(panel_gpointer);
     panel_config_save(panel);
