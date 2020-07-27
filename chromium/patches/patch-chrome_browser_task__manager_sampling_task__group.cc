$NetBSD$

--- chrome/browser/task_manager/sampling/task_group.cc.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/task_manager/sampling/task_group.cc
@@ -32,7 +32,7 @@ const int kBackgroundRefreshTypesMask =
 #if defined(OS_WIN)
     REFRESH_TYPE_START_TIME | REFRESH_TYPE_CPU_TIME |
 #endif  // defined(OS_WIN)
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
     REFRESH_TYPE_FD_COUNT |
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX)
 #if BUILDFLAG(ENABLE_NACL)
@@ -113,7 +113,7 @@ TaskGroup::TaskGroup(
 #if BUILDFLAG(ENABLE_NACL)
       nacl_debug_stub_port_(nacl::kGdbDebugStubPortUnknown),
 #endif  // BUILDFLAG(ENABLE_NACL)
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
       open_fd_count_(-1),
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX)
       idle_wakeups_per_second_(-1),
@@ -128,7 +128,7 @@ TaskGroup::TaskGroup(
                    weak_ptr_factory_.GetWeakPtr()),
         base::Bind(&TaskGroup::OnIdleWakeupsRefreshDone,
                    weak_ptr_factory_.GetWeakPtr()),
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
         base::Bind(&TaskGroup::OnOpenFdCountRefreshDone,
                    weak_ptr_factory_.GetWeakPtr()),
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX)
@@ -299,7 +299,7 @@ void TaskGroup::OnRefreshNaClDebugStubPo
 }
 #endif  // BUILDFLAG(ENABLE_NACL)
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 void TaskGroup::OnOpenFdCountRefreshDone(int open_fd_count) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
 
