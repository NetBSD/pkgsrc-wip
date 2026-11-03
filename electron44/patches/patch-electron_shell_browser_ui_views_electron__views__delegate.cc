$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/shell/browser/ui/views/electron_views_delegate.cc.orig	2026-10-30 06:33:33.000000000 +0000
+++ electron/shell/browser/ui/views/electron_views_delegate.cc
@@ -36,7 +36,7 @@ void ViewsDelegate::NotifyMenuItemFocuse
                                           int item_count,
                                           bool has_submenu) {}
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
