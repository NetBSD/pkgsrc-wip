$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/renderer_preferences_util.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/renderer_preferences_util.cc
@@ -40,7 +40,7 @@
 #include "ui/views/controls/textfield/textfield.h"
 #endif
 
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #include "ui/linux/linux_ui.h"
@@ -180,7 +180,7 @@ void UpdateFromSystemSettings(blink::Ren
   prefs->caret_blink_interval = views::Textfield::GetCaretBlinkInterval();
 #endif
 
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile);
   if (linux_ui_theme) {
     if (ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme()) {
@@ -203,7 +203,7 @@ void UpdateFromSystemSettings(blink::Ren
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
