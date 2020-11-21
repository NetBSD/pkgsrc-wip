$NetBSD$

--- Source/WebKit/UIProcess/API/gtk/WebKitWebViewBase.cpp.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/UIProcess/API/gtk/WebKitWebViewBase.cpp
@@ -1746,8 +1746,9 @@ static AtkObject* webkitWebViewBaseGetAc
 
         // Set the parent to not break bottom-up navigation.
         if (auto* parentWidget = gtk_widget_get_parent(widget)) {
-            if (auto* axParent = gtk_widget_get_accessible(parentWidget))
-                atk_object_set_parent(priv->accessible.get(), axParent);
+// TODO don't know how to fix this
+//            if (auto* axParent = gtk_widget_get_accessible(parentWidget))
+//                atk_object_set_parent(priv->accessible.get(), axParent);
         }
     }
 
@@ -1778,7 +1779,7 @@ static void toplevelWindowIsActiveChange
 static void toplevelWindowStateChanged(GdkSurface* surface, GParamSpec*, WebKitWebViewBase* webViewBase)
 {
     auto state = gdk_toplevel_get_state(GDK_TOPLEVEL(surface));
-    bool visible = !(state & GDK_SURFACE_STATE_MINIMIZED);
+    bool visible = !(state & GDK_TOPLEVEL_STATE_MINIMIZED);
     WebKitWebViewBasePrivate* priv = webViewBase->priv;
     if (visible) {
         if (priv->activityState & ActivityState::IsVisible)
@@ -2004,7 +2005,7 @@ static void webkit_web_view_base_class_i
 #if !USE(GTK4)
     widgetClass->event = webkitWebViewBaseEvent;
 #endif
-    widgetClass->get_accessible = webkitWebViewBaseGetAccessible;
+//    widgetClass->get_accessible = webkitWebViewBaseGetAccessible;
 #if USE(GTK4)
     widgetClass->root = webkitWebViewBaseRoot;
     widgetClass->unroot = webkitWebViewBaseUnroot;
