$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/file_system_access/file_system_access_local_path_watcher.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/content/browser/file_system_access/file_system_access_local_path_watcher.cc
@@ -63,7 +63,7 @@ void FileSystemAccessLocalPathWatcher::I
   base::FilePathWatcher::WatchOptions watch_options {
     .type = scope().IsRecursive() ? base::FilePathWatcher::Type::kRecursive
                                   : base::FilePathWatcher::Type::kNonRecursive,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Note: `report_modified_path` is also present on Android
     // and Fuchsia. Update this switch if support for watching
     // the local file system is added on those platforms.
