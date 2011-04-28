$NetBSD: patch-base_test_test__file__util__linux.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/test/test_file_util_linux.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/test/test_file_util_linux.cc
@@ -16,10 +16,15 @@ bool EvictFileFromSystemCache(const File
   int fd = open(file.value().c_str(), O_RDONLY);
   if (fd < 0)
     return false;
+#if defined(OS_FREEBSD) || defined(OS_OPENBSD)
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
