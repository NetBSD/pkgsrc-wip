$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/web_applications/os_integration/web_app_shortcut.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/web_applications/os_integration/web_app_shortcut.h
@@ -21,7 +21,7 @@
 #include "ui/gfx/image/image_family.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/os_integration/web_app_shortcut_linux.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -74,7 +74,7 @@ struct ShortcutInfo {
   // the installed PWA experience and thus the icons are not designed to be
   // displayed on an OS dock.
   bool is_diy_app = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::set<DesktopActionInfo> actions;
 #endif  // BUILDFLAG(IS_LINUX)
 
