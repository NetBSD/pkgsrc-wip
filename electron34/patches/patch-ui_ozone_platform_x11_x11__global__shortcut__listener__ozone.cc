$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/platform/x11/x11_global_shortcut_listener_ozone.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/ozone/platform/x11/x11_global_shortcut_listener_ozone.cc
@@ -26,27 +26,30 @@ void X11GlobalShortcutListenerOzone::Sto
 bool X11GlobalShortcutListenerOzone::RegisterAccelerator(KeyboardCode key_code,
                                                          bool is_alt_down,
                                                          bool is_ctrl_down,
-                                                         bool is_shift_down) {
+                                                         bool is_shift_down,
+                                                         bool is_cmd_down) {
   return XGlobalShortcutListener::RegisterAccelerator(
-      key_code, is_alt_down, is_ctrl_down, is_shift_down);
+      key_code, is_alt_down, is_ctrl_down, is_shift_down, is_cmd_down);
 }
 
 void X11GlobalShortcutListenerOzone::UnregisterAccelerator(
     KeyboardCode key_code,
     bool is_alt_down,
     bool is_ctrl_down,
-    bool is_shift_down) {
+    bool is_shift_down,
+    bool is_cmd_down) {
   return XGlobalShortcutListener::UnregisterAccelerator(
-      key_code, is_alt_down, is_ctrl_down, is_shift_down);
+      key_code, is_alt_down, is_ctrl_down, is_shift_down, is_cmd_down);
 }
 
 void X11GlobalShortcutListenerOzone::OnKeyPressed(KeyboardCode key_code,
                                                   bool is_alt_down,
                                                   bool is_ctrl_down,
-                                                  bool is_shift_down) {
+                                                  bool is_shift_down,
+                                                  bool is_cmd_down) {
   if (delegate()) {
     delegate()->OnKeyPressed(key_code, is_alt_down, is_ctrl_down,
-                             is_shift_down);
+                             is_shift_down, is_cmd_down);
   }
 }
 
