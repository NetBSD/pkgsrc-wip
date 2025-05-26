$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/webui/app_settings/web_app_settings_ui.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/webui/app_settings/web_app_settings_ui.h
@@ -14,13 +14,13 @@
 #include "ui/webui/mojo_web_ui_controller.h"
 #include "ui/webui/resources/cr_components/app_management/app_management.mojom-forward.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/common/webui_url_constants.h"
 #include "content/public/browser/webui_config.h"
 #include "content/public/common/url_constants.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class WebAppSettingsUI;
 
 class WebAppSettingsUIConfig
