$NetBSD$

Add NetBSD support.

--- testsuite/TestSuiteUtils.cpp.orig	2025-03-30 00:13:38.265068497 +0000
+++ testsuite/TestSuiteUtils.cpp
@@ -34,7 +34,7 @@
 #include <cstdio>
 #include <cstring>
 
-#if defined (_POSIX_C_SOURCE) || defined (_POSIX_SOURCE) || defined(__APPLE__) || defined(__FreeBSD__)
+#if defined (_POSIX_C_SOURCE) || defined (_POSIX_SOURCE) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #define USE_POSIX
 #elif defined(_WIN32)
 #define USE_WIN32
