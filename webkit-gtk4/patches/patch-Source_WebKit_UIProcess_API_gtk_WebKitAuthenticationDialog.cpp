$NetBSD$

--- Source/WebKit/UIProcess/API/gtk/WebKitAuthenticationDialog.cpp.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/UIProcess/API/gtk/WebKitAuthenticationDialog.cpp
@@ -98,12 +98,12 @@ static void webkitAuthenticationDialogIn
     GtkWidget* vBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
 
     GtkWidget* box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
-    gtk_widget_add_css_class(box, GTK_STYLE_CLASS_TITLEBAR);
+    gtk_widget_add_css_class(box, "titlebar");
     gtk_widget_set_size_request(box, -1, 16);
     GtkWidget* title = gtk_label_new(_("Authentication Required"));
     gtk_widget_set_margin_top(title, 6);
     gtk_widget_set_margin_bottom(title, 6);
-    gtk_widget_add_css_class(title, GTK_STYLE_CLASS_TITLE);
+    gtk_widget_add_css_class(title, "title");
 #if USE(GTK4)
     gtk_widget_set_hexpand(title, TRUE);
     gtk_widget_set_halign(title, GTK_ALIGN_CENTER);
@@ -193,7 +193,7 @@ static void webkitAuthenticationDialogIn
     GtkWidget* loginLabel = gtk_label_new_with_mnemonic(_("_Username"));
     gtk_label_set_mnemonic_widget(GTK_LABEL(loginLabel), priv->loginEntry);
     gtk_widget_set_halign(loginLabel, GTK_ALIGN_END);
-    gtk_widget_add_css_class(loginLabel, GTK_STYLE_CLASS_DIM_LABEL);
+    gtk_widget_add_css_class(loginLabel, "dim-label");
     gtk_widget_show(loginLabel);
 
     priv->passwordEntry = gtk_entry_new();
@@ -205,7 +205,7 @@ static void webkitAuthenticationDialogIn
     GtkWidget* passwordLabel = gtk_label_new_with_mnemonic(_("_Password"));
     gtk_label_set_mnemonic_widget(GTK_LABEL(passwordLabel), priv->passwordEntry);
     gtk_widget_set_halign(passwordLabel, GTK_ALIGN_END);
-    gtk_widget_add_css_class(passwordLabel, GTK_STYLE_CLASS_DIM_LABEL);
+    gtk_widget_add_css_class(passwordLabel, "dim-label");
     gtk_widget_show(passwordLabel);
 
     GtkWidget* grid = gtk_grid_new();
