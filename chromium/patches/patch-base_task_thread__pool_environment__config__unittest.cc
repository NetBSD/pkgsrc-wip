$NetBSD$

--- base/task/thread_pool/environment_config_unittest.cc.orig	2020-07-08 21:40:31.000000000 +0000
+++ base/task/thread_pool/environment_config_unittest.cc
@@ -15,7 +15,7 @@ TEST(ThreadPoolEnvironmentConfig, CanUse
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_IOS)
   EXPECT_TRUE(CanUseBackgroundPriorityForWorkerThread());
 #elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    defined(OS_CHROMEOS) || defined(OS_NACL)
+    defined(OS_CHROMEOS) || defined(OS_NACL) || defined(OS_BSD)
   EXPECT_FALSE(CanUseBackgroundPriorityForWorkerThread());
 #else
 #error Platform doesn't match any block
