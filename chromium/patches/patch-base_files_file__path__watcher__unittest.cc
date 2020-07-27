$NetBSD$

--- base/files/file_path_watcher_unittest.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ base/files/file_path_watcher_unittest.cc
@@ -798,7 +798,7 @@ enum Permission {
   Execute
 };
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 bool ChangeFilePermissions(const FilePath& path, Permission perm, bool allow) {
   struct stat stat_buf;
 
@@ -829,7 +829,7 @@ bool ChangeFilePermissions(const FilePat
 }
 #endif  // defined(OS_MACOSX)
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // Linux implementation of FilePathWatcher doesn't catch attribute changes.
 // http://crbug.com/78043
 // Windows implementation of FilePathWatcher catches attribute changes that
