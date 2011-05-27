$NetBSD: patch-testing_gtest_include_gtest_internal_gtest-port.h,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- testing/gtest/include/gtest/internal/gtest-port.h.orig	2011-05-24 08:20:42.000000000 +0000
+++ testing/gtest/include/gtest/internal/gtest-port.h
@@ -223,7 +223,8 @@
 #endif  // _WIN32_WCE
 #elif defined __APPLE__
 #define GTEST_OS_MAC 1
-#elif defined __linux__
+#elif defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__) || \
+      defined(__NetBSD__) || defined(__OpenBSD__)
 #define GTEST_OS_LINUX 1
 #elif defined __MVS__
 #define GTEST_OS_ZOS 1
@@ -499,7 +500,7 @@
 #ifndef GTEST_HAS_CLONE
 // The user didn't tell us, so we need to figure it out.
 
-#if GTEST_OS_LINUX && !defined(__ia64__)
+#if GTEST_OS_LINUX && !defined(__ia64__) && !defined(__DragonFly__)
 #define GTEST_HAS_CLONE 1
 #else
 #define GTEST_HAS_CLONE 0
