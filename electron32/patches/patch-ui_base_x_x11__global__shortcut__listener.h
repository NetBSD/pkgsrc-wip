$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/x/x11_global_shortcut_listener.h.orig	2024-10-18 12:35:12.384405900 +0000
+++ ui/base/x/x11_global_shortcut_listener.h
@@ -41,18 +41,21 @@ class COMPONENT_EXPORT(UI_BASE_X) XGloba
   virtual void OnKeyPressed(KeyboardCode key_code,
                             bool is_alt_down,
                             bool is_ctrl_down,
-                            bool is_shift_down) = 0;
+                            bool is_shift_down,
+                            bool is_cmd_down) = 0;
 
   void StartListening();
   void StopListening();
   bool RegisterAccelerator(KeyboardCode key_code,
                            bool is_alt_down,
                            bool is_ctrl_down,
-                           bool is_shift_down);
+                           bool is_shift_down,
+                           bool is_cmd_down);
   void UnregisterAccelerator(KeyboardCode key_code,
                              bool is_alt_down,
                              bool is_ctrl_down,
-                             bool is_shift_down);
+                             bool is_shift_down,
+                             bool is_cmd_down);
 
  private:
   // Due to how system key grabbing works on X11, we have to be a bit greedy and
@@ -61,7 +64,7 @@ class COMPONENT_EXPORT(UI_BASE_X) XGloba
   // and filter the incoming events against that registry before notifying the
   // observer.  This tuple describes the meaningful parts of the event; booleans
   // 1, 2, and 3 hold states of Alt, Control, and Shift keys, respectively.
-  using Accelerator = std::tuple<KeyboardCode, bool, bool, bool>;
+  using Accelerator = std::tuple<KeyboardCode, bool, bool, bool, bool>;
 
   // Invoked when a global shortcut is pressed.
   void OnKeyPressEvent(const KeyEvent& event);
