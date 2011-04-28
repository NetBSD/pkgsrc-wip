$NetBSD: patch-base_dir__reader__posix__unittest.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/dir_reader_posix_unittest.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/dir_reader_posix_unittest.cc
@@ -28,7 +28,11 @@ TEST(DirReaderPosixUnittest, Read) {
   const char* dir = mkdtemp(kDirTemplate);
   CHECK(dir);
 
+#if defined(OS_NETBSD)
+  const int prev_wd = open(".", O_RDONLY);
+#else
   const int prev_wd = open(".", O_RDONLY | O_DIRECTORY);
+#endif
   CHECK_GE(prev_wd, 0);
 
   PCHECK(chdir(dir) == 0);
