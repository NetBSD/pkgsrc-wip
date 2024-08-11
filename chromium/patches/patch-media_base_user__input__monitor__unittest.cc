$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/base/user_input_monitor_unittest.cc.orig	2024-07-24 02:44:41.021206100 +0000
+++ media/base/user_input_monitor_unittest.cc
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_descriptor_watcher_posix.h"
 #endif
 
@@ -49,7 +49,7 @@ class UserInputMonitorTest : public test
 }  // namespace
 
 TEST_F(UserInputMonitorTest, CreatePlatformSpecific) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::test::TaskEnvironment task_environment(
       base::test::TaskEnvironment::MainThreadType::IO);
 #else
@@ -72,7 +72,7 @@ TEST_F(UserInputMonitorTest, CreatePlatf
 }
 
 TEST_F(UserInputMonitorTest, CreatePlatformSpecificWithMapping) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::test::TaskEnvironment task_environment(
       base::test::TaskEnvironment::MainThreadType::IO);
 #else
