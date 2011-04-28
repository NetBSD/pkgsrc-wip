$NetBSD: patch-third__party_WebKit_Source_WebCore_platform_graphics_skia_FontCustomPlatformData.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/platform/graphics/skia/FontCustomPlatformData.h.orig	2011-04-13 08:12:26.000000000 +0000
+++ third_party/WebKit/Source/WebCore/platform/graphics/skia/FontCustomPlatformData.h
@@ -40,7 +40,7 @@
 #if OS(WINDOWS)
 #include "PlatformString.h"
 #include <windows.h>
-#elif OS(LINUX) || OS(FREEBSD) || PLATFORM(BREWMP)
+#elif OS(LINUX) || OS(BSD) || PLATFORM(BREWMP)
 #include "SkTypeface.h"
 #endif
 
@@ -57,7 +57,7 @@ public:
         : m_fontReference(fontReference)
         , m_name(name)
     {}
-#elif OS(LINUX) || OS(FREEBSD) || PLATFORM(BREWMP)
+#elif OS(LINUX) || OS(BSD) || PLATFORM(BREWMP)
     explicit FontCustomPlatformData(SkTypeface* typeface)
         : m_fontReference(typeface)
     {}
@@ -73,7 +73,7 @@ public:
 #if OS(WINDOWS)
     HANDLE m_fontReference;
     String m_name;
-#elif OS(LINUX) || OS(FREEBSD) || PLATFORM(BREWMP)
+#elif OS(LINUX) || OS(BSD) || PLATFORM(BREWMP)
     SkTypeface* m_fontReference;
 #endif
 };
