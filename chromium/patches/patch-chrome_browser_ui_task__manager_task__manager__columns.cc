$NetBSD$

--- chrome/browser/ui/task_manager/task_manager_columns.cc.orig	2020-07-08 21:40:36.000000000 +0000
+++ chrome/browser/ui/task_manager/task_manager_columns.cc
@@ -93,7 +93,7 @@ const TableColumnData kColumns[] = {
      base::size("100000") * kCharWidth, -1, true, false, false},
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
     {IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN, ui::TableColumn::RIGHT, -1, 0,
      base::size("999") * kCharWidth, -1, true, false, false},
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX)
