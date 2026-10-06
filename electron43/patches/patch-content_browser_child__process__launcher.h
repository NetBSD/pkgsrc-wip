$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/child_process_launcher.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/child_process_launcher.h
@@ -33,6 +33,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "base/win/windows_types.h"
+#include "base/win/scoped_handle.h"
 #endif
 
 #if BUILDFLAG(IS_POSIX)
@@ -189,7 +190,10 @@ struct ChildProcessLauncherFileData {
       delete;
   ~ChildProcessLauncherFileData();
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN)
+  base::win::ScopedHandle stdout_handle;
+  base::win::ScopedHandle stderr_handle;
+#elif BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
   // Files opened by the browser and passed as corresponding file descriptors
   // in the child process. If a FilePath is provided, the file will be opened
   // and the descriptor cached for future process launches. If a ScopedFD is
@@ -204,6 +208,15 @@ struct ChildProcessLauncherFileData {
   std::map<std::string, absl::variant<base::FilePath, base::ScopedFD>>
       files_to_preload;
 #endif
+
+#if BUILDFLAG(IS_POSIX)
+  // Map of file descriptors to pass. This is used instead of
+  // `files_to_preload` when the data needs to be installed at an exact FD
+  // number in the new process.
+  //
+  // Currently only supported on POSIX platforms.
+  std::map<int, base::ScopedFD> additional_remapped_fds;
+#endif
 };
 
 // Launches a process asynchronously and notifies the client of the process
