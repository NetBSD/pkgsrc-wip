$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ui_base_switches.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ ui/base/ui_base_switches.h
@@ -37,13 +37,13 @@ inline constexpr char kDisableModalAnima
 inline constexpr char kShowMacOverlayBorders[] = "show-mac-overlay-borders";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Specifies system font family name. Improves determinism when rendering pages
 // in headless mode.
 inline constexpr char kSystemFontFamily[] = "system-font-family";
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Specify the toolkit used to construct the Linux GUI.
 inline constexpr char kUiToolkitFlag[] = "ui-toolkit";
 // Specify the GTK version to be loaded.
