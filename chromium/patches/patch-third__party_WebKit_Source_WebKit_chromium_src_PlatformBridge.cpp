$NetBSD: patch-third__party_WebKit_Source_WebKit_chromium_src_PlatformBridge.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebKit/chromium/src/PlatformBridge.cpp.orig	2011-04-13 08:12:09.000000000 +0000
+++ third_party/WebKit/Source/WebKit/chromium/src/PlatformBridge.cpp
@@ -70,7 +70,7 @@
 #include "win/WebThemeEngine.h"
 #endif
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
 #include "linux/WebThemeEngine.h"
 #include "WebFontInfo.h"
 #include "WebFontRenderStyle.h"
@@ -436,7 +436,7 @@ bool PlatformBridge::ensureFontLoaded(HF
 }
 #endif
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
 String PlatformBridge::getFontFamilyForCharacters(const UChar* characters, size_t numCharacters)
 {
     if (webKitClient()->sandboxSupport())
@@ -778,7 +778,7 @@ void PlatformBridge::paintProgressBar(
         gc->platformContext()->canvas(), barRect, valueRect, determinate, animatedSeconds);
 }
 
-#elif OS(LINUX)
+#elif OS(LINUX) || OS(BSD)
 
 static WebThemeEngine::Part WebThemePart(PlatformBridge::ThemePart part)
 {
