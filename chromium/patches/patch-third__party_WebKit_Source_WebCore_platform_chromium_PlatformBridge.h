$NetBSD: patch-third__party_WebKit_Source_WebCore_platform_chromium_PlatformBridge.h,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- third_party/WebKit/Source/WebCore/platform/chromium/PlatformBridge.h.orig	2011-05-24 08:03:23.000000000 +0000
+++ third_party/WebKit/Source/WebCore/platform/chromium/PlatformBridge.h
@@ -148,7 +148,7 @@ public:
 #if OS(WINDOWS)
     static bool ensureFontLoaded(HFONT);
 #endif
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
     static void getRenderStyleForStrike(const char* family, int sizeAndStyle, FontRenderStyle* result);
     static String getFontFamilyForCharacters(const UChar*, size_t numCharacters, const char* preferredLocale);
 #endif
@@ -265,7 +265,7 @@ public:
         GraphicsContext*, int part, int state, int classicState, const IntRect&);
     static void paintProgressBar(
         GraphicsContext*, const IntRect& barRect, const IntRect& valueRect, bool determinate, double animatedSeconds);
-#elif OS(LINUX)
+#elif OS(LINUX) || OS(BSD)
     // The UI part which is being accessed.
     enum ThemePart {
         // ScrollbarTheme parts
