$NetBSD: patch-chrome_browser_ui_toolbar_wrench__menu__model.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/browser/ui/toolbar/wrench_menu_model.cc.orig	2011-05-24 08:01:42.000000000 +0000
+++ chrome/browser/ui/toolbar/wrench_menu_model.cc
@@ -38,7 +38,7 @@
 #include "ui/base/models/button_menu_item_model.h"
 #include "ui/base/resource/resource_bundle.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 #include <gtk/gtk.h>
 #include "chrome/browser/ui/gtk/gtk_util.h"
 #endif
@@ -359,7 +359,7 @@ void WrenchMenuModel::Build() {
 #endif
 
   AddSeparator();
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(TOOLKIT_VIEWS))
+#if defined(OS_MACOSX) || defined(TOOLKIT_USES_GTK)
   // WARNING: Mac does not use the ButtonMenuItemModel, but instead defines the
   // layout for this menu item in Toolbar.xib. It does, however, use the
   // command_id value from AddButtonItem() to identify this special item.
@@ -374,7 +374,7 @@ void WrenchMenuModel::Build() {
 #endif
 
   AddSeparator();
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(TOOLKIT_VIEWS))
+#if defined(OS_MACOSX) || defined(TOOLKIT_USES_GTK)
   // WARNING: See above comment.
   zoom_menu_item_model_.reset(
       new ui::ButtonMenuItemModel(IDS_ZOOM_MENU, this));
