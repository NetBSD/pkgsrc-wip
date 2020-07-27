$NetBSD$

--- chrome/browser/background/background_mode_manager.cc.orig	2020-07-08 21:40:33.000000000 +0000
+++ chrome/browser/background/background_mode_manager.cc
@@ -849,7 +849,7 @@ gfx::ImageSkia GetStatusTrayIcon() {
     return gfx::ImageSkia();
 
   return family->CreateExact(size).AsImageSkia();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return *ui::ResourceBundle::GetSharedInstance().GetImageSkiaNamed(
       IDR_PRODUCT_LOGO_128);
 #elif defined(OS_MACOSX)
