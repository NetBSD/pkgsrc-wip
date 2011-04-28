$NetBSD: patch-base_process__util.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/process_util.h.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/process_util.h
@@ -14,14 +14,20 @@
 #if defined(OS_WIN)
 #include <windows.h>
 #include <tlhelp32.h>
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_NETBSD)
 // kinfo_proc is defined in <sys/sysctl.h>, but this forward declaration
 // is sufficient for the vector<kinfo_proc> below.
+#if defined(OS_MACOSX) || defined(OS_OPENBSD)
 struct kinfo_proc;
+#else
+struct kinfo_proc2;
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
@@ -161,7 +167,7 @@ void CloseProcessHandle(ProcessHandle pr
 // Win XP SP1 as well.
 ProcessId GetProcId(ProcessHandle process);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_NETBSD)
 // Returns the ID for the parent of the given process.
 ProcessId GetParentProcessId(ProcessHandle process);
 
@@ -172,7 +178,8 @@ FilePath GetProcessExecutablePath(Proces
 // CPU-related ticks.  Returns -1 on parse error.
 // Exposed for testing.
 int ParseProcStatCPU(const std::string& input);
-
+#endif
+#if defined(OS_LINUX)
 static const char kAdjustOOMScoreSwitch[] = "--adjust-oom-score";
 
 // This adjusts /proc/process/oom_adj so the Linux OOM killer will prefer
@@ -439,8 +446,12 @@ class ProcessIterator {
 #if defined(OS_WIN)
   HANDLE snapshot_;
   bool started_iteration_;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_NETBSD)
+#if defined(OS_MACOSX) || defined(OS_OPENBSD)
   std::vector<kinfo_proc> kinfo_procs_;
+#else
+  std::vector<kinfo_proc2> kinfo_procs_;
+#endif
   size_t index_of_kinfo_proc_;
 #elif defined(OS_POSIX)
   DIR *procfs_dir_;
