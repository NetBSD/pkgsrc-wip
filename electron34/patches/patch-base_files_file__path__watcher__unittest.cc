$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/files/file_path_watcher_unittest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/files/file_path_watcher_unittest.cc
@@ -902,7 +902,7 @@ TEST_F(FilePathWatcherTest, WatchDirecto
   }
   delegate.RunUntilEventsMatch(event_expecter);
 
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && BUILDFLAG(IS_BSD)
   ASSERT_TRUE(WriteFile(file1, "content v2"));
   // Mac implementation does not detect files modified in a directory.
   // TODO(crbug.com/40263777): Expect that no events are fired on Mac.
@@ -1848,7 +1848,7 @@ namespace {
 
 enum Permission { Read, Write, Execute };
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
 bool ChangeFilePermissions(const FilePath& path, Permission perm, bool allow) {
   struct stat stat_buf;
 
@@ -1882,7 +1882,7 @@ bool ChangeFilePermissions(const FilePat
 
 }  // namespace
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) && BUILDFLAG(IS_BSD)
 // Linux implementation of FilePathWatcher doesn't catch attribute changes.
 // http://crbug.com/78043
 // Windows implementation of FilePathWatcher catches attribute changes that
