$NetBSD$

--- Source/WebKit/UIProcess/API/gtk/WebKitScriptDialogImpl.cpp.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/UIProcess/API/gtk/WebKitScriptDialogImpl.cpp
@@ -113,13 +113,13 @@ static void webkitScriptDialogImplConstr
 #endif
 
     GtkWidget* box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
-    gtk_widget_add_css_class(box, GTK_STYLE_CLASS_TITLEBAR);
+    gtk_widget_add_css_class(box, "titlebar");
     gtk_widget_set_size_request(box, -1, 16);
     priv->title = gtk_label_new(nullptr);
     gtk_label_set_ellipsize(GTK_LABEL(priv->title), PANGO_ELLIPSIZE_END);
     gtk_widget_set_margin_top(priv->title, 6);
     gtk_widget_set_margin_bottom(priv->title, 6);
-    gtk_widget_add_css_class(priv->title, GTK_STYLE_CLASS_TITLE);
+    gtk_widget_add_css_class(priv->title, "title");
 #if USE(GTK4)
     gtk_widget_set_hexpand(priv->title, TRUE);
     gtk_widget_set_halign(priv->title, GTK_ALIGN_CENTER);
@@ -235,7 +235,7 @@ static void webkit_script_dialog_impl_cl
     widgetClass->key_press_event = webkitScriptDialogImplKeyPressEvent;
 #endif
     widgetClass->map = webkitScriptDialogImplMap;
-    gtk_widget_class_set_accessible_role(widgetClass, ATK_ROLE_ALERT);
+    gtk_widget_class_set_accessible_role(widgetClass, GTK_ACCESSIBLE_ROLE_ALERT);
 }
 
 static void webkitScriptDialogImplSetText(WebKitScriptDialogImpl* dialog, const char* text, GtkRequisition* maxSize)
