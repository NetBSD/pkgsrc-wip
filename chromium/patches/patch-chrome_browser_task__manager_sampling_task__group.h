$NetBSD$

--- chrome/browser/task_manager/sampling/task_group.h.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/task_manager/sampling/task_group.h
@@ -39,7 +39,7 @@ constexpr int kUnsupportedVMRefreshFlags
     REFRESH_TYPE_WEBCACHE_STATS | REFRESH_TYPE_NETWORK_USAGE |
     REFRESH_TYPE_NACL | REFRESH_TYPE_IDLE_WAKEUPS | REFRESH_TYPE_HANDLES |
     REFRESH_TYPE_START_TIME | REFRESH_TYPE_CPU_TIME | REFRESH_TYPE_PRIORITY |
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
     REFRESH_TYPE_FD_COUNT |
 #endif
     REFRESH_TYPE_HARD_FAULTS;
@@ -122,7 +122,7 @@ class TaskGroup {
   int nacl_debug_stub_port() const { return nacl_debug_stub_port_; }
 #endif  // BUILDFLAG(ENABLE_NACL)
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   int open_fd_count() const { return open_fd_count_; }
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX)
 
@@ -138,7 +138,7 @@ class TaskGroup {
   void RefreshNaClDebugStubPort(int child_process_unique_id);
   void OnRefreshNaClDebugStubPortDone(int port);
 #endif
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   void OnOpenFdCountRefreshDone(int open_fd_count);
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX)
 
@@ -209,7 +209,7 @@ class TaskGroup {
 #if BUILDFLAG(ENABLE_NACL)
   int nacl_debug_stub_port_;
 #endif  // BUILDFLAG(ENABLE_NACL)
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // The number of file descriptors currently open by the process.
   int open_fd_count_;
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX)
