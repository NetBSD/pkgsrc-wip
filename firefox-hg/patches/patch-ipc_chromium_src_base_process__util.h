$NetBSD: patch-ipc_chromium_src_base_process__util.h,v 1.1 2014/09/29 10:46:25 thomasklausner Exp $

--- ipc/chromium/src/base/process_util.h.orig	2014-09-28 08:30:05.000000000 +0000
+++ ipc/chromium/src/base/process_util.h
@@ -17,7 +17,7 @@
 #ifndef STDOUT_FILENO
 #define STDOUT_FILENO 1
 #endif
-#elif defined(OS_LINUX) || defined(__GLIBC__)
+#elif defined(OS_LINUX) || defined(__GLIBC__) || defined(OS_SOLARIS)
 #include <dirent.h>
 #include <limits.h>
 #include <sys/types.h>
@@ -41,6 +41,9 @@
 typedef PROCESSENTRY32 ProcessEntry;
 typedef IO_COUNTERS IoCounters;
 #elif defined(OS_POSIX)
+#ifndef NAME_MAX
+#define NAME_MAX _POSIX_NAME_MAX
+#endif
 // TODO(port): we should not rely on a Win32 structure.
 struct ProcessEntry {
   int pid;
