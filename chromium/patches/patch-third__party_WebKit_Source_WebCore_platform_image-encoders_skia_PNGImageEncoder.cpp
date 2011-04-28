$NetBSD: patch-third__party_WebKit_Source_WebCore_platform_image-encoders_skia_PNGImageEncoder.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/platform/image-encoders/skia/PNGImageEncoder.cpp.orig	2011-04-13 08:12:30.000000000 +0000
+++ third_party/WebKit/Source/WebCore/platform/image-encoders/skia/PNGImageEncoder.cpp
@@ -43,7 +43,7 @@ namespace WebCore {
 
 static void writeOutput(png_structp png, png_bytep data, png_size_t size)
 {
-    static_cast<Vector<unsigned char>*>(png->io_ptr)->append(data, size);
+    static_cast<Vector<unsigned char>*>(png_get_io_ptr(png))->append(data, size);
 }
 
 static void preMultipliedBGRAtoRGBA(const SkPMColor* input, int pixels, unsigned char* output)
