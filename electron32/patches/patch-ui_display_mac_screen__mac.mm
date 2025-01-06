$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/display/mac/screen_mac.mm.orig	2024-10-18 12:35:12.452378700 +0000
+++ ui/display/mac/screen_mac.mm
@@ -171,7 +171,17 @@ DisplayMac BuildDisplayForScreen(NSScree
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
   {
