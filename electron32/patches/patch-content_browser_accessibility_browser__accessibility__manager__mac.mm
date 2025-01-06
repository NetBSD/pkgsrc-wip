$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/accessibility/browser_accessibility_manager_mac.mm.orig	2024-10-18 12:34:11.991639100 +0000
+++ content/browser/accessibility/browser_accessibility_manager_mac.mm
@@ -20,7 +20,9 @@
 #include "ui/accessibility/ax_role_properties.h"
 #include "ui/accessibility/platform/ax_platform_tree_manager_delegate.h"
 #include "ui/accessibility/platform/ax_private_webkit_constants_mac.h"
+#if !IS_MAS_BUILD()
 #include "ui/base/cocoa/remote_accessibility_api.h"
+#endif
 
 namespace {
 
@@ -224,6 +226,7 @@ void BrowserAccessibilityManagerMac::Fir
         return;
       }
 
+#if !IS_MAS_BUILD()
       BrowserAccessibilityManager* root_manager = GetManagerForRootFrame();
       if (root_manager) {
         BrowserAccessibilityManagerMac* root_manager_mac =
@@ -246,6 +249,7 @@ void BrowserAccessibilityManagerMac::Fir
           return;
         }
       }
+#endif
 
       // Use native VoiceOver support for live regions.
       BrowserAccessibilityCocoa* retained_node = native_node;
@@ -646,6 +650,7 @@ bool BrowserAccessibilityManagerMac::Sho
     return window == [NSApp accessibilityFocusedWindow];
   }
 
+#if !IS_MAS_BUILD()
   // TODO(accessibility): We need a solution to the problem described below.
   // If the window is NSAccessibilityRemoteUIElement, there are some challenges:
   // 1. NSApp is the browser which spawned the PWA, and what it considers the
@@ -674,6 +679,7 @@ bool BrowserAccessibilityManagerMac::Sho
   if ([window isKindOfClass:[NSAccessibilityRemoteUIElement class]]) {
     return true;
   }
+#endif
 
   return false;
 }
