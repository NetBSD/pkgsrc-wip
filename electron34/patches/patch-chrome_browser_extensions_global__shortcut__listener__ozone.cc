$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/extensions/global_shortcut_listener_ozone.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/extensions/global_shortcut_listener_ozone.cc
@@ -58,7 +58,8 @@ bool GlobalShortcutListenerOzone::Regist
   const bool registered =
       platform_global_shortcut_listener_->RegisterAccelerator(
           accelerator.key_code(), accelerator.IsAltDown(),
-          accelerator.IsCtrlDown(), accelerator.IsShiftDown());
+          accelerator.IsCtrlDown(), accelerator.IsShiftDown(),
+          accelerator.IsCmdDown());
   if (registered)
     registered_hot_keys_.insert(accelerator);
   return registered;
@@ -72,14 +73,15 @@ void GlobalShortcutListenerOzone::Unregi
 
   platform_global_shortcut_listener_->UnregisterAccelerator(
       accelerator.key_code(), accelerator.IsAltDown(), accelerator.IsCtrlDown(),
-      accelerator.IsShiftDown());
+      accelerator.IsShiftDown(), accelerator.IsCmdDown());
   registered_hot_keys_.erase(accelerator);
 }
 
 void GlobalShortcutListenerOzone::OnKeyPressed(ui::KeyboardCode key_code,
                                                bool is_alt_down,
                                                bool is_ctrl_down,
-                                               bool is_shift_down) {
+                                               bool is_shift_down,
+                                               bool is_cmd_down) {
   int modifiers = 0;
   if (is_alt_down)
     modifiers |= ui::EF_ALT_DOWN;
@@ -87,6 +89,8 @@ void GlobalShortcutListenerOzone::OnKeyP
     modifiers |= ui::EF_CONTROL_DOWN;
   if (is_shift_down)
     modifiers |= ui::EF_SHIFT_DOWN;
+  if (is_cmd_down)
+    modifiers |= ui::EF_COMMAND_DOWN;
 
   NotifyKeyPressed(ui::Accelerator(key_code, modifiers));
 }
