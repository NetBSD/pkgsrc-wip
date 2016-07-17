$NetBSD$

--- third_party/WebKit/Source/platform/fonts/FontCache.h.orig	2016-06-24 01:02:46.000000000 +0000
+++ third_party/WebKit/Source/platform/fonts/FontCache.h
@@ -174,7 +174,7 @@ private:
     // Implemented on skia platforms.
     PassRefPtr<SkTypeface> createTypeface(const FontDescription&, const FontFaceCreationParams&, CString& name);
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(FREEBSD) || OS(OPENBSD) || OS(NETBSD)
     static AtomicString getFamilyNameForCharacter(SkFontMgr*, UChar32, const FontDescription&, FontFallbackPriority);
 #endif
 
