$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- components/os_crypt/sync/os_crypt_unittest.cc.orig	2026-11-03 08:29:05.539617109 +0000
+++ components/os_crypt/sync/os_crypt_unittest.cc
@@ -19,7 +19,7 @@
 #include "components/os_crypt/sync/os_crypt_mocker.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/sync/os_crypt_mocker_linux.h"
 #endif
 
@@ -163,7 +163,7 @@ TEST_F(OSCryptTest, Metrics) {
 #if BUILDFLAG(IS_WIN)
     histograms.ExpectTotalCount("OSCrypt.EncryptionPrefixVersion", 0);
 #else
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Linux defaults to using a `v11` key.
     const os_crypt::EncryptionPrefixVersion expected =
         os_crypt::EncryptionPrefixVersion::kVersion11;
@@ -171,7 +171,7 @@ TEST_F(OSCryptTest, Metrics) {
     // All other non-Windows platforms use a `v10` key.
     const os_crypt::EncryptionPrefixVersion expected =
         os_crypt::EncryptionPrefixVersion::kVersion10;
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     histograms.ExpectUniqueSample("OSCrypt.EncryptionPrefixVersion", expected,
                                   1u);
 #endif  // BUILDFLAG(IS_WIN)
