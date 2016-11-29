$NetBSD$

--- ui/views/window/dialog_delegate.cc.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/views/window/dialog_delegate.cc
@@ -56,7 +56,7 @@ Widget::InitParams DialogDelegate::GetDi
   params.bounds = bounds;
   DialogDelegate* dialog = delegate->AsDialogDelegate();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // The new style doesn't support unparented dialogs on Linux desktop.
   if (dialog)
     dialog->supports_custom_frame_ &= parent != NULL;
