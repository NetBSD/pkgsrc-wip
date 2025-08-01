$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/files/file_util_unittest.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ base/files/file_util_unittest.cc
@@ -3920,7 +3920,7 @@ TEST_F(FileUtilTest, ReadFileToStringWit
 }
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 TEST_F(FileUtilTest, ReadFileToStringWithProcFileSystem) {
   FilePath file_path("/proc/cpuinfo");
   std::string data = "temp";
@@ -4505,6 +4505,19 @@ TEST_F(FileUtilTest, CreateDirectoryOnly
 
 #endif  // BUILDFLAG(IS_ANDROID)
 
+#if BUILDFLAG(IS_OPENBSD)
+TEST_F(FileUtilTest, CreateDirectoryInUnveiledPath) {
+  FilePath dir = PathService::CheckedGet(DIR_GEN_TEST_DATA_ROOT);
+  dir = dir.Append(FILE_PATH_LITERAL("base"));
+  dir = dir.Append(FILE_PATH_LITERAL("test"));
+  dir = dir.Append(FILE_PATH_LITERAL("unveil"));
+  unveil(dir.value().c_str(), "rwc");
+  EXPECT_TRUE(CreateDirectory(dir));
+  dir = dir.Append(FILE_PATH_LITERAL("test"));
+  EXPECT_FALSE(CreateDirectory(dir));
+}
+#endif
+
 #if BUILDFLAG(IS_WIN) && BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
     defined(ARCH_CPU_32_BITS)
 // TODO(crbug.com/327582285): Re-enable these tests. They may be failing due to
@@ -4671,7 +4684,7 @@ TEST(FileUtilMultiThreadedTest, MultiThr
                 NULL);
 #else
     size_t bytes_written =
-        ::write(::fileno(output_file.get()), content.c_str(), content.length());
+        ::write(fileno(output_file.get()), content.c_str(), content.length());
 #endif
     EXPECT_EQ(content.length(), bytes_written);
     ::fflush(output_file.get());
