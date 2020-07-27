$NetBSD$

--- ui/views/bubble/bubble_dialog_delegate_view.cc.orig	2020-07-15 18:56:49.000000000 +0000
+++ ui/views/bubble/bubble_dialog_delegate_view.cc
@@ -283,7 +283,7 @@ Widget* BubbleDialogDelegate::CreateBubb
   bubble_delegate->SetAnchorView(bubble_delegate->GetAnchorView());
   Widget* bubble_widget = CreateBubbleWidget(bubble_delegate);
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
   // Linux clips bubble windows that extend outside their parent window bounds.
   // Mac never adjusts.
   bubble_delegate->set_adjust_if_offscreen(false);
