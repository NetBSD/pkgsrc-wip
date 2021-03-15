$NetBSD$

--- src/3rdparty/chromium/base/files/file_util_unittest.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/files/file_util_unittest.cc
@@ -3501,7 +3501,7 @@ TEST_F(FileUtilTest, ReadFileToStringWit
 }
 #endif  // defined(OS_WIN)
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_FREEBSD)
 TEST_F(FileUtilTest, ReadFileToStringWithProcFileSystem) {
   FilePath file_path("/proc/cpuinfo");
   std::string data = "temp";
