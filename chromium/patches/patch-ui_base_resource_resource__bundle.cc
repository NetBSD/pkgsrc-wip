$NetBSD: patch-ui_base_resource_resource__bundle.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- ui/base/resource/resource_bundle.cc.orig	2011-05-24 08:01:59.000000000 +0000
+++ ui/base/resource/resource_bundle.cc
@@ -129,7 +129,7 @@ gfx::Image& ResourceBundle::GetImageName
   return *GetEmptyImage();
 }
 
-#if !defined(OS_MACOSX) && !defined(OS_LINUX)
+#if !defined(OS_POSIX)
 // Only Mac and Linux have non-Skia native image types. All other platforms use
 // Skia natively, so just use GetImageNamed().
 gfx::Image& ResourceBundle::GetNativeImageNamed(int resource_id) {
