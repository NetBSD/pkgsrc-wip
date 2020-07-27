$NetBSD$

--- ui/views/selection_controller.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ ui/views/selection_controller.cc
@@ -23,7 +23,7 @@ SelectionController::SelectionController
       delegate_(delegate),
       handles_selection_clipboard_(false) {
 // On Linux, update the selection clipboard on a text selection.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   set_handles_selection_clipboard(true);
 #endif
 
