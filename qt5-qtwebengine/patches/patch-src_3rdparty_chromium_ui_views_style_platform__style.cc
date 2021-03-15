$NetBSD$

--- src/3rdparty/chromium/ui/views/style/platform_style.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/views/style/platform_style.cc
@@ -74,7 +74,7 @@ gfx::Range PlatformStyle::RangeToDeleteB
 
 #endif  // OS_MACOSX
 
-#if !BUILDFLAG(ENABLE_DESKTOP_AURA) || !defined(OS_LINUX)
+#if !BUILDFLAG(ENABLE_DESKTOP_AURA) || (!defined(OS_LINUX) && !defined(OS_BSD))
 // static
 std::unique_ptr<Border> PlatformStyle::CreateThemedLabelButtonBorder(
     LabelButton* button) {
