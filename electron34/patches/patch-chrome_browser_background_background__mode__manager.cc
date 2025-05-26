$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/background/background_mode_manager.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/background/background_mode_manager.cc
@@ -872,7 +872,7 @@ gfx::ImageSkia GetStatusTrayIcon() {
     return gfx::ImageSkia();
 
   return family->CreateExact(size).AsImageSkia();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return *ui::ResourceBundle::GetSharedInstance().GetImageSkiaNamed(
       IDR_PRODUCT_LOGO_128);
 #elif BUILDFLAG(IS_MAC)
