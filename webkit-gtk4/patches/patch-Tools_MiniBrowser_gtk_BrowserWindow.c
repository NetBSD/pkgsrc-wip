$NetBSD$

--- Tools/MiniBrowser/gtk/BrowserWindow.c.orig	2020-08-12 09:17:57.000000000 +0000
+++ Tools/MiniBrowser/gtk/BrowserWindow.c
@@ -989,9 +989,9 @@ static void browserWindowSetupEditorTool
 
     GtkWidget *groupBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
 #if GTK_CHECK_VERSION(3, 98, 5)
-    gtk_widget_add_css_class(groupBox, GTK_STYLE_CLASS_LINKED);
+    gtk_widget_add_css_class(groupBox, "linked");
 #else
-    gtk_style_context_add_class(gtk_widget_get_style_context(groupBox), GTK_STYLE_CLASS_LINKED);
+    gtk_style_context_add_class(gtk_widget_get_style_context(groupBox), "linked");
 #endif
     addToolbarButton(groupBox, TOOLBAR_BUTTON_TOGGLE, "format-text-bold-symbolic", "edit.Bold");
     addToolbarButton(groupBox, TOOLBAR_BUTTON_TOGGLE, "format-text-italic-symbolic", "edit.Italic");
@@ -1006,9 +1006,9 @@ static void browserWindowSetupEditorTool
 
     groupBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
 #if GTK_CHECK_VERSION(3, 98, 5)
-    gtk_widget_add_css_class(groupBox, GTK_STYLE_CLASS_LINKED);
+    gtk_widget_add_css_class(groupBox, "linked");
 #else
-    gtk_style_context_add_class(gtk_widget_get_style_context(groupBox), GTK_STYLE_CLASS_LINKED);
+    gtk_style_context_add_class(gtk_widget_get_style_context(groupBox), "linked");
 #endif
     addToolbarButton(groupBox, TOOLBAR_BUTTON_NORMAL, "edit-cut-symbolic", "edit.Cut");
     addToolbarButton(groupBox, TOOLBAR_BUTTON_NORMAL, "edit-copy-symbolic", "edit.Copy");
@@ -1022,9 +1022,9 @@ static void browserWindowSetupEditorTool
 
     groupBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
 #if GTK_CHECK_VERSION(3, 98, 5)
-    gtk_widget_add_css_class(groupBox, GTK_STYLE_CLASS_LINKED);
+    gtk_widget_add_css_class(groupBox, "linked");
 #else
-    gtk_style_context_add_class(gtk_widget_get_style_context(groupBox), GTK_STYLE_CLASS_LINKED);
+    gtk_style_context_add_class(gtk_widget_get_style_context(groupBox), "linked");
 #endif
     addToolbarButton(groupBox, TOOLBAR_BUTTON_NORMAL, "edit-undo-symbolic", "edit.Undo");
     addToolbarButton(groupBox, TOOLBAR_BUTTON_NORMAL, "edit-redo-symbolic", "edit.Redo");
@@ -1037,9 +1037,9 @@ static void browserWindowSetupEditorTool
 
     groupBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
 #if GTK_CHECK_VERSION(3, 98, 5)
-    gtk_widget_add_css_class(groupBox, GTK_STYLE_CLASS_LINKED);
+    gtk_widget_add_css_class(groupBox, "linked");
 #else
-    gtk_style_context_add_class(gtk_widget_get_style_context(groupBox), GTK_STYLE_CLASS_LINKED);
+    gtk_style_context_add_class(gtk_widget_get_style_context(groupBox), "linked");
 #endif
     addToolbarButton(groupBox, TOOLBAR_BUTTON_NORMAL, "format-justify-left-symbolic", "edit.JustifyLeft");
     addToolbarButton(groupBox, TOOLBAR_BUTTON_NORMAL, "format-justify-center-symbolic", "edit.JustifyCenter");
@@ -1053,9 +1053,9 @@ static void browserWindowSetupEditorTool
 
     groupBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
 #if GTK_CHECK_VERSION(3, 98, 5)
-    gtk_widget_add_css_class(groupBox, GTK_STYLE_CLASS_LINKED);
+    gtk_widget_add_css_class(groupBox, "linked");
 #else
-    gtk_style_context_add_class(gtk_widget_get_style_context(groupBox), GTK_STYLE_CLASS_LINKED);
+    gtk_style_context_add_class(gtk_widget_get_style_context(groupBox), "linked");
 #endif
     addToolbarButton(groupBox, TOOLBAR_BUTTON_NORMAL, "format-indent-more-symbolic", "edit.Indent");
     addToolbarButton(groupBox, TOOLBAR_BUTTON_NORMAL, "format-indent-less-symbolic", "edit.Outdent");
@@ -1068,9 +1068,9 @@ static void browserWindowSetupEditorTool
 
     groupBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
 #if GTK_CHECK_VERSION(3, 98, 5)
-    gtk_widget_add_css_class(groupBox, GTK_STYLE_CLASS_LINKED);
+    gtk_widget_add_css_class(groupBox, "linked");
 #else
-    gtk_style_context_add_class(gtk_widget_get_style_context(groupBox), GTK_STYLE_CLASS_LINKED);
+    gtk_style_context_add_class(gtk_widget_get_style_context(groupBox), "linked");
 #endif
     GtkWidget *button = addToolbarButton(groupBox, TOOLBAR_BUTTON_NORMAL, "insert-image-symbolic", NULL);
     g_signal_connect(button, "clicked", G_CALLBACK(insertImageCommandCallback), window);
@@ -1239,9 +1239,9 @@ static void browser_window_init(BrowserW
 
     GtkWidget *navigationBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
 #if GTK_CHECK_VERSION(3, 98, 5)
-    gtk_widget_add_css_class(navigationBox, GTK_STYLE_CLASS_LINKED);
+    gtk_widget_add_css_class(navigationBox, "linked");
 #else
-    gtk_style_context_add_class(gtk_widget_get_style_context(navigationBox), GTK_STYLE_CLASS_LINKED);
+    gtk_style_context_add_class(gtk_widget_get_style_context(navigationBox), "linked");
 #endif
 
     window->backItem = addToolbarButton(navigationBox, TOOLBAR_BUTTON_NORMAL, "go-previous-symbolic", "win.go-back");
