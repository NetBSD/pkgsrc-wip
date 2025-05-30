$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/ui/views/menu_bar.h.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/shell/browser/ui/views/menu_bar.h
@@ -84,7 +84,7 @@ class MenuBar : public views::Accessible
   View* FindAccelChild(char16_t key);
 
   SkColor background_color_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   SkColor enabled_color_;
   SkColor disabled_color_;
 #endif
