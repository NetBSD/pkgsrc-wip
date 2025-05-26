$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/google/seven_zip_reader_unittest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/google/seven_zip_reader_unittest.cc
@@ -47,6 +47,7 @@
 #include "base/files/file_util.h"
 #include "base/logging.h"
 #include "base/path_service.h"
+#include "build/build_config.h"
 #include "testing/gmock/include/gmock/gmock.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
@@ -356,8 +357,15 @@ class SevenZipReaderFakeCrcTableTest : p
   std::array<uint32_t, 2048> crc_table_;
 };
 
+// TODO(crbug.com/388538957): Make this work on ARM64, which uses a different
+// number of tables and the crc32b instruction.
+#if defined(ARCH_CPU_ARM64)
+#define MAYBE_EmptyCrcWithFakeTable DISABLED_EmptyCrcWithFakeTable
+#else
+#define MAYBE_EmptyCrcWithFakeTable EmptyCrcWithFakeTable
+#endif
 // This is useful functionality for the fuzzer, so we test it here.
-TEST_F(SevenZipReaderFakeCrcTableTest, EmptyCrcWithFakeTable) {
+TEST_F(SevenZipReaderFakeCrcTableTest, MAYBE_EmptyCrcWithFakeTable) {
   base::File file = OpenTestFile(FILE_PATH_LITERAL("fake_crc_table.7z"));
   ASSERT_TRUE(file.IsValid());
 
