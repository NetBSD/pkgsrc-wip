$NetBSD$

--- Source/WebKit/UIProcess/Inspector/gtk/WebKitInspectorWindow.cpp.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/UIProcess/Inspector/gtk/WebKitInspectorWindow.cpp
@@ -64,14 +64,14 @@ static void webkit_inspector_window_init
     gtk_widget_set_halign(titleLabel, GTK_ALIGN_CENTER);
     gtk_label_set_single_line_mode(GTK_LABEL(titleLabel), TRUE);
     gtk_label_set_ellipsize(GTK_LABEL(titleLabel), PANGO_ELLIPSIZE_END);
-    gtk_widget_add_css_class(titleLabel, GTK_STYLE_CLASS_TITLE);
+    gtk_widget_add_css_class(titleLabel, "title");
     gtk_widget_set_parent(titleLabel, box);
 
     window->subtitleLabel = gtk_label_new(nullptr);
     gtk_widget_set_halign(window->subtitleLabel, GTK_ALIGN_CENTER);
     gtk_label_set_single_line_mode(GTK_LABEL(window->subtitleLabel), TRUE);
     gtk_label_set_ellipsize(GTK_LABEL(window->subtitleLabel), PANGO_ELLIPSIZE_END);
-    gtk_widget_add_css_class(window->subtitleLabel, GTK_STYLE_CLASS_SUBTITLE);
+    gtk_widget_add_css_class(window->subtitleLabel, "subtitle");
     gtk_widget_set_parent(window->subtitleLabel, box);
     gtk_widget_hide(window->subtitleLabel);
 
