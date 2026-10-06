$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gfx/platform_font_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/gfx/platform_font_mac.mm
@@ -19,6 +19,7 @@
 #include "base/numerics/safe_conversions.h"
 #include "base/strings/sys_string_conversions.h"
 #include "base/strings/utf_string_conversions.h"
+#include "electron/mas.h"
 #include "third_party/skia/include/ports/SkTypeface_mac.h"
 #include "ui/gfx/canvas.h"
 #include "ui/gfx/font.h"
@@ -28,9 +29,11 @@ namespace gfx {
 
 using Weight = Font::Weight;
 
+#if !IS_MAS_BUILD()
 extern "C" {
 bool CTFontDescriptorIsSystemUIFont(CTFontDescriptorRef);
 }
+#endif
 
 namespace {
 
@@ -250,7 +253,13 @@ SystemFontTypeFromUndocumentedCTFontRefI
   // TODO(avi, etienneb): Figure out this font stuff.
   base::apple::ScopedCFTypeRef<CTFontDescriptorRef> descriptor(
       CTFontCopyFontDescriptor(font));
+#if IS_MAS_BUILD()
+  CFNumberRef priority = (CFNumberRef)CTFontDescriptorCopyAttribute(descriptor.get(), (CFStringRef)kCTFontPriorityAttribute);
+  SInt64 v;
+  if (CFNumberGetValue(priority, kCFNumberSInt64Type, &v) && v == kCTFontPrioritySystem) {
+#else
   if (CTFontDescriptorIsSystemUIFont(descriptor.get())) {
+#endif
     // Assume it's the standard system font. The fact that this much is known is
     // enough.
     return PlatformFontMac::SystemFontType::kGeneral;
