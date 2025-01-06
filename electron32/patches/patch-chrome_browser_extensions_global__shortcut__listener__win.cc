$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/extensions/global_shortcut_listener_win.cc.orig	2024-10-18 12:34:01.581256000 +0000
+++ chrome/browser/extensions/global_shortcut_listener_win.cc
@@ -63,6 +63,8 @@ void GlobalShortcutListenerWin::OnWndPro
   modifiers |= (LOWORD(lparam) & MOD_SHIFT) ? ui::EF_SHIFT_DOWN : 0;
   modifiers |= (LOWORD(lparam) & MOD_ALT) ? ui::EF_ALT_DOWN : 0;
   modifiers |= (LOWORD(lparam) & MOD_CONTROL) ? ui::EF_CONTROL_DOWN : 0;
+  modifiers |= (LOWORD(lparam) & MOD_WIN) ? ui::EF_COMMAND_DOWN : 0;
+
   ui::Accelerator accelerator(
       ui::KeyboardCodeForWindowsKeyCode(key_code), modifiers);
 
@@ -93,6 +95,7 @@ bool GlobalShortcutListenerWin::Register
   modifiers |= accelerator.IsShiftDown() ? MOD_SHIFT : 0;
   modifiers |= accelerator.IsCtrlDown() ? MOD_CONTROL : 0;
   modifiers |= accelerator.IsAltDown() ? MOD_ALT : 0;
+  modifiers |= accelerator.IsCmdDown() ? MOD_WIN : 0;
 
   // Create an observer that registers a hot key for |accelerator|.
   std::unique_ptr<gfx::SingletonHwndHotKeyObserver> observer =
