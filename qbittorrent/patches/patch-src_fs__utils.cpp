$NetBSD: patch-src_fs__utils.cpp,v 1.1 2013/12/12 15:33:22 noud4 Exp $

Use statvfs on NetBSD.

--- src/fs_utils.cpp.orig	2013-11-19 22:55:00.000000000 +0000
+++ src/fs_utils.cpp
@@ -52,6 +52,9 @@
 #if defined(Q_WS_MAC) || defined(Q_OS_FREEBSD)
 #include <sys/param.h>
 #include <sys/mount.h>
+#elif defined(Q_OS_NETBSD)
+#include <sys/param.h>
+#include <sys/statvfs.h>
 #else
 #include <sys/vfs.h>
 #endif
@@ -282,9 +285,17 @@ long long fsutils::freeDiskSpaceOnPath(Q
 
 #ifndef Q_WS_WIN
   unsigned long long available;
+#if defined(Q_OS_NETBSD)
+  struct statvfs stats;
+#else
   struct statfs stats;
+#endif
   const QString statfs_path = dir_path.path()+"/.";
+#if defined(Q_OS_NETBSD)
+  const int ret = statvfs (qPrintable(statfs_path), &stats) ;
+#else
   const int ret = statfs (qPrintable(statfs_path), &stats) ;
+#endif
   if (ret == 0) {
     available = ((unsigned long long)stats.f_bavail) *
         ((unsigned long long)stats.f_bsize) ;
