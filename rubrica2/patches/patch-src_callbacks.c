$NetBSD: patch-src_callbacks.c,v 1.1 2012/10/02 21:46:54 othyro Exp $

Fixes G_CONST_RETURN undeclared error.

--- src/callbacks.c.orig	2011-02-20 15:45:46.000000000 +0000
+++ src/callbacks.c
@@ -336,7 +336,7 @@ on_saveas_cb (GtkWidget* button, gpointe
       gint rate;
       gboolean backup;
       GtkFileFilter* filefilter;
-      G_CONST_RETURN gchar *filter;
+      gchar *filter;
       
       filefilter = gtk_file_chooser_get_filter(GTK_FILE_CHOOSER (chooser));
       filter     = gtk_file_filter_get_name(filefilter);
