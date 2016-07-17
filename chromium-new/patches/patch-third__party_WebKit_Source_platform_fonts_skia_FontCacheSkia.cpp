$NetBSD$

--- third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp.orig	2016-06-24 01:02:46.000000000 +0000
+++ third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp
@@ -60,7 +60,7 @@ static PassRefPtr<SkTypeface> typefaceFo
 
 namespace blink {
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD)
 // Android special locale for retrieving the color emoji font
 // based on the proposed changes in UTR #51 for introducing
 // an Emoji script code:
@@ -171,7 +171,7 @@ PassRefPtr<SimpleFontData> FontCache::ge
     return fontDataFromFontPlatformData(fontPlatformData, shouldRetain);
 }
 
-#if OS(WIN) || OS(LINUX)
+#if OS(WIN) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD)
 static inline SkFontStyle fontStyle(const FontDescription& fontDescription)
 {
     int width = static_cast<int>(fontDescription.stretch());
@@ -232,7 +232,7 @@ PassRefPtr<SkTypeface> FontCache::create
     }
 #endif
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD) || OS(NETBSD)
     // On linux if the fontManager has been overridden then we should be calling the embedder
     // provided font Manager rather than calling SkTypeface::CreateFromName which may redirect the
     // call to the default font Manager.
