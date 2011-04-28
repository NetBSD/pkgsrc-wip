$NetBSD: patch-base_file__util__posix.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/file_util_posix.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/file_util_posix.cc
@@ -59,7 +59,7 @@ bool RealPath(const FilePath& path, File
 
 }  // namespace
 
-#if defined(OS_OPENBSD) || defined(OS_FREEBSD) || \
+#if defined(OS_BSD) || \
     (defined(OS_MACOSX) && \
      MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_5)
 typedef struct stat stat_wrapper_t;
@@ -98,8 +98,8 @@ int CountFilesCreatedAfter(const FilePat
 
   DIR* dir = opendir(path.value().c_str());
   if (dir) {
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_FREEBSD) && \
-    !defined(OS_OPENBSD) && !defined(OS_SOLARIS)
+#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_BSD) && \
+    !defined(OS_SOLARIS)
   #error Port warning: depending on the definition of struct dirent, \
          additional space for pathname may be needed
 #endif
@@ -709,8 +709,8 @@ bool FileEnumerator::ReadDirectory(std::
   if (!dir)
     return false;
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_FREEBSD) && \
-    !defined(OS_OPENBSD) && !defined(OS_SOLARIS)
+#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_BSD) && \
+    !defined(OS_SOLARIS)
   #error Port warning: depending on the definition of struct dirent, \
          additional space for pathname may be needed
 #endif
@@ -815,7 +815,11 @@ bool GetTempDir(FilePath* path) {
 }
 
 bool GetShmemTempDir(FilePath* path) {
+#if defined(OS_LINUX)
   *path = FilePath("/dev/shm");
+#else
+  *path = FilePath("/tmp");
+#endif
   return true;
 }
 
