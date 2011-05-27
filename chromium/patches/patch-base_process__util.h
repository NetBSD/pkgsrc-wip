$NetBSD: patch-base_process__util.h,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- base/process_util.h.orig	2011-05-24 08:01:33.000000000 +0000
+++ base/process_util.h
@@ -14,14 +14,20 @@
 #if defined(OS_WIN)
 #include <windows.h>
 #include <tlhelp32.h>
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
 // kinfo_proc is defined in <sys/sysctl.h>, but this forward declaration
 // is sufficient for the vector<kinfo_proc> below.
+#if defined(OS_NETBSD)
+struct kinfo_proc2;
+#else
 struct kinfo_proc;
+#endif
 // malloc_zone_t is defined in <malloc/malloc.h>, but this forward declaration
 // is sufficient for GetPurgeableZone() below.
 typedef struct _malloc_zone_t malloc_zone_t;
+#if defined(OS_MACOSX)
 #include <mach/mach.h>
+#endif
 #elif defined(OS_POSIX)
 #include <dirent.h>
 #include <limits.h>
@@ -161,10 +167,11 @@ void CloseProcessHandle(ProcessHandle pr
 // Win XP SP1 as well.
 ProcessId GetProcId(ProcessHandle process);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Returns the path to the executable of the given process.
 FilePath GetProcessExecutablePath(ProcessHandle process);
 
+#elif defined(OS_LINUX)
 // Parse the data found in /proc/<pid>/stat and return the sum of the
 // CPU-related ticks.  Returns -1 on parse error.
 // Exposed for testing.
@@ -439,8 +446,12 @@ class ProcessIterator {
 #if defined(OS_WIN)
   HANDLE snapshot_;
   bool started_iteration_;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_NETBSD)
+  std::vector<kinfo_proc2> kinfo_procs_;
+#else
   std::vector<kinfo_proc> kinfo_procs_;
+#endif
   size_t index_of_kinfo_proc_;
 #elif defined(OS_POSIX)
   DIR *procfs_dir_;
