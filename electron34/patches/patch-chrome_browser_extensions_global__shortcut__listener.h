$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/extensions/global_shortcut_listener.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/extensions/global_shortcut_listener.h
@@ -34,6 +34,8 @@ class GlobalShortcutListener {
 
   static GlobalShortcutListener* GetInstance();
 
+  static void SetShouldUseInternalMediaKeyHandling(bool should_use);
+
   // Register an observer for when a certain |accelerator| is struck. Returns
   // true if register successfully, or false if 1) the specificied |accelerator|
   // has been registered by another caller or other native applications, or
