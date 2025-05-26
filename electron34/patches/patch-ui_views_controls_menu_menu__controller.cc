$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_controller.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/controls/menu/menu_controller.cc
@@ -578,13 +578,20 @@ void MenuController::Run(Widget* parent,
                          MenuAnchorPosition position,
                          bool context_menu,
                          bool is_nested_drag,
+                         ui::mojom::MenuSourceType source_type,
                          gfx::NativeView native_view_for_gestures) {
   exit_type_ = ExitType::kNone;
   possible_drag_ = false;
   drag_in_progress_ = false;
   closing_event_time_ = base::TimeTicks();
   menu_start_time_ = base::TimeTicks::Now();
-  menu_start_mouse_press_loc_ = gfx::Point();
+  // In some cases, the context menu is asynchronously created after the "mouse
+  // pressed event" is dispatched, so `RootView::current_event()` below is null.
+  // The mouse press location must be taken from the `anchor_bounds` for these
+  // cases.
+  menu_start_mouse_press_loc_ = source_type == ui::mojom::MenuSourceType::kMouse
+                                    ? anchor_bounds.origin()
+                                    : gfx::Point();
 
   ui::Event* event = nullptr;
   if (parent) {
@@ -641,6 +648,14 @@ void MenuController::Run(Widget* parent,
   // Set the selection, which opens the initial menu.
   SetSelection(root, SELECTION_OPEN_SUBMENU | SELECTION_UPDATE_IMMEDIATELY);
 
+  if (source_type == ui::mojom::MenuSourceType::kKeyboard && context_menu && root->HasSubmenu()) {
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
@@ -2292,19 +2307,15 @@ void MenuController::OpenMenuImpl(MenuIt
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
