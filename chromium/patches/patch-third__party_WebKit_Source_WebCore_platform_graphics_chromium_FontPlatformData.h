$NetBSD: patch-third__party_WebKit_Source_WebCore_platform_graphics_chromium_FontPlatformData.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/platform/graphics/chromium/FontPlatformData.h.orig	2011-04-13 08:12:25.000000000 +0000
+++ third_party/WebKit/Source/WebCore/platform/graphics/chromium/FontPlatformData.h
@@ -33,7 +33,7 @@
 
 #if OS(WINDOWS)
 #include "FontPlatformDataChromiumWin.h"
-#elif OS(LINUX) || OS(FREEBSD)
+#elif OS(LINUX) || OS(BSD)
 #include "FontPlatformDataLinux.h"
 #endif
 
