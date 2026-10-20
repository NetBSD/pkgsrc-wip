$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/shell/browser/ui/views/menu_bar.h.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/shell/browser/ui/views/menu_bar.h
@@ -81,7 +81,7 @@ class MenuBar : public views::Accessible
   View* FindAccelChild(char16_t key);
 
   SkColor background_color_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   SkColor enabled_color_;
   SkColor disabled_color_;
 #endif
