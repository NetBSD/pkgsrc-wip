$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/platform/x11/x11_global_shortcut_listener_ozone.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/ozone/platform/x11/x11_global_shortcut_listener_ozone.h
@@ -28,17 +28,20 @@ class X11GlobalShortcutListenerOzone : p
   bool RegisterAccelerator(KeyboardCode key_code,
                            bool is_alt_down,
                            bool is_ctrl_down,
-                           bool is_shift_down) override;
+                           bool is_shift_down,
+                           bool is_cmd_down) override;
   void UnregisterAccelerator(KeyboardCode key_code,
                              bool is_alt_down,
                              bool is_ctrl_down,
-                             bool is_shift_down) override;
+                             bool is_shift_down,
+                             bool is_cmd_down) override;
 
   // ui::XGlobalShortcutListener:
   void OnKeyPressed(KeyboardCode key_code,
                     bool is_alt_down,
                     bool is_ctrl_down,
-                    bool is_shift_down) override;
+                    bool is_shift_down,
+                    bool is_cmd_down) override;
 };
 
 }  // namespace ui
