$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/process/process_iterator.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/process/process_iterator.h
@@ -25,7 +25,7 @@
 #include <windows.h>
 
 #include <tlhelp32.h>
-#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_NETBSD)
 #include <sys/sysctl.h>
 #elif BUILDFLAG(IS_FREEBSD)
 #include <sys/user.h>
@@ -117,7 +117,11 @@ class BASE_EXPORT ProcessIterator {
   HANDLE snapshot_;
   bool started_iteration_ = false;
 #elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
+# if BUILDFLAG(IS_NETBSD)
+  std::vector<kinfo_proc2> kinfo_procs_;
+# else
   std::vector<kinfo_proc> kinfo_procs_;
+# endif
   size_t index_of_kinfo_proc_ = 0;
 #elif BUILDFLAG(IS_POSIX)
   struct DIRClose {
