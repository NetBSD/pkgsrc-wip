$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc
@@ -143,7 +143,7 @@
 #include "chrome/browser/ui/chrome_pages.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/display/screen.h"
 #endif
 
@@ -162,7 +162,7 @@
 #include "chrome/browser/ui/webui/certificate_manager_localized_strings_provider.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui_factory.h"
 #include "ui/ozone/public/ozone_platform.h"
 #endif
@@ -283,7 +283,7 @@ void AddA11yStrings(content::WebUIDataSo
       {"focusHighlightLabel",
        IDS_SETTINGS_ACCESSIBILITY_FOCUS_HIGHLIGHT_DESCRIPTION},
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       {"overscrollHistoryNavigationTitle",
        IDS_SETTINGS_OVERSCROLL_HISTORY_NAVIGATION_TITLE},
       {"overscrollHistoryNavigationSubtitle",
@@ -556,7 +556,7 @@ void AddAppearanceStrings(content::WebUI
       {"uiFeatureAlignLeft", IDS_SETTINGS_UI_FEATURE_ALIGN_LEFT},
       {"uiFeatureAlignRight", IDS_SETTINGS_UI_FEATURE_ALIGN_RIGHT},
       {"resetToDefault", IDS_SETTINGS_RESET_TO_DEFAULT},
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {"gtkTheme", IDS_SETTINGS_GTK_THEME},
       {"useGtkTheme", IDS_SETTINGS_USE_GTK_THEME},
       {"qtTheme", IDS_SETTINGS_QT_THEME},
@@ -564,7 +564,7 @@ void AddAppearanceStrings(content::WebUI
       {"classicTheme", IDS_SETTINGS_CLASSIC_THEME},
       {"useClassicTheme", IDS_SETTINGS_USE_CLASSIC_THEME},
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {"showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS},
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -590,7 +590,7 @@ void AddAppearanceStrings(content::WebUI
   html_source->AddBoolean("toolbarPinningEnabled",
                           features::IsToolbarPinningEnabled());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool show_custom_chrome_frame = ui::OzonePlatform::GetInstance()
                                       ->GetPlatformRuntimeProperties()
                                       .supports_server_side_window_decorations;
