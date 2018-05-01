$NetBSD$

From DragonFly dports devel/llvm50.

D31831: posix_fallocate isn't support on all filesystems

https://reviews.llvm.org/D31831

Check the return from posix_fallocate and if the filesystem doesn't support it fall back to ftruncate.

Apparently for FreeBSD some recent version posix_fallocate does not work on zfs.

--- lib/Support/Unix/Path.inc.orig	2017-06-29 13:15:31.000000000 +0000
+++ lib/Support/Unix/Path.inc
@@ -68,13 +68,13 @@
 
 #include <sys/types.h>
 #if !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) &&   \
-    !defined(__linux__)
+    !defined(__linux__) && !defined(__DragonFly__)
 #include <sys/statvfs.h>
 #define STATVFS statvfs
 #define FSTATVFS fstatvfs
 #define STATVFS_F_FRSIZE(vfs) vfs.f_frsize
 #else
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/mount.h>
 #include <sys/param.h>
 #elif defined(__linux__)
@@ -427,7 +427,7 @@ std::error_code resize_file(int FD, uint
   // If we have posix_fallocate use it. Unlike ftruncate it always allocates
   // space, so we get an error if the disk is full.
   if (int Err = ::posix_fallocate(FD, 0, Size)) {
-    if (Err != EOPNOTSUPP)
+    if (Err != EINVAL && Err != EOPNOTSUPP)
       return std::error_code(Err, std::generic_category());
   }
 #endif
