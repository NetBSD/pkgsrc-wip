$NetBSD$

--- third_party/WebKit/Source/platform/fonts/FontCache.h.orig	2017-02-02 02:03:10.000000000 +0000
+++ third_party/WebKit/Source/platform/fonts/FontCache.h
@@ -122,7 +122,7 @@ class PLATFORM_EXPORT FontCache {
 #else
   static const AtomicString& legacySystemFontFamily();
 #endif
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD) || OS(NETBSD)
   static void setSystemFontFamily(const AtomicString&);
 #endif
 
@@ -232,7 +232,7 @@ class PLATFORM_EXPORT FontCache {
                                    const FontFaceCreationParams&,
                                    CString& name);
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(FREEBSD) || OS(OPENBSD) || OS(NETBSD)
   static AtomicString getFamilyNameForCharacter(SkFontMgr*,
                                                 UChar32,
                                                 const FontDescription&,
