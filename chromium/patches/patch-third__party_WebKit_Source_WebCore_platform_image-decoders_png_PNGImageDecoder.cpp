$NetBSD: patch-third__party_WebKit_Source_WebCore_platform_image-decoders_png_PNGImageDecoder.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/platform/image-decoders/png/PNGImageDecoder.cpp.orig	2011-04-13 08:12:31.000000000 +0000
+++ third_party/WebKit/Source/WebCore/platform/image-decoders/png/PNGImageDecoder.cpp
@@ -136,14 +136,31 @@ public:
 
         const char* segment;
         while (unsigned segmentLength = data.getSomeData(segment, m_readOffset)) {
-            m_readOffset += segmentLength;
-            m_currentBufferSize = m_readOffset;
-            png_process_data(m_png, m_info, reinterpret_cast<png_bytep>(const_cast<char*>(segment)), segmentLength);
-            // We explicitly specify the superclass isSizeAvailable() because we
-            // merely want to check if we've managed to set the size, not
-            // (recursively) trigger additional decoding if we haven't.
-            if (sizeOnly ? decoder->ImageDecoder::isSizeAvailable() : decoder->isComplete())
-                return true;
+	    if (sizeOnly) {
+		while (segmentLength > 0)  {
+		    // Unfortunately if we read the image at this point it will be ignored,
+		    // therefore take small steps through the data until the head is read.
+		    // This is crude but effective.
+		    m_currentBufferSize = ++m_readOffset;
+		    png_process_data(m_png, m_info, reinterpret_cast<png_bytep>(const_cast<char*>(segment)), 1);
+
+		    // We explicitly specify the superclass isSizeAvailable() because we
+		    // merely want to check if we've managed to set the size, not
+		    // (recursively) trigger additional decoding if we haven't.
+		    if (decoder->ImageDecoder::isSizeAvailable())
+			return true;
+
+		    --segmentLength;
+		    ++segment;
+		}
+	    } else {
+		// Just process the whole segment at once:
+		m_readOffset += segmentLength;
+		m_currentBufferSize = m_readOffset;
+		png_process_data(m_png, m_info, reinterpret_cast<png_bytep>(const_cast<char*>(segment)), segmentLength);
+		if (decoder->isComplete())
+		    return true;
+	    }
         }
         return false;
     }
@@ -226,7 +243,7 @@ static ColorProfile readColorProfile(png
 #ifdef PNG_iCCP_SUPPORTED
     char* profileName;
     int compressionType;
-    char* profile;
+    png_byte* profile;
     png_uint_32 profileLength;
     if (png_get_iCCP(png, info, &profileName, &compressionType, &profile, &profileLength)) {
         ColorProfile colorProfile;
@@ -241,11 +258,11 @@ void PNGImageDecoder::headerAvailable()
 {
     png_structp png = m_reader->pngPtr();
     png_infop info = m_reader->infoPtr();
-    png_uint_32 width = png->width;
-    png_uint_32 height = png->height;
+    png_uint_32 width = png_get_image_width(png, info);
+    png_uint_32 height = png_get_image_height(png, info);
     
     // Protect against large images.
-    if (png->width > cMaxPNGSize || png->height > cMaxPNGSize) {
+    if (width > cMaxPNGSize || height > cMaxPNGSize) {
         longjmp(JMPBUF(png), 1);
         return;
     }
@@ -316,12 +333,6 @@ void PNGImageDecoder::headerAvailable()
     ASSERT(channels == 3 || channels == 4);
 
     m_reader->setHasAlpha(channels == 4);
-
-    if (m_reader->decodingSizeOnly()) {
-        // If we only needed the size, halt the reader.     
-        m_reader->setReadOffset(m_reader->currentBufferSize() - png->buffer_size);
-        png->buffer_size = 0;
-    }
 }
 
 void PNGImageDecoder::rowAvailable(unsigned char* rowBuffer, unsigned rowIndex, int interlacePass)
@@ -343,7 +354,8 @@ void PNGImageDecoder::rowAvailable(unsig
         // For PNGs, the frame always fills the entire image.
         buffer.setRect(IntRect(IntPoint(), size()));
 
-        if (m_reader->pngPtr()->interlaced)
+        if (png_get_interlace_type(m_reader->pngPtr(), m_reader->infoPtr())
+		!= PNG_INTERLACE_NONE)
             m_reader->createInterlaceBuffer((m_reader->hasAlpha() ? 4 : 3) * size().width() * size().height());
     }
 
