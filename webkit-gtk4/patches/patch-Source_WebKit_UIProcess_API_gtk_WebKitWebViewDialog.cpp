$NetBSD$

--- Source/WebKit/UIProcess/API/gtk/WebKitWebViewDialog.cpp.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/UIProcess/API/gtk/WebKitWebViewDialog.cpp
@@ -113,8 +113,8 @@ static void webkitWebViewDialogConstruct
 #if USE(GTK4)
     gtk_widget_add_css_class(GTK_WIDGET(object), "dialog");
     gtk_widget_add_css_class(GTK_WIDGET(object), "message");
-    gtk_widget_add_css_class(GTK_WIDGET(object), GTK_STYLE_CLASS_CSD);
-    gtk_widget_remove_css_class(GTK_WIDGET(object), GTK_STYLE_CLASS_BACKGROUND);
+    gtk_widget_add_css_class(GTK_WIDGET(object), "csd");
+    gtk_widget_remove_css_class(GTK_WIDGET(object), "background");
 
     WebKitWebViewDialogPrivate* priv = WEBKIT_WEB_VIEW_DIALOG(object)->priv;
     priv->cssProvider = adoptGRef(gtk_css_provider_new());
@@ -122,8 +122,8 @@ static void webkitWebViewDialogConstruct
 #else
     gtk_widget_set_app_paintable(GTK_WIDGET(object), TRUE);
 
-    gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(object)), GTK_STYLE_CLASS_CSD);
-    gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(object)), GTK_STYLE_CLASS_BACKGROUND);
+    gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(object)), "csd");
+    gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(object)), "background");
 #endif
 }
 
@@ -154,7 +154,7 @@ void webkitWebViewDialogSetChild(WebKitW
     g_clear_pointer(&priv->child, gtk_widget_unparent);
     if (child) {
         gtk_widget_set_parent(child, GTK_WIDGET(dialog));
-        gtk_widget_add_css_class(child, GTK_STYLE_CLASS_BACKGROUND);
+        gtk_widget_add_css_class(child, "background");
         gtk_style_context_add_provider(gtk_widget_get_style_context(child), GTK_STYLE_PROVIDER(priv->cssProvider.get()), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
         priv->child = child;
     }
