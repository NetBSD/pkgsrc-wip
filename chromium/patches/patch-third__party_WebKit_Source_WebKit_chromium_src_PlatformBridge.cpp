$NetBSD: patch-third__party_WebKit_Source_WebKit_chromium_src_PlatformBridge.cpp,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- third_party/WebKit/Source/WebKit/chromium/src/PlatformBridge.cpp.orig	2011-05-24 08:03:03.000000000 +0000
+++ third_party/WebKit/Source/WebKit/chromium/src/PlatformBridge.cpp
@@ -70,7 +70,7 @@
 #include "win/WebThemeEngine.h"
 #endif
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
 #include "linux/WebThemeEngine.h"
 #include "WebFontInfo.h"
 #include "WebFontRenderStyle.h"
@@ -432,7 +432,7 @@ bool PlatformBridge::ensureFontLoaded(HF
 }
 #endif
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
 String PlatformBridge::getFontFamilyForCharacters(const UChar* characters, size_t numCharacters, const char* preferredLocale)
 {
     if (webKitClient()->sandboxSupport())
@@ -773,7 +773,7 @@ void PlatformBridge::paintProgressBar(
         gc->platformContext()->canvas(), barRect, valueRect, determinate, animatedSeconds);
 }
 
-#elif OS(LINUX)
+#elif OS(LINUX) || OS(BSD)
 
 static WebThemeEngine::Part WebThemePart(PlatformBridge::ThemePart part)
 {
