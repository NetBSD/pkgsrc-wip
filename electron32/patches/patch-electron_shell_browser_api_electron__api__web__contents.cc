$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/api/electron_api_web_contents.cc.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/shell/browser/api/electron_api_web_contents.cc
@@ -153,11 +153,11 @@
 #include "ui/base/cocoa/defaults_utils.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/font_render_params.h"
 #endif
 
@@ -520,7 +520,7 @@ std::optional<base::TimeDelta> GetCursor
       ui::TextInsertionCaretBlinkPeriodFromDefaults());
   if (system_value)
     return *system_value;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance())
     return linux_ui->GetCursorBlinkInterval();
 #elif BUILDFLAG(IS_WIN)
@@ -874,7 +874,7 @@ void WebContents::InitWithSessionAndOpti
   accept_languages.pop_back();
   prefs->accept_languages = accept_languages;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Update font settings.
   static const gfx::FontRenderParams params(
       gfx::GetFontRenderParams(gfx::FontRenderParamsQuery(), nullptr));
@@ -2619,7 +2619,7 @@ void WebContents::ForcefullyCrashRendere
 
   content::RenderProcessHost* rph = rwh->GetProcess();
   if (rph) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // A generic |CrashDumpHungChildProcess()| is not implemented for Linux.
     // Instead we send an explicit IPC to crash on the renderer's IO thread.
     rph->ForceCrash();
@@ -3298,7 +3298,7 @@ void WebContents::CopyImageAt(int x, int
 void WebContents::Focus() {
   // Focusing on WebContents does not automatically focus the window on macOS
   // and Linux, do it manually to match the behavior on Windows.
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (owner_window())
     owner_window()->Focus(true);
 #endif
@@ -4159,7 +4159,7 @@ ui::ImageModel WebContents::GetDevToolsW
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WebContents::GetDevToolsWindowWMClass(std::string* name,
                                            std::string* class_name) {
   *class_name = Browser::Get()->GetName();
