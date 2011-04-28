$NetBSD: patch-chrome_browser_ui_toolbar_wrench__menu__model.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/toolbar/wrench_menu_model.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/toolbar/wrench_menu_model.cc
@@ -37,7 +37,7 @@
 #include "ui/base/models/button_menu_item_model.h"
 #include "ui/base/resource/resource_bundle.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 #include <gtk/gtk.h>
 #include "chrome/browser/ui/gtk/gtk_util.h"
 #endif
@@ -355,7 +355,7 @@ void WrenchMenuModel::Build() {
                              IDS_NEW_INCOGNITO_WINDOW);
 
   AddSeparator();
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(TOOLKIT_VIEWS))
+#if defined(OS_MACOSX) || defined(TOOLKIT_USES_GTK)
   // WARNING: Mac does not use the ButtonMenuItemModel, but instead defines the
   // layout for this menu item in Toolbar.xib. It does, however, use the
   // command_id value from AddButtonItem() to identify this special item.
@@ -370,7 +370,7 @@ void WrenchMenuModel::Build() {
 #endif
 
   AddSeparator();
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(TOOLKIT_VIEWS))
+#if defined(OS_MACOSX) || defined(TOOLKIT_USES_GTK)
   // WARNING: See above comment.
   zoom_menu_item_model_.reset(
       new ui::ButtonMenuItemModel(IDS_ZOOM_MENU, this));
