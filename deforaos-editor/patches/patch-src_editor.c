$NetBSD: patch-src_editor.c,v 1.1 2015/06/13 21:21:49 khorben Exp $

Fix build with Gtk+ 3

--- src/editor.c.orig	2015-06-11 14:36:48.000000000 +0000
+++ src/editor.c
@@ -1450,7 +1450,7 @@ void editor_show_properties(Editor * edi
 		q = p;
 	}
 	widget = gtk_entry_new();
-	gtk_entry_set_editable(GTK_ENTRY(widget), FALSE);
+	gtk_editable_set_editable(GTK_EDITABLE(widget), FALSE);
 	gtk_entry_set_text(GTK_ENTRY(widget), q);
 	gtk_size_group_add_widget(vgroup, widget);
 	g_free(p);
