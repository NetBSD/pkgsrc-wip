$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/gfx/font_render_params.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/font_render_params.h
@@ -115,7 +115,7 @@ GFX_EXPORT FontRenderParams GetFontRende
     const FontRenderParamsQuery& query,
     std::string* family_out);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Clears GetFontRenderParams()'s cache. Intended to be called by tests that are
 // changing Fontconfig's configuration.
 GFX_EXPORT void ClearFontRenderParamsCacheForTest();
@@ -125,7 +125,7 @@ GFX_EXPORT void ClearFontRenderParamsCac
 GFX_EXPORT float GetFontRenderParamsDeviceScaleFactor();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Sets the device scale factor for FontRenderParams to decide
 // if it should enable subpixel positioning.
 GFX_EXPORT void SetFontRenderParamsDeviceScaleFactor(
