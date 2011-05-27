$NetBSD: patch-chrome_browser_ui_views_extensions_extension__popup.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/browser/ui/views/extensions/extension_popup.cc.orig	2011-05-24 08:01:41.000000000 +0000
+++ chrome/browser/ui/views/extensions/extension_popup.cc
@@ -23,7 +23,7 @@
 #include "views/widget/root_view.h"
 #include "views/window/window.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
@@ -94,7 +94,7 @@ ExtensionPopup::ExtensionPopup(Extension
 
   // The bubble chrome requires a separate window, so construct it here.
   gfx::NativeView native_window = frame->GetNativeView();
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
   border_widget_ = new views::WidgetGtk(views::WidgetGtk::TYPE_WINDOW);
   static_cast<views::WidgetGtk*>(border_widget_)->MakeTransparent();
   static_cast<views::WidgetGtk*>(border_widget_)->make_transient_to_parent();
