$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/test/test_file_util_linux.cc.orig	2024-09-24 20:49:13.905582700 +0000
+++ base/test/test_file_util_linux.cc
@@ -54,8 +54,10 @@ bool EvictFileFromSystemCache(const File
     return false;
   if (fdatasync(fd.get()) != 0)
     return false;
+#if !BUILDFLAG(IS_BSD)
   if (posix_fadvise(fd.get(), 0, 0, POSIX_FADV_DONTNEED) != 0)
     return false;
+#endif
   return true;
 }
 
