$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gfx/platform_font_mac.mm.orig	2024-10-18 12:35:12.692283200 +0000
+++ ui/gfx/platform_font_mac.mm
@@ -28,9 +28,11 @@ namespace gfx {
 
 using Weight = Font::Weight;
 
+#if !IS_MAS_BUILD()
 extern "C" {
 bool CTFontDescriptorIsSystemUIFont(CTFontDescriptorRef);
 }
+#endif
 
 namespace {
 
@@ -245,7 +247,13 @@ SystemFontTypeFromUndocumentedCTFontRefI
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
