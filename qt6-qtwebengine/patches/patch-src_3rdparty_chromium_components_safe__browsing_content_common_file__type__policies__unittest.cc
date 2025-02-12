$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/safe_browsing/content/common/file_type_policies_unittest.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/components/safe_browsing/content/common/file_type_policies_unittest.cc
@@ -139,7 +139,7 @@ TEST_F(FileTypePoliciesTest, UnpackResou
   EXPECT_EQ(DownloadFileType::FULL_PING, file_type.ping_setting());
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(DownloadFileType::ALLOW_ON_USER_GESTURE,
             file_type.platform_settings(0).danger_level());
   EXPECT_EQ(DownloadFileType::DISALLOW_AUTO_OPEN,
