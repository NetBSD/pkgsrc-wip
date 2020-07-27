$NetBSD$

--- chrome/browser/task_manager/task_manager_observer.h.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/task_manager/task_manager_observer.h
@@ -43,7 +43,7 @@ enum RefreshType {
   // or backgrounded.
   REFRESH_TYPE_PRIORITY = 1 << 13,
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // For observers interested in getting the number of open file descriptors of
   // processes.
   REFRESH_TYPE_FD_COUNT = 1 << 14,
