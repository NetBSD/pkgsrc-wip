$NetBSD: patch-testing_gtest_include_gtest_internal_gtest-port.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- testing/gtest/include/gtest/internal/gtest-port.h.orig	2011-04-13 08:14:19.000000000 +0000
+++ testing/gtest/include/gtest/internal/gtest-port.h
@@ -222,7 +222,8 @@
 #endif  // _WIN32_WCE
 #elif defined __APPLE__
 #define GTEST_OS_MAC 1
-#elif defined __linux__
+#elif defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__) || \
+      defined(__NetBSD__) || defined(__OpenBSD__)
 #define GTEST_OS_LINUX 1
 #elif defined __MVS__
 #define GTEST_OS_ZOS 1
