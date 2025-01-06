$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/webui/accessibility/accessibility_ui.h.orig	2024-10-18 12:34:03.608132800 +0000
+++ chrome/browser/ui/webui/accessibility/accessibility_ui.h
@@ -30,6 +30,8 @@ class ScopedAccessibilityMode;
 class WebContents;
 }  // namespace content
 
+class ElectronAccessibilityUIMessageHandler;
+
 namespace user_prefs {
 class PrefRegistrySyncable;
 }  // namespace user_prefs
@@ -82,6 +84,8 @@ class AccessibilityUIMessageHandler : pu
   static void RegisterProfilePrefs(user_prefs::PrefRegistrySyncable* registry);
 
  private:
+  friend class ElectronAccessibilityUIMessageHandler;
+
   // Applies `mode` to `web_contents` for the lifetime of the accessibility
   // UI page.
   void SetAccessibilityModeForWebContents(content::WebContents* web_contents,
