$NetBSD$

--- third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp.orig	2016-11-10 20:02:26.000000000 +0000
+++ third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp
@@ -62,7 +62,7 @@ static PassRefPtr<SkTypeface> typefaceFo
 
 namespace blink {
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(BSD)
 // Android special locale for retrieving the color emoji font
 // based on the proposed changes in UTR #51 for introducing
 // an Emoji script code:
@@ -183,7 +183,7 @@ PassRefPtr<SkTypeface> FontCache::create
     }
 #endif
 
-#if OS(LINUX) || OS(WIN)
+#if OS(LINUX) || OS(WIN) || OS(BSD)
     // On linux if the fontManager has been overridden then we should be calling the embedder
     // provided font Manager rather than calling SkTypeface::CreateFromName which may redirect the
     // call to the default font Manager.
