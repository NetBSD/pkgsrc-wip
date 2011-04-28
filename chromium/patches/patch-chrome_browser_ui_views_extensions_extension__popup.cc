$NetBSD: patch-chrome_browser_ui_views_extensions_extension__popup.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/extensions/extension_popup.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/extensions/extension_popup.cc
@@ -26,7 +26,7 @@
 #include "views/widget/root_view.h"
 #include "views/window/window.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
@@ -110,7 +110,7 @@ ExtensionPopup::ExtensionPopup(Extension
   // The bubble chrome requires a separate window, so construct it here.
   if (BUBBLE_CHROME == popup_chrome_) {
     gfx::NativeView native_window = frame->GetNativeView();
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
     border_widget_ = new views::WidgetGtk(views::WidgetGtk::TYPE_WINDOW);
     static_cast<views::WidgetGtk*>(border_widget_)->MakeTransparent();
     static_cast<views::WidgetGtk*>(border_widget_)->make_transient_to_parent();
