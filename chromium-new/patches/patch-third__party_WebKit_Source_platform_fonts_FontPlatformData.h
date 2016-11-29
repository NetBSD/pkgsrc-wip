$NetBSD$

--- third_party/WebKit/Source/platform/fonts/FontPlatformData.h.orig	2016-11-10 20:02:26.000000000 +0000
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.h
@@ -46,9 +46,9 @@
 #include "wtf/text/CString.h"
 #include "wtf/text/StringImpl.h"
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
 #include "platform/fonts/linux/FontRenderStyle.h"
-#endif // OS(LINUX) || OS(ANDROID)
+#endif // OS(LINUX) || OS(ANDROID) || OS(BSD)
 
 #if OS(MACOSX)
 OBJC_CLASS NSFont;
@@ -126,7 +126,7 @@ public:
     PassRefPtr<OpenTypeVerticalData> verticalData() const;
     PassRefPtr<SharedBuffer> openTypeTable(SkFontTableTag) const;
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
     // The returned styles are all actual styles without FontRenderStyle::NoPreference.
     const FontRenderStyle& getFontRenderStyle() const { return m_style; }
 #endif
@@ -152,7 +152,7 @@ public:
     bool m_syntheticItalic;
     FontOrientation m_orientation;
 private:
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
     FontRenderStyle m_style;
 #endif
 
