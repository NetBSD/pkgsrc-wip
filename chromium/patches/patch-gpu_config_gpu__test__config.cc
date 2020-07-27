$NetBSD$

--- gpu/config/gpu_test_config.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ gpu/config/gpu_test_config.cc
@@ -25,7 +25,7 @@ namespace {
 GPUTestConfig::OS GetCurrentOS() {
 #if defined(OS_CHROMEOS)
   return GPUTestConfig::kOsChromeOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return GPUTestConfig::kOsLinux;
 #elif defined(OS_WIN)
   int32_t major_version = 0;
