$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/x/x11_global_shortcut_listener.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/base/x/x11_global_shortcut_listener.cc
@@ -36,11 +36,13 @@ const x11::ModMask kModifiersMasks[] = {
 
 x11::ModMask GetNativeModifiers(bool is_alt_down,
                                 bool is_ctrl_down,
-                                bool is_shift_down) {
+                                bool is_shift_down,
+                                bool is_cmd_down) {
   constexpr auto kNoMods = x11::ModMask{};
   return (is_shift_down ? x11::ModMask::Shift : kNoMods) |
          (is_ctrl_down ? x11::ModMask::Control : kNoMods) |
-         (is_alt_down ? x11::ModMask::c_1 : kNoMods);
+         (is_alt_down ? x11::ModMask::c_1 : kNoMods) |
+         (is_cmd_down ? x11::ModMask::c_4 : kNoMods);
 }
 
 }  // namespace
@@ -86,8 +88,9 @@ uint32_t XGlobalShortcutListener::Dispat
 bool XGlobalShortcutListener::RegisterAccelerator(KeyboardCode key_code,
                                                   bool is_alt_down,
                                                   bool is_ctrl_down,
-                                                  bool is_shift_down) {
-  auto modifiers = GetNativeModifiers(is_alt_down, is_ctrl_down, is_shift_down);
+                                                  bool is_shift_down,
+                                                  bool is_cmd_down) {
+  auto modifiers = GetNativeModifiers(is_alt_down, is_ctrl_down, is_shift_down, is_cmd_down);
   auto keysym = XKeysymForWindowsKeyCode(key_code, false);
   auto keycode = connection_->KeysymToKeycode(keysym);
 
@@ -112,7 +115,7 @@ bool XGlobalShortcutListener::RegisterAc
   }
 
   registered_combinations_.insert(
-      Accelerator(key_code, is_alt_down, is_ctrl_down, is_shift_down));
+      Accelerator(key_code, is_alt_down, is_ctrl_down, is_shift_down, is_cmd_down));
 
   return true;
 }
@@ -120,8 +123,9 @@ bool XGlobalShortcutListener::RegisterAc
 void XGlobalShortcutListener::UnregisterAccelerator(KeyboardCode key_code,
                                                     bool is_alt_down,
                                                     bool is_ctrl_down,
-                                                    bool is_shift_down) {
-  auto modifiers = GetNativeModifiers(is_alt_down, is_ctrl_down, is_shift_down);
+                                                    bool is_shift_down,
+                                                    bool is_cmd_down) {
+  auto modifiers = GetNativeModifiers(is_alt_down, is_ctrl_down, is_shift_down, is_cmd_down);
   auto keysym = XKeysymForWindowsKeyCode(key_code, false);
   auto keycode = connection_->KeysymToKeycode(keysym);
 
@@ -129,7 +133,7 @@ void XGlobalShortcutListener::Unregister
     connection_->UngrabKey({keycode, x_root_window_, modifiers | mask});
 
   registered_combinations_.erase(
-      Accelerator(key_code, is_alt_down, is_ctrl_down, is_shift_down));
+      Accelerator(key_code, is_alt_down, is_ctrl_down, is_shift_down, is_cmd_down));
 }
 
 void XGlobalShortcutListener::OnKeyPressEvent(const KeyEvent& event) {
@@ -139,14 +143,15 @@ void XGlobalShortcutListener::OnKeyPress
   const bool is_alt_down = event.flags() & EF_ALT_DOWN;
   const bool is_ctrl_down = event.flags() & EF_CONTROL_DOWN;
   const bool is_shift_down = event.flags() & EF_SHIFT_DOWN;
+  const bool is_cmd_down = event.flags() & EF_COMMAND_DOWN;
 
   if (!base::Contains(
           registered_combinations_,
-          Accelerator(key_code, is_alt_down, is_ctrl_down, is_shift_down))) {
+          Accelerator(key_code, is_alt_down, is_ctrl_down, is_shift_down, is_cmd_down))) {
     return;
   }
 
-  OnKeyPressed(key_code, is_alt_down, is_ctrl_down, is_shift_down);
+  OnKeyPressed(key_code, is_alt_down, is_ctrl_down, is_shift_down, is_cmd_down);
 }
 
 }  // namespace ui
