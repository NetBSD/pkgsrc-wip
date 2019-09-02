$NetBSD$

--- gdb/tui/tui-winsource.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/tui/tui-winsource.c
@@ -545,6 +545,9 @@ tui_erase_exec_info_content (struct tui_
 {
   struct tui_gen_win_info *exec_info = win_info->execution_info;
 
+  if (exec_info->handle == NULL)
+    return;
+
   werase (exec_info->handle);
   exec_info->refresh_window ();
 }
