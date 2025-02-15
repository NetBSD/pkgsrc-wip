$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/electron_browser_main_parts.h.orig	2025-01-21 17:36:55.000000000 +0000
+++ electron/shell/browser/electron_browser_main_parts.h
@@ -119,7 +119,7 @@ class ElectronBrowserMainParts : public 
       const scoped_refptr<base::SingleThreadTaskRunner>& task_runner);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void DetectOzonePlatform();
 #endif
 
@@ -141,7 +141,7 @@ class ElectronBrowserMainParts : public 
   std::unique_ptr<display::Screen> screen_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<ui::DarkModeManagerLinux> dark_mode_manager_;
   std::unique_ptr<ui::LinuxUiGetter> linux_ui_getter_;
 #endif
