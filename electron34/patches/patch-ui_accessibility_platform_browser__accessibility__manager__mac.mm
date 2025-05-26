$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/accessibility/platform/browser_accessibility_manager_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/accessibility/platform/browser_accessibility_manager_mac.mm
@@ -13,13 +13,16 @@
 #include "base/task/single_thread_task_runner.h"
 #include "base/task/task_traits.h"
 #include "base/time/time.h"
+#include "electron/mas.h"
 #include "ui/accelerated_widget_mac/accelerated_widget_mac.h"
 #include "ui/accessibility/ax_role_properties.h"
 #include "ui/accessibility/platform/ax_platform_tree_manager_delegate.h"
 #include "ui/accessibility/platform/ax_private_webkit_constants_mac.h"
 #import "ui/accessibility/platform/browser_accessibility_cocoa.h"
 #import "ui/accessibility/platform/browser_accessibility_mac.h"
+#if !IS_MAS_BUILD()
 #include "ui/base/cocoa/remote_accessibility_api.h"
+#endif
 
 namespace {
 
@@ -227,6 +230,7 @@ void BrowserAccessibilityManagerMac::Fir
         return;
       }
 
+#if !IS_MAS_BUILD()
       BrowserAccessibilityManager* root_manager = GetManagerForRootFrame();
       if (root_manager) {
         BrowserAccessibilityManagerMac* root_manager_mac =
@@ -249,6 +253,7 @@ void BrowserAccessibilityManagerMac::Fir
           return;
         }
       }
+#endif
 
       // Use native VoiceOver support for live regions.
       BrowserAccessibilityCocoa* retained_node = native_node;
@@ -645,6 +650,7 @@ bool BrowserAccessibilityManagerMac::Sho
     return window == [NSApp accessibilityFocusedWindow];
   }
 
+#if !IS_MAS_BUILD()
   // TODO(accessibility): We need a solution to the problem described below.
   // If the window is NSAccessibilityRemoteUIElement, there are some challenges:
   // 1. NSApp is the browser which spawned the PWA, and what it considers the
@@ -673,6 +679,7 @@ bool BrowserAccessibilityManagerMac::Sho
   if ([window isKindOfClass:[NSAccessibilityRemoteUIElement class]]) {
     return true;
   }
+#endif
 
   return false;
 }
