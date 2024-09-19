$NetBSD$

--- Tools/MiniBrowser/gtk/BrowserSearchBox.c.orig	2020-08-12 09:17:57.000000000 +0000
+++ Tools/MiniBrowser/gtk/BrowserSearchBox.c
@@ -187,8 +187,8 @@ static void browser_search_box_init(Brow
 
     gtk_orientable_set_orientation(GTK_ORIENTABLE(searchBox), GTK_ORIENTATION_HORIZONTAL);
 #if GTK_CHECK_VERSION(3, 98, 5)
-    gtk_widget_add_css_class(GTK_WIDGET(searchBox), GTK_STYLE_CLASS_LINKED);
-    gtk_widget_add_css_class(GTK_WIDGET(searchBox), GTK_STYLE_CLASS_RAISED);
+    gtk_widget_add_css_class(GTK_WIDGET(searchBox), "linked");
+    gtk_widget_add_css_class(GTK_WIDGET(searchBox), "raised");
 #else
     GtkStyleContext *styleContext = gtk_widget_get_style_context(GTK_WIDGET(searchBox));
     gtk_style_context_add_class(styleContext, GTK_STYLE_CLASS_LINKED);
