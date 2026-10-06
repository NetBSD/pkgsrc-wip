$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/display/mac/screen_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/display/mac/screen_mac.mm
@@ -30,6 +30,7 @@
 #include "base/trace_event/trace_event.h"
 #include "build/build_config.h"
 #include "components/device_event_log/device_event_log.h"
+#include "electron/mas.h"
 #include "ui/display/display.h"
 #include "ui/display/display_change_notifier.h"
 #include "ui/display/util/display_util.h"
@@ -176,7 +177,17 @@ DisplayMac BuildDisplayForScreen(NSScree
     display.set_color_depth(Display::kDefaultBitsPerPixel);
     display.set_depth_per_component(Display::kDefaultBitsPerComponent);
   }
+#if IS_MAS_BUILD()
+  // This is equivalent to the CGDisplayUsesForceToGray() API as at 2018-08-06,
+  // but avoids usage of the private API.
+  CFStringRef app = CFSTR("com.apple.CoreGraphics");
+  CFStringRef key = CFSTR("DisplayUseForcedGray");
+  Boolean key_valid = false;
+  display.set_is_monochrome(
+      CFPreferencesGetAppBooleanValue(key, app, &key_valid));
+#else
   display.set_is_monochrome(CGDisplayUsesForceToGray());
+#endif
 
   // Query the display's refresh rate.
   if (@available(macos 12.0, *)) {
