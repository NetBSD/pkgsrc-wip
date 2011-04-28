$NetBSD: patch-chrome_browser_ui_views_accessible__view__helper.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/accessible_view_helper.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/accessible_view_helper.cc
@@ -21,7 +21,7 @@ AccessibleViewHelper::AccessibleViewHelp
   if (!accessibility_event_router_->AddViewTree(view_tree_, profile))
     view_tree_ = NULL;
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
   GtkWidget* widget = view_tree->GetWidget()->GetNativeView();
   widget_helper_.reset(new AccessibleWidgetHelper(widget, profile));
 #endif
