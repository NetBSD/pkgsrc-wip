$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/file_system_access/file_system_access_local_path_watcher.cc.orig	2024-10-18 12:34:12.423414500 +0000
+++ content/browser/file_system_access/file_system_access_local_path_watcher.cc
@@ -62,7 +62,7 @@ void FileSystemAccessLocalPathWatcher::I
   FilePathWatcher::WatchOptions watch_options{
       .type = scope().IsRecursive() ? FilePathWatcher::Type::kRecursive
                                     : FilePathWatcher::Type::kNonRecursive,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       // Note: `report_modified_path` is also present on Android
       // and Fuchsia. Update this switch if support for watching
       // the local file system is added on those platforms.
