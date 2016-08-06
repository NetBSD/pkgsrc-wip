$NetBSD$

--- base/process/process_iterator.h.orig	2016-08-05 17:13:37.000000000 +0000
+++ base/process/process_iterator.h
@@ -22,7 +22,7 @@
 #if defined(OS_WIN)
 #include <windows.h>
 #include <tlhelp32.h>
-#elif defined(OS_MACOSX) || defined(OS_OPENBSD)
+#elif defined(OS_MACOSX) || defined(OS_NETBSD) || defined(OS_OPENBSD)
 #include <sys/sysctl.h>
 #elif defined(OS_FREEBSD)
 #include <sys/user.h>
@@ -110,7 +110,11 @@ class BASE_EXPORT ProcessIterator {
   HANDLE snapshot_;
   bool started_iteration_;
 #elif defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_NETBSD)
+  std::vector<kinfo_proc2> kinfo_procs_;
+#else
   std::vector<kinfo_proc> kinfo_procs_;
+#endif
   size_t index_of_kinfo_proc_;
 #elif defined(OS_POSIX)
   DIR* procfs_dir_;
