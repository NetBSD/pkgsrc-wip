$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/extensions/global_shortcut_listener_ozone.h.orig	2024-10-18 12:34:01.581256000 +0000
+++ chrome/browser/extensions/global_shortcut_listener_ozone.h
@@ -46,7 +46,8 @@ class GlobalShortcutListenerOzone
   void OnKeyPressed(ui::KeyboardCode key_code,
                     bool is_alt_down,
                     bool is_ctrl_down,
-                    bool is_shift_down) override;
+                    bool is_shift_down,
+                    bool is_cmd_down) override;
   void OnPlatformListenerDestroyed() override;
 
   bool is_listening_ = false;
