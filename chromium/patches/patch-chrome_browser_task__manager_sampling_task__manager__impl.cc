$NetBSD$

--- chrome/browser/task_manager/sampling/task_manager_impl.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/task_manager/sampling/task_manager_impl.cc
@@ -229,7 +229,7 @@ void TaskManagerImpl::GetUSERHandles(Tas
 }
 
 int TaskManagerImpl::GetOpenFdCount(TaskId task_id) const {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   return GetTaskGroupByTaskId(task_id)->open_fd_count();
 #else
   return -1;
