$NetBSD$

--- ui/views/views_delegate.cc.orig	2017-02-02 02:03:13.000000000 +0000
+++ ui/views/views_delegate.cc
@@ -71,7 +71,7 @@ HICON ViewsDelegate::GetDefaultWindowIco
 bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow window) const {
   return false;
 }
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
