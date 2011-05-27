$NetBSD: patch-base_test_test__file__util__linux.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- base/test/test_file_util_linux.cc.orig	2011-05-24 08:01:33.000000000 +0000
+++ base/test/test_file_util_linux.cc
@@ -16,10 +16,15 @@ bool EvictFileFromSystemCache(const File
   int fd = open(file.value().c_str(), O_RDONLY);
   if (fd < 0)
     return false;
+#if defined(OS_OPENBSD) || defined(OS_DRAGONFLY)
+  if (fsync(fd) != 0)
+    return false;
+#else
   if (fdatasync(fd) != 0)
     return false;
   if (posix_fadvise(fd, 0, 0, POSIX_FADV_DONTNEED) != 0)
     return false;
+#endif
   close(fd);
   return true;
 }
