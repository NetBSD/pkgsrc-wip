$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/public/platform_global_shortcut_listener.h.orig	2024-10-18 12:35:12.776249600 +0000
+++ ui/ozone/public/platform_global_shortcut_listener.h
@@ -20,7 +20,8 @@ class COMPONENT_EXPORT(OZONE_BASE) Platf
   virtual void OnKeyPressed(KeyboardCode key_code,
                             bool is_alt_down,
                             bool is_ctrl_down,
-                            bool is_shift_down) = 0;
+                            bool is_shift_down,
+                            bool is_cmd_down) = 0;
   // Called back when the platform implementation is destroyed.
   virtual void OnPlatformListenerDestroyed() = 0;
 
@@ -52,11 +53,13 @@ class COMPONENT_EXPORT(OZONE_BASE) Platf
   virtual bool RegisterAccelerator(KeyboardCode key_code,
                                    bool is_alt_down,
                                    bool is_ctrl_down,
-                                   bool is_shift_down) = 0;
+                                   bool is_shift_down,
+                                   bool is_cmd_down) = 0;
   virtual void UnregisterAccelerator(KeyboardCode key_code,
                                      bool is_alt_down,
                                      bool is_ctrl_down,
-                                     bool is_shift_down) = 0;
+                                     bool is_shift_down,
+                                     bool is_cmd_down) = 0;
 
  protected:
   PlatformGlobalShortcutListenerDelegate* delegate() { return delegate_; }
