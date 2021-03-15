$NetBSD$

--- src/3rdparty/chromium/ui/views/window/dialog_delegate.cc.orig	2020-07-15 18:56:49.000000000 +0000
+++ src/3rdparty/chromium/ui/views/window/dialog_delegate.cc
@@ -62,7 +62,7 @@ Widget* DialogDelegate::CreateDialogWidg
 
 // static
 bool DialogDelegate::CanSupportCustomFrame(gfx::NativeView parent) {
-#if defined(OS_LINUX) && BUILDFLAG(ENABLE_DESKTOP_AURA)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(ENABLE_DESKTOP_AURA)
   // The new style doesn't support unparented dialogs on Linux desktop.
   return parent != nullptr;
 #else
