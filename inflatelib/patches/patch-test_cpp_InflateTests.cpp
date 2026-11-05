$NetBSD$

https://github.com/microsoft/inflatelib/pull/36

--- test/cpp/InflateTests.cpp.orig	2026-08-21 23:40:16.000000000 +0000
+++ test/cpp/InflateTests.cpp
@@ -6,7 +6,7 @@
  *    TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  *    PARTICULAR PURPOSE AND NONINFRINGEMENT.
  */
-#include <catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #define __STDC_WANT_LIB_EXT1__ 1 /* For fopen_s */
 #include <cstdio>
