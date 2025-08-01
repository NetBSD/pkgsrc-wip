$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/font_render_params.h.orig	2025-07-21 19:32:31.000000000 +0000
+++ ui/gfx/font_render_params.h
@@ -115,7 +115,7 @@ COMPONENT_EXPORT(GFX)
 FontRenderParams GetFontRenderParams(const FontRenderParamsQuery& query,
                                      std::string* family_out);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Clears GetFontRenderParams()'s cache. Intended to be called by tests that are
 // changing Fontconfig's configuration.
 COMPONENT_EXPORT(GFX) void ClearFontRenderParamsCacheForTest();
@@ -125,7 +125,7 @@ COMPONENT_EXPORT(GFX) void ClearFontRend
 COMPONENT_EXPORT(GFX) float GetFontRenderParamsDeviceScaleFactor();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Sets the device scale factor for FontRenderParams to decide
 // if it should enable subpixel positioning.
 COMPONENT_EXPORT(GFX)
