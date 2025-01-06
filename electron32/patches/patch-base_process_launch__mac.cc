$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/process/launch_mac.cc.orig	2024-10-18 12:33:59.794258600 +0000
+++ base/process/launch_mac.cc
@@ -21,13 +21,18 @@
 #include "base/threading/scoped_blocking_call.h"
 #include "base/threading/thread_restrictions.h"
 #include "base/trace_event/base_tracing.h"
+#if IS_MAS_BUILD()
+#include <sys/syscall.h>
+#endif
 
 extern "C" {
 // Changes the current thread's directory to a path or directory file
 // descriptor.
+#if !IS_MAS_BUILD()
 int pthread_chdir_np(const char* dir);
 
 int pthread_fchdir_np(int fd);
+#endif
 
 int responsibility_spawnattrs_setdisclaim(posix_spawnattr_t attrs,
                                           int disclaim);
@@ -99,13 +104,27 @@ class PosixSpawnFileActions {
 
 #if !BUILDFLAG(IS_MAC)
 int ChangeCurrentThreadDirectory(const char* path) {
+#if IS_MAS_BUILD()
+  #pragma clang diagnostic push
+  #pragma clang diagnostic ignored "-Wdeprecated-declarations"
+  return syscall(SYS___pthread_chdir, path);
+  #pragma clang diagnostic pop
+#else
   return pthread_chdir_np(path);
+#endif
 }
 
 // The recommended way to unset a per-thread cwd is to set a new value to an
 // invalid file descriptor, per libpthread-218.1.3/private/private.h.
 int ResetCurrentThreadDirectory() {
+#if IS_MAS_BUILD()
+  #pragma clang diagnostic push
+  #pragma clang diagnostic ignored "-Wdeprecated-declarations"
+  return syscall(SYS___pthread_fchdir, -1);
+  #pragma clang diagnostic pop
+#else
   return pthread_fchdir_np(-1);
+#endif
 }
 #endif
 
@@ -226,7 +245,7 @@ Process LaunchProcess(const std::vector<
     file_actions.Inherit(STDERR_FILENO);
   }
 
-#if BUILDFLAG(IS_MAC)
+#if 0
   if (options.disclaim_responsibility) {
     DPSXCHECK(responsibility_spawnattrs_setdisclaim(attr.get(), 1));
   }
