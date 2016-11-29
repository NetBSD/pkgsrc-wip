$NetBSD$

--- third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp.orig	2016-11-10 20:02:26.000000000 +0000
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp
@@ -93,7 +93,7 @@ FontPlatformData::FontPlatformData(const
     , m_syntheticBold(source.m_syntheticBold)
     , m_syntheticItalic(source.m_syntheticItalic)
     , m_orientation(source.m_orientation)
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
     , m_style(source.m_style)
 #endif
     , m_harfBuzzFace(nullptr)
@@ -115,7 +115,7 @@ FontPlatformData::FontPlatformData(const
     , m_syntheticBold(src.m_syntheticBold)
     , m_syntheticItalic(src.m_syntheticItalic)
     , m_orientation(src.m_orientation)
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
     , m_style(FontRenderStyle::querySystem(m_family, m_textSize, m_typeface->style()))
 #endif
     , m_harfBuzzFace(nullptr)
@@ -142,7 +142,7 @@ FontPlatformData::FontPlatformData(PassR
     , m_syntheticBold(syntheticBold)
     , m_syntheticItalic(syntheticItalic)
     , m_orientation(orientation)
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
     , m_style(FontRenderStyle::querySystem(m_family, m_textSize, m_typeface->style()))
 #endif
     , m_isHashTableDeletedValue(false)
@@ -188,7 +188,7 @@ const FontPlatformData& FontPlatformData
     m_syntheticItalic = other.m_syntheticItalic;
     m_harfBuzzFace = nullptr;
     m_orientation = other.m_orientation;
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
     m_style = other.m_style;
 #endif
 
@@ -216,7 +216,7 @@ bool FontPlatformData::operator==(const 
         && m_isHashTableDeletedValue == a.m_isHashTableDeletedValue
         && m_syntheticBold == a.m_syntheticBold
         && m_syntheticItalic == a.m_syntheticItalic
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
         && m_style == a.m_style
 #endif
         && m_orientation == a.m_orientation;
