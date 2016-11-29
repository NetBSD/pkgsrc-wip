$NetBSD$

--- third_party/WebKit/Source/platform/fonts/FontCache.h.orig	2016-11-10 20:02:26.000000000 +0000
+++ third_party/WebKit/Source/platform/fonts/FontCache.h
@@ -179,7 +179,7 @@ private:
     // Implemented on skia platforms.
     PassRefPtr<SkTypeface> createTypeface(const FontDescription&, const FontFaceCreationParams&, CString& name);
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(FREEBSD) || OS(OPENBSD) || OS(NETBSD)
     static AtomicString getFamilyNameForCharacter(SkFontMgr*, UChar32, const FontDescription&, FontFallbackPriority);
 #endif
 
