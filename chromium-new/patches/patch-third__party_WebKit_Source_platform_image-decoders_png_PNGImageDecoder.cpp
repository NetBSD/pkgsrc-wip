$NetBSD$

--- third_party/WebKit/Source/platform/image-decoders/png/PNGImageDecoder.cpp.orig	2016-06-24 01:02:46.000000000 +0000
+++ third_party/WebKit/Source/platform/image-decoders/png/PNGImageDecoder.cpp
@@ -234,7 +234,7 @@ void PNGImageDecoder::headerAvailable()
 #endif
             png_uint_32 profileLength = 0;
             if (png_get_iCCP(png, info, &profileName, &compressionType, &profile, &profileLength)) {
-                setColorProfileAndTransform(profile, profileLength, imageHasAlpha, false /* useSRGB */);
+                setColorProfileAndTransform(reinterpret_cast<const char*>(profile), profileLength, imageHasAlpha, false /* useSRGB */);
             }
         }
 #endif // PNG_iCCP_SUPPORTED
