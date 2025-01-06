$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_controller.cc.orig	2024-10-18 12:35:12.832227200 +0000
+++ ui/views/controls/menu/menu_controller.cc
@@ -578,6 +578,7 @@ void MenuController::Run(Widget* parent,
                          MenuAnchorPosition position,
                          bool context_menu,
                          bool is_nested_drag,
+                         ui::MenuSourceType source_type,
                          gfx::NativeView native_view_for_gestures) {
   exit_type_ = ExitType::kNone;
   possible_drag_ = false;
@@ -642,6 +643,14 @@ void MenuController::Run(Widget* parent,
   // Set the selection, which opens the initial menu.
   SetSelection(root, SELECTION_OPEN_SUBMENU | SELECTION_UPDATE_IMMEDIATELY);
 
+  if (source_type == ui::MENU_SOURCE_KEYBOARD && context_menu && root->HasSubmenu()) {
+    // For context menus opened via the keyboard we select the first item by default
+    // to match accessibility expectations
+    MenuItemView* first_item = FindInitialSelectableMenuItem(root, INCREMENT_SELECTION_DOWN);
+    if (first_item)
+      SetSelection(first_item, SELECTION_UPDATE_IMMEDIATELY);
+  }
+
   if (button_controller) {
     pressed_lock_ = button_controller->TakeLock(
         false, ui::LocatedEvent::FromIfValid(event));
@@ -2277,19 +2286,15 @@ void MenuController::OpenMenuImpl(MenuIt
     }
     item->GetSubmenu()->ShowAt(params);
 
-    // Figure out if the mouse is under the menu; if so, remember the mouse
-    // location so we can ignore the first mouse move event(s) with that
-    // location. We do this after `ShowAt` because `ConvertFromScreen` doesn't
-    // work correctly if the widget isn't shown.
+    // Remember the mouse location so we can ignore the first mouse move
+    // event(s) with that location. We do this after `ShowAt` because
+    // `ConvertFromScreen` doesn't work correctly if the widget isn't shown.
     if (item->GetSubmenu()->GetWidget()) {
       const gfx::Point mouse_pos = ConvertFromScreen(
           *item->submenu_,
           display::Screen::GetScreen()->GetCursorScreenPoint());
-      MenuPart part_under_mouse = GetMenuPart(item->submenu_.get(), mouse_pos);
-      if (part_under_mouse.type != MenuPartType::kNone) {
-        menu_open_mouse_loc_ =
-            GetLocationInRootMenu(*item->submenu_, mouse_pos);
-      }
+      menu_open_mouse_loc_ =
+          GetLocationInRootMenu(*item->submenu_, mouse_pos);
     }
 
     item->GetSubmenu()->GetWidget()->SetNativeWindowProperty(
