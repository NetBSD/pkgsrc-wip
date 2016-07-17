$NetBSD$

--- third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp.orig	2016-06-24 01:02:46.000000000 +0000
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp
@@ -357,7 +357,7 @@ PassRefPtr<SharedBuffer> FontPlatformDat
 {
     RefPtr<SharedBuffer> buffer;
 
-    SkFontTableTag tag = WTF::bswap32(table);
+    SkFontTableTag tag = bswap32(table);
     const size_t tableSize = m_typeface->getTableSize(tag);
     if (tableSize) {
         Vector<char> tableBuffer(tableSize);
