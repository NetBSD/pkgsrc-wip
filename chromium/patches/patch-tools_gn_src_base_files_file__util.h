$NetBSD$

https://gn-review.googlesource.com/c/gn/+/9700

--- tools/gn/src/base/files/file_util.h.orig	2020-07-15 19:07:32.000000000 +0000
+++ tools/gn/src/base/files/file_util.h
@@ -325,7 +325,7 @@ bool VerifyPathControlledByAdmin(const b
 // the directory |path|, in the number of FilePath::CharType, or -1 on failure.
 int GetMaximumPathComponentLength(const base::FilePath& path);
 
-#if defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 // Broad categories of file systems as returned by statfs() on Linux.
 enum FileSystemType {
   FILE_SYSTEM_UNKNOWN,   // statfs failed.
